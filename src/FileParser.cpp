#include "FileParser.hpp"
#include "Token.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

namespace fp
{
	FileParser::FileParser():
		_fileName(""),
		_white_spaces(DEFAULT_WHITE_SPACES),
		_line_separators(DEFAULT_LINE_SEPARATOR),
		_bloc_open_separators(DEFAULT_BLOC_OPEN),
		_bloc_close_separators(DEFAULT_BLOC_CLOSE),
		_assignement(DEFAULT_ASSIGNEMENT)
	{}

	FileParser::FileParser(const FileParser &src):
		_fileName(src._fileName),
		_white_spaces(src._white_spaces),
		_line_separators(src._line_separators),
		_bloc_open_separators(src._bloc_open_separators),
		_bloc_close_separators(src._bloc_close_separators),
		_assignement(src._assignement)
	{}

	FileParser::FileParser(const std::string &fileName):
		_fileName(fileName),
		_white_spaces(DEFAULT_WHITE_SPACES),
		_line_separators(DEFAULT_LINE_SEPARATOR),
		_bloc_open_separators(DEFAULT_BLOC_OPEN),
		_bloc_close_separators(DEFAULT_BLOC_CLOSE),
		_assignement(DEFAULT_ASSIGNEMENT)
	{}

	FileParser::~FileParser()
	{}

	FileParser	&FileParser::operator=(const FileParser &src)
	{
		if (this == &src)
			return (*this);
		this->_fileName = src._fileName;
		this->_white_spaces = src._white_spaces;
		this->_line_separators = src._line_separators;
		this->_bloc_open_separators = src._bloc_open_separators;
		this->_bloc_close_separators = src._bloc_close_separators;
		this->_assignement = src._assignement;
		return (*this);
	}

	const std::string &FileParser::getFileName() const
	{
		return (this->_fileName);
	}

	void	FileParser::setFileName(const std::string &fileName)
	{
		this->_fileName = fileName;
	}

	const std::string &FileParser::getWhiteSpaces() const
	{
		return (this->_white_spaces);
	}

	void FileParser::setWhiteSpaces(const std::string &white_spaces)
	{
		this->_white_spaces = white_spaces;
	}

	void FileParser::setLineSeparators(const std::string &line_separators)
	{
		this->_line_separators = line_separators;
	}

	const std::string &FileParser::getBlocOpenSeparators() const
	{
		return (this->_bloc_open_separators);
	}

	const std::string &FileParser::getBlocCloseSeparators() const
	{
		return (this->_bloc_close_separators);
	}

	void FileParser::setBlocCloseSeparators(const std::string &bloc_close_separators)
	{
		this->_bloc_close_separators = bloc_close_separators;
	}

	void FileParser::setAssignement(const std::string &assignement)
	{
		this->_assignement = assignement;
	}

	const std::string &FileParser::getAssignement() const
	{
		return (this->_assignement);
	}

	void FileParser::setBlocOpenSeparators(const std::string &bloc_open_separators)
	{
		this->_bloc_open_separators = bloc_open_separators;
	}

	const std::string &FileParser::getLineSeparators() const
	{
		return (this->_line_separators);
	}

	FileParser::FileParserException::FileParserException(const std::string &msg): _msg(msg)
	{}

	FileParser::FileParserException::~FileParserException() throw()
	{}

	const char *FileParser::FileParserException::what() const throw()
	{
		return (this->_msg.c_str());
	}

	std::string	FileParser::_openFile()
	{
		std::stringstream buffer;
		std::ifstream		ifs;

		ifs.open(this->_fileName.c_str());
		if (!ifs.is_open())
			throw FileParserException("Cannot open file");

		buffer << ifs.rdbuf();
		ifs.close();
		return (buffer.str());
	}

	std::vector<Token>	FileParser::_tokenize(const std::string &str)
	{
		std::vector<Token>	tokens;
		std::string					token;
		std::string					separators;
		int							row;

		row = 1;
		separators = this->_line_separators + this->_bloc_open_separators + this->_bloc_close_separators + this->_white_spaces + this->_assignement;
		for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		{
			if (*it == '\n')
				row++;
			if (separators.find(*it) == std::string::npos)
				token += *it;
			else
			{
				if (!token.empty())
				{
					tokens.push_back(Token(token, row));
					token.clear();
				}
				if (this->_white_spaces.find(*it) == std::string::npos)
					tokens.push_back(Token(std::string(1, *it), row));
			}
		}
		return (tokens);
	}

	Module *FileParser::parse()
	{
		std::string			fileContent = this->_openFile();
		std::vector<Token>	tokens;
		Module				*mod = new Module(this);

		//std::cout << "\033[1m" << this->_fileName << "\033[0m:\nFile content: " << fileContent << std::endl;

		tokens = this->_tokenize(fileContent);

		//std::cout << "Tokens: ";
		//for (std::vector<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
		//	std::cout << "<" << *it << "> ";
		//std::cout << std::endl;

		mod->build_objects(tokens.begin(), tokens.end());

		return mod;
	}

	bool FileParser::isLineSeparator(const std::string &str)
	{
		return (this->_line_separators.find(str) != std::string::npos);
	}

	bool FileParser::isBlocOpenSeparator(const std::string &str)
	{
		return (this->_bloc_open_separators.find(str) != std::string::npos);
	}

	bool FileParser::isBlocCloseSeparator(const std::string &str)
	{
		return (this->_bloc_close_separators.find(str) != std::string::npos);
	}

	bool FileParser::isAssignement(const std::string &str)
	{
		return (this->_assignement.find(str) != std::string::npos);
	}

	FileParser::FileParserSyntaxException::FileParserSyntaxException(const std::string &msg, int line)
	{
		std::stringstream ss;

		ss << "Syntax error at line " << line << ": " << msg;
		this->_msg = ss.str();
	}

	FileParser::FileParserSyntaxException::~FileParserSyntaxException() throw()
	{}

	const char *FileParser::FileParserSyntaxException::what() const throw()
	{
		return (this->_msg.c_str());
	}
}
