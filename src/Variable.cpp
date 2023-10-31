#include "Variable.hpp"
#include <iostream>

namespace fp
{
	Variable::Variable(): Object()
	{}

	Variable::Variable(const Variable &src): Object(src)
	{}

	Variable::Variable(const std::string &name): Object(name)
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

	const std::string &Variable::getValue() const
	{
		return (this->value);
	}

	void Variable::setValue(const std::string &value)
	{
		this->value = value;
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
}
