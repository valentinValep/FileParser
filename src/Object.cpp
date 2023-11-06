#include "Object.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace fp
{
	Object::Object(): _name("")
	{}

	Object::Object(const Object &src): _name(src._name)
	{}

	Object::Object(const std::string &name): _name(name)
	{}

	Object::~Object()
	{}

	Object	&Object::operator=(const Object &src)
	{
		if (this == &src)
			return (*this);
		this->_name = src._name;
		return (*this);
	}

	bool Object::operator==(const Object &src) const
	{
		return (this->_name == src._name && this->_attributes == src._attributes);
	}

	const std::string &Object::getName() const
	{
		return (this->_name);
	}

	void Object::setName(const std::string &name)
	{
		this->_name = name;
	}

	void Object::setAttributes(const std::vector<std::string> &attributes)
	{
		this->_attributes = attributes;
	}

	const std::vector<std::string> &Object::getAttributes() const
	{
		return (this->_attributes);
	}

	void Object::print(int depth) const
	{
		for (int i = 0; i < depth; i++)
			std::cout << "  ";
		std::cout << this->_name;
		for (std::vector<std::string>::const_iterator it = this->_attributes.begin(); it != this->_attributes.end(); it++)
			std::cout << " " << *it;
		std::cout << std::endl;
	}
}
