#include "Module.hpp"
#include "Variable.hpp"
#include <string>
#include <vector>

namespace fp
{
	Module::Module(): Object(), _file_parser(NULL), _objects()
	{}

	Module::Module(const Module &src): Object(src), _file_parser(src._file_parser), _objects(src._objects), _path(src._path)
	{}

	Module::Module(FileParser *file_parser, const std::string &path): Object(), _file_parser(file_parser), _objects(), _path(path)
	{}

	Module::Module(const std::string &name, FileParser *file_parser, const std::string &path): Object(name), _file_parser(file_parser), _objects(), _path(path)
	{}

	Module::~Module()
	{
		for (std::vector<Object *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it)
			delete *it;
	}

	bool Module::operator==(const Object &src) const
	{
		if (this == &src)
			return (true);
		if (this->getType() != src.getType())
			return (false);
		const Module *mod = dynamic_cast<const Module *>(&src);
		if (this->_objects.size() != mod->_objects.size())
			return (false);
		for (size_t i = 0; i < this->_objects.size(); i++)
		{
			if (!(*this->_objects[i] == *mod->_objects[i]))
				return (false);
		}
		return (Object::operator==(src) && this->_path == mod->_path);
	}

	Module	&Module::operator=(const Module &src)
	{
		if (this == &src)
			return (*this);
		Object::operator=(src);
		this->_objects = src._objects;
		this->_file_parser = src._file_parser;
		return (*this);
	}

	const std::vector<Object *> &Module::getObjects() const
	{
		return (this->_objects);
	}

	void Module::setObjects(const std::vector<Object *> &objects)
	{
		this->_objects = objects;
	}

	void Module::addObject(Object *object)
	{
		this->_objects.push_back(object);
	}

	e_TokenType Module::getTokenType(const std::string &token)
	{
		if (this->_file_parser->isBlocCloseSeparator(token))
			return (CLOSE_BRACE);
		if (this->_file_parser->isBlocOpenSeparator(token))
			return (OPEN_BRACE);
		if (this->_file_parser->isLineSeparator(token))
			return (LINE_SEPARATOR);
		if (this->_file_parser->isAssignement(token))
			return (ASSIGNEMENT);
		return (WORD);
	}

	void	Module::createNewVariable(const std::string &name, const std::string &value, const std::vector<std::string> &attributes, int line)
	{
		if (!this->_file_parser->isWhitelisted(this->_path + this->getName() + "/" + name))
			throw FileParser::FileParserSyntaxException("Unexpected name \"" + this->_path + this->getName() + "/" + name +"\"", this->_file_parser->getFileName(), line);
		Variable *var = new Variable(name);
		_objects.push_back(var);
		if (!value.empty())
			var->setValue(value);
		var->setAttributes(attributes);
	}

	void	Module::createNewModule(const std::string &name, const std::vector<std::string> &attributes, std::vector<fp::Token>::iterator module_begin, std::vector<fp::Token>::iterator it)
	{
		if (name.empty() && this->_file_parser->getModuleNamePresence() == REQUIRED)
			throw FileParser::FileParserSyntaxException("Modules need name", this->_file_parser->getFileName(), (*it).getLine());
		if (!name.empty() && this->_file_parser->getModuleNamePresence() == FORBIDDEN)
			throw FileParser::FileParserSyntaxException("Modules can't have name", this->_file_parser->getFileName(), (*it).getLine());
		if (!this->_file_parser->isWhitelisted(this->_path + this->getName() + "/" + name + "/"))
			throw FileParser::FileParserSyntaxException("Unexpected name \"" + this->_path + this->getName() + "/" + name + "/" +"\"", this->_file_parser->getFileName(), (*it).getLine());
		Module *mod = new Module(name, this->_file_parser, this->_path + this->getName() + "/");
		_objects.push_back(mod);
		mod->setAttributes(attributes);
		mod->build_objects(module_begin, it);
	}

