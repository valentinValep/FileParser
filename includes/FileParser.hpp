#pragma once

#include "Module.hpp"
#include "Token.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <set>

#define DEFAULT_WHITE_SPACES	" \t\n\r\v\f"
#define DEFAULT_LINE_SEPARATOR	";,"
#define DEFAULT_BLOC_OPEN		"{["
#define DEFAULT_BLOC_CLOSE		"}]"
#define DEFAULT_ASSIGNEMENT		"=:"


namespace fp
{
	class Module;

	enum e_Presence
	{
		FORBIDDEN,
		OPTIONAL,
		REQUIRED
	};

	class FileParser
	{
	private:
		// Attributes
		std::set<std::string>	_whitelist;
		std::string					_fileName;
		std::string					_white_spaces;
		std::string					_line_separators;
		std::string					_bloc_open_separators;
		std::string					_bloc_close_separators;
		std::string					_assignement;
		e_Presence					_variable_value_presence;
		e_Presence					_module_name_presence;

		// Methods
		std::string					_openFile();
		std::vector<Token>			_tokenize(const std::string &str);
	public:
		// Constructors & Destructor
		FileParser();
		FileParser(const std::string &fileName);
		~FileParser();
		FileParser(const FileParser &src);
		FileParser	&operator=(const FileParser &src);

		// Getters & Setters
		const std::string	&getFileName() const;
		void				setFileName(const std::string &fileName);
		const std::string	&getWhiteSpaces() const;
		void				setWhiteSpaces(const std::string &white_spaces);
		const std::string	&getLineSeparators() const;
		void				setLineSeparators(const std::string &line_separator);
		const std::string	&getBlocOpenSeparators() const;
		void				setBlocOpenSeparators(const std::string &bloc_open_separators);
		const std::string	&getBlocCloseSeparators() const;
		void				setBlocCloseSeparators(const std::string &bloc_close_separators);
		const std::string	&getAssignement() const;
		void				setAssignement(const std::string &assignement);
		e_Presence			getVariableValuePresence() const;
		e_Presence			getModuleNamePresence() const;

		// Methods

		/// @brief Parse the file and return a Module object
		/// @return Module* A pointer to the Module object
		/// @throw FileParserException: if the file cannot be opened
		/// @throw FileParserSyntaxException: if the syntax is incorrect
		Module				*parse();

		bool				isLineSeparator(const std::string &str);
		bool				isBlocOpenSeparator(const std::string &str);
		bool				isBlocCloseSeparator(const std::string &str);
		bool				isAssignement(const std::string &str);

		FileParser			*banVariableValue();
		FileParser			*allowVariableValue();
		FileParser			*forceVariableValue();
		FileParser			*banModuleName();
		FileParser			*allowModuleName();
		FileParser			*forceModuleName();
		void				addToWhitelist(const std::string &str);
		bool				isWhitelisted(const std::string &str);

		// Exceptions
		class FileParserException: public std::exception
		{
		private:
			std::string		_msg;
		public:
			FileParserException(const std::string &msg);
			virtual ~FileParserException() throw();
			virtual const char	*what() const throw();
		};

		class FileParserSyntaxException: public std::exception
		{
		private:
			std::string		_msg;
		public:
			FileParserSyntaxException(const std::string &msg, std::string file, int line);
			virtual ~FileParserSyntaxException() throw();
			virtual const char	*what() const throw();
		};
	};
}
