#include "Token.hpp"
#include <string>

namespace fp
{
	Token::Token(): str(""), _line(0)
	{}

	Token::Token(const Token &src): str(src.str), _line(src._line)
	{}

	Token::Token(const std::string &str, int line): str(str), _line(line)
	{}

	Token::~Token()
	{}

	Token &Token::operator=(const Token &src)
	{
		if (this == &src)
			return (*this);
		this->str = src.str;
		this->_line = src._line;
		return (*this);
	}

	const std::string &Token::getStr() const
	{
		return (this->str);
	}

	int Token::getLine() const
	{
		return (this->_line);
	}
}
