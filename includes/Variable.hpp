#pragma once

#include "Object.hpp"
#include <string>

namespace fp
{
	class Variable: public Object
	{
	private:
		std::string		value;
		bool			_has_value;
	public:
		// Constructors & Destructor
		Variable();
		Variable(const Variable &src);
		Variable(const std::string &name);
		Variable	&operator=(const Variable &src);
		virtual ~Variable();

		// Operators
		virtual bool	operator==(const Object &src) const;

		// Getters & Setters
		const std::string	&getValue() const;
		void				setValue(const std::string &value);
		bool				hasValue() const;

		// Methods
		virtual void				print(int depth) const;
		virtual std::string			getType() const;
	};
}
