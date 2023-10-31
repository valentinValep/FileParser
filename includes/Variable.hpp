#pragma once

#include "Object.hpp"
#include <string>

namespace fp
{
	class Variable: public Object
	{
	private:
		std::string		value;
	public:
		// Constructors & Destructor
		Variable();
		Variable(const Variable &src);
		Variable(const std::string &name);
		~Variable();
		Variable	&operator=(const Variable &src);

		// Getters & Setters
		const std::string	&getValue() const;
		void				setValue(const std::string &value);

		// Methods
		virtual void				print(int depth) const;
	};
}
