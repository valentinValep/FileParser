#include "Variable.hpp"
#include <iostream>

namespace fp
{
	Variable::Variable(): Object(), value(""), _has_value(false)
	{}

	Variable::Variable(const Variable &src): Object(src), value(src.value), _has_value(src._has_value)
	{}

	Variable::Variable(const std::string &name): Object(name), value(""), _has_value(false)
	{}

	Variable::~Variable()
	{}

	Variable	&Variable::operator=(const Variable &src)
	{
		if (this == &src)
			return (*this);
		Object::operator=(src);
		return (*this);
	}

	bool Variable::operator==(const Object &src) const
	{
		if (this == &src)
			return (true);
		if (this->getType() != src.getType())
			return (false);
		const Variable *var = dynamic_cast<const Variable *>(&src);
		return (Object::operator==(src) && this->value == var->value);
	}

	const std::string &Variable::getValue() const
	{
		return (this->value);
	}

	void Variable::setValue(const std::string &value)
	{
		if (value != "")
			this->_has_value = true;
		else
			this->_has_value = false;
		this->value = value;
	}

	bool	Variable::hasValue() const
	{
		return (this->_has_value);
	}

	void Variable::print(int depth) const
	{
		for (int i = 0; i < depth; i++)
			std::cout << "  ";
		std::cout << this->getName();
		for (std::vector<std::string>::const_iterator it = this->getAttributes().begin(); it != this->getAttributes().end(); it++)
			std::cout << " " << *it;
		std::cout << " = " << this->value << std::endl;
	}

	std::string Variable::getType() const
	{
		return ("Variable");
	}
}
