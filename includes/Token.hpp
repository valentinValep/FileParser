#pragma once

#include <string>
#include <iostream>

namespace fp
{
	class Token
	{
	private:
		std::string		str;
		int				_line;

		Token();
	public:
		// Constructors & Destructor
		Token(const Token &src);
		Token(const std::string &str, int line);
		~Token();
		Token	&operator=(const Token &src);

		// Getters
		const std::string	&getStr() const;
		int					getLine() const;
	};
}
