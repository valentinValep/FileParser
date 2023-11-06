#pragma once

#include "Object.hpp"
#include "FileParser.hpp"
#include "Token.hpp"
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

		Module();
		e_TokenType	getTokenType(const std::string &token);
	public:
		// Constructors & Destructor
		Module(const Module &src);
		Module(FileParser *file_parser);
		Module(const std::string &name, FileParser *file_parser);
		Module	&operator=(const Module &src);
		~Module();

		// Operators
		virtual bool	operator==(const Object &src) const;

		// Getters & Setters
		const std::vector<Object*>	&getObjects() const;
		void						setObjects(const std::vector<Object*> &objects);
		void						addObject(Object *object);

		// Methods
		void						build_objects(std::vector<Token>::iterator begin, std::vector<Token>::iterator end);
		virtual std::string			getType() const;
		virtual void				print(int depth) const;
		void						print() const;
	};
}
