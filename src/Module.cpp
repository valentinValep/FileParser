#include "Module.hpp"
#include "Variable.hpp"
#include <string>
#include <vector>

namespace fp
{
	Module::Module(): Object(), _file_parser(NULL), _objects()
	{}

	Module::Module(const Module &src): Object(src), _file_parser(src._file_parser), _objects(src._objects)
	{}

	Module::Module(FileParser *file_parser): Object(), _file_parser(file_parser), _objects()
	{}

	Module::Module(const std::string &name, FileParser *file_parser): Object(name), _file_parser(file_parser), _objects()
	{}

	Module::~Module()
	{}

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

	void Module::build_objects(std::vector<Token>::iterator begin, std::vector<Token>::iterator end)
	{
		std::string					name;
		std::vector<std::string>	attributes;
		e_TokenType					token_type;
		e_ParseState				parse_state = DEFAULT;
		int							module_brace_count = 0;
		std::vector<Token>::iterator	module_begin;

		if (!this->_file_parser)
			throw FileParser::FileParserException("internal error: FileParser can't be NULL to build Module objects");
		for (std::vector<Token>::iterator it = begin; it != end; ++it)
		{
			token_type = this->getTokenType((*it).getStr());
			if (parse_state == CAN_NEW_LINE)
			{
				parse_state = DEFAULT;
				if (token_type == LINE_SEPARATOR)
					continue;
				else if (token_type != WORD)
					throw FileParser::FileParserSyntaxException("Unexpected token", (*it).getLine());
			}
			if (parse_state == MODULE)
			{
				if (token_type == OPEN_BRACE)
					++module_brace_count;
				else if (token_type == CLOSE_BRACE)
				{
					if (module_brace_count == 0)
					{
						if (name.empty())
							throw FileParser::FileParserSyntaxException("Module name can't be empty", (*it).getLine());
						Module *mod = new Module(name, this->_file_parser);
						_objects.push_back(mod);
						mod->setAttributes(attributes);
						name.clear();
						attributes.clear();
						mod->build_objects(module_begin, it);
						parse_state = CAN_NEW_LINE;
						continue;
					}
					--module_brace_count;
				}
			}
			else if (parse_state == VARIABLE)
			{
				if (token_type != WORD)
					throw FileParser::FileParserSyntaxException("Assignement must be followed by a value", (*it).getLine());
				if (name.empty())
					throw FileParser::FileParserSyntaxException("Variable name can't be empty", (*it).getLine());
				Variable *var = new Variable(name);
				_objects.push_back(var);
				var->setValue((*it).getStr());
				var->setAttributes(attributes);
				name.clear();
				attributes.clear();
				parse_state = NEED_NEW_LINE;
			}
			else if (parse_state == NEED_NEW_LINE)
			{
				if (token_type != LINE_SEPARATOR)
					throw FileParser::FileParserSyntaxException("Variable must be followed by a line separator", (*it).getLine());
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
				Variable *var = new Variable(name);
				_objects.push_back(var);
				var->setValue(attributes.back());
				attributes.pop_back();
				_objects.back()->setAttributes(attributes);
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
				throw FileParser::FileParserSyntaxException("Unexpected close brace", (*it).getLine());
			}
		}
		if (parse_state != DEFAULT && parse_state != CAN_NEW_LINE && parse_state != NEED_NEW_LINE)
			throw FileParser::FileParserException("Unexpected end of file");
		if (!name.empty())
		{
			Variable *var = new Variable(name);
			_objects.push_back(var);
			var->setValue(attributes.back());
			attributes.pop_back();
			_objects.back()->setAttributes(attributes);
		}
	}

	void Module::print() const
	{
		this->print(0);
	}

	void Module::print(int depth) const
	{
		for (int i = 0; i < depth; i++)
			std::cout << "  ";
		std::cout << this->getName()  << (this->getName().empty()? "{": " {") << std::endl;
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