	void	Module::build_objects(std::vector<Token>::iterator begin, std::vector<Token>::iterator end)
	{
		std::string						name;
		std::vector<std::string>		attributes;
		e_TokenType						token_type;
		e_ParseState					parse_state = DEFAULT;
		int								module_brace_count = 0;
		std::vector<Token>::iterator	module_begin;

		if (!this->_file_parser)
			throw FileParser::FileParserException("internal error: FileParser can't be NULL to build Module objects");
		// Parse tokens
		for (std::vector<Token>::iterator it = begin; it != end; ++it)
		{
			token_type = this->getTokenType((*it).getStr());
			if (parse_state == CAN_NEW_LINE)
			{
				parse_state = DEFAULT;
				if (token_type == LINE_SEPARATOR)
					continue;
				else if (token_type != WORD)
					throw FileParser::FileParserSyntaxException("Unexpected token", this->_file_parser->getFileName(), (*it).getLine());
			}
			if (parse_state == MODULE)
			{
				if (token_type == OPEN_BRACE)
					++module_brace_count;
				else if (token_type == CLOSE_BRACE)
				{
					if (module_brace_count == 0)
					{
						createNewModule(name, attributes, module_begin, it);
						name.clear();
						attributes.clear();
						parse_state = CAN_NEW_LINE;
						continue;
					}
					--module_brace_count;
				}
			}
			else if (parse_state == VARIABLE && token_type != OPEN_BRACE)
			{
				if (this->_file_parser->getVariableValuePresence() == FORBIDDEN)
					throw FileParser::FileParserSyntaxException("Variables can't have value", this->_file_parser->getFileName(), (*it).getLine());
				if (token_type != WORD)
					throw FileParser::FileParserSyntaxException("Assignement must be followed by a value", this->_file_parser->getFileName(), (*it).getLine());
				if (name.empty())
					throw FileParser::FileParserSyntaxException("Variable name can't be empty", this->_file_parser->getFileName(), (*it).getLine());
				this->createNewVariable(name, (*it).getStr(), attributes, (*it).getLine());
				name.clear();
				attributes.clear();
				parse_state = NEED_NEW_LINE;
			}
			else if (parse_state == NEED_NEW_LINE)
			{
				if (token_type != LINE_SEPARATOR)
					throw FileParser::FileParserSyntaxException("Variable must be followed by a line separator", this->_file_parser->getFileName(), (*it).getLine());
				parse_state = DEFAULT;
			}
			else if (token_type == WORD)
			{
				if (name.empty())
					name = (*it).getStr();
				else
					attributes.push_back((*it).getStr());
			}
			else if (token_type == LINE_SEPARATOR)
			{
				if (name.empty())
					throw FileParser::FileParserSyntaxException("Variable name can't be empty", this->_file_parser->getFileName(), (*it).getLine());
				if (this->_file_parser->getVariableValuePresence() == REQUIRED)
					throw FileParser::FileParserSyntaxException("Variables must have a value", this->_file_parser->getFileName(), (*it).getLine());
				this->createNewVariable(name, "", attributes, (*it).getLine());
				name.clear();
				attributes.clear();
			}
			else if (token_type == ASSIGNEMENT)
			{
				parse_state = VARIABLE;
			}
			else if (token_type == OPEN_BRACE)
			{
				parse_state = MODULE;
				module_begin = it + 1;
			}
			else if (token_type == CLOSE_BRACE)
			{
				throw FileParser::FileParserSyntaxException("Unexpected close brace", this->_file_parser->getFileName(), (*it).getLine());
			}
		}

		// End of file
		if (parse_state != DEFAULT && parse_state != CAN_NEW_LINE && parse_state != NEED_NEW_LINE)
			throw FileParser::FileParserSyntaxException("Unexpected end of module", this->_file_parser->getFileName(), (*(end - 1)).getLine());
		//std::cout << "DEBUG: name: \"" << name << "\"" << std::endl;
		//std::cout << "DEBUG: " << (!name.empty()) << std::endl;
		if (!name.empty())
		{
			if (this->_file_parser->getVariableValuePresence() == REQUIRED)
				throw FileParser::FileParserSyntaxException("Variables must have a value", this->_file_parser->getFileName(), (*(end - 1)).getLine());
			this->createNewVariable(name, "", attributes, (*(end - 1)).getLine());
		}
	}

	std::string Module::getType() const
	{
		return ("Module");
	}

	bool Module::contains(const std::string &path) const
	{
		std::string	child = path.substr(1);
		std::string	module_name = child.substr(0, child.find('/'));

		for (std::vector<Object*>::const_iterator it = this->_objects.begin(); it != this->_objects.end(); ++it)
		{
			if ((*it)->getName() == module_name)
			{
				if (child.find('/') == std::string::npos)
					return (true);
				else
					return (dynamic_cast<Module*>(*it)->contains(child.substr(child.find('/'))));
			}
		}
		return false;
	}

	bool Module::hardContains(const std::string &path) const
	{
		std::string	child = path.substr(1);
		std::string	module_name = child.substr(0, child.find('/'));
		bool		found = false;

		for (std::vector<Object*>::const_iterator it = this->_objects.begin(); it != this->_objects.end(); ++it)
		{
			if ((*it)->getName() == module_name)
			{
				if (child.find('/') == std::string::npos)
					return (true);
				else if (!dynamic_cast<Module*>(*it)->hardContains(child.substr(child.find('/'))))
					return (false);
				else
					found = true;
			}
		}
		return found;
	}

	void Module::print() const
	{
		this->print(0);
	}

	Object *Module::getObject(const std::string &name) const
	{
		for (std::vector<Object*>::const_iterator it = this->_objects.begin(); it != this->_objects.end(); ++it)
		{
			if ((*it)->getName() == name)
				return (*it);
		}
		return (NULL);
	}

	Module *Module::getModule(const std::string &name) const
	{
		Object *obj = this->getObject(name);
		if (obj && obj->getType() == "Module")
			return (dynamic_cast<Module*>(obj));
		return (NULL);
	}

	int Module::getNbObjects(const std::string &name) const
	{ // @TODO: test
		int	count = 0;

		for (std::vector<Object*>::const_iterator it = this->_objects.begin(); it != this->_objects.end(); ++it)
		{
			if ((*it)->getName() == name)
				++count;
		}
		return (count);
	}

	int Module::getNbObjects() const
	{ // @TODO: test
		return this->_objects.size();
	}

	Variable *Module::getVariable(const std::string &name) const
	{
		Object *obj = this->getObject(name);
		if (obj && obj->getType() == "Variable")
			return (dynamic_cast<Variable*>(obj));
		return (NULL);
	}

	void Module::print(int depth) const
	{
		for (int i = 0; i < depth; i++)
			std::cout << "  ";
		std::cout << this->getName() << "(" + this->_path + ") {" << std::endl;
		for (std::vector<Object*>::const_iterator it = this->_objects.begin(); it != this->_objects.end(); ++it)
		{
			for (int i = 0; i < depth; i++)
				std::cout << "  ";
			(*it)->print(depth + 1);
		}
		for (int i = 0; i < depth; i++)
			std::cout << "  ";
		std::cout << "}" << std::endl;
	}
}
