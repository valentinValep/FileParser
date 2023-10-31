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
		~Object();
		Object	&operator=(const Object &src);

		// Getters & Setters
		const std::string				&getName() const;
		void							setName(const std::string &name);
		const std::vector<std::string>	&getAttributes() const;
		void							setAttributes(const std::vector<std::string> &attributes);

		// Methods
		virtual void				print(int depth) const;
	};
}
