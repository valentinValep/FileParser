#pragma once

#include <string>
#include <vector>

namespace fp
{
	class Object
	{
	private:
		std::string						_name;
		std::vector<std::string>		_attributes;
	public:
		// Constructors & Destructor
		Object();
		Object(const Object &src);
		Object(const std::string &name);
		Object	&operator=(const Object &src);
		virtual ~Object();

		// Operators
		virtual bool	operator==(const Object &src) const;

		// Getters & Setters
		const std::string				&getName() const;
		void							setName(const std::string &name);
		const std::vector<std::string>	&getAttributes() const;
		void							setAttributes(const std::vector<std::string> &attributes);
		void							addAttribute(const std::string &attribute);

		// Methods
		virtual void				print(int depth) const;
		virtual std::string			getType() const = 0;
	};
}
