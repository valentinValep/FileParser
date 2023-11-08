#pragma once

#include "Object.hpp"
#include "FileParser.hpp"
#include "Token.hpp"
#include "Variable.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace fp
{
	class FileParser;

	enum e_TokenType
	{
		WORD,
		LINE_SEPARATOR,
		OPEN_BRACE,
		CLOSE_BRACE,
		ASSIGNEMENT
	};

	enum e_ParseState
	{
		DEFAULT,
		VARIABLE,
		NEED_NEW_LINE,
		CAN_NEW_LINE,
		MODULE
	};

	class Module: public Object
	{
	private:
		FileParser				*_file_parser;
		std::vector<Object*>	_objects;
		std::string				_path;

		Module();
		e_TokenType	getTokenType(const std::string &token);
		void		createNewVariable(const std::string &name, const std::string &value, const std::vector<std::string> &attributes, int line);
		void		createNewModule(const std::string &name, const std::vector<std::string> &attributes, std::vector<fp::Token>::iterator module_begin, std::vector<fp::Token>::iterator it);
	public:
		// Constructors & Destructor
		Module(const Module &src);
		Module(FileParser *file_parser, const std::string &path);
		Module(const std::string &name, FileParser *file_parser, const std::string &path);
		Module	&operator=(const Module &src);
		virtual ~Module();

		// Operators
		virtual bool	operator==(const Object &src) const;

		// Getters & Setters
		const std::vector<Object*>	&getObjects() const;
		void						setObjects(const std::vector<Object*> &objects);
		void						addObject(Object *object);

		// Methods
		void						build_objects(std::vector<Token>::iterator begin, std::vector<Token>::iterator end);
		virtual std::string			getType() const;
		bool						contains(const std::string &path) const;
		bool						hardContains(const std::string &path) const;
		virtual void				print(int depth) const;
		void						print() const;
		Object						*getObject(const std::string &name) const;
		/// \brief Get a variable from the module
		/// \param name The name of the variable
		/// \return The variable if found, nullptr otherwise
		Variable					*getVariable(const std::string &name) const;
		Module						*getModule(const std::string &name) const;
	};
}

