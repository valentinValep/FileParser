#include "FileParser.hpp"
#include "Module.hpp"
#include "Variable.hpp"
#include <iostream>

int	equal_operator_test()
{
	fp::FileParser	fp;
	{
		fp::Module		expected("1", &fp, "");
		fp::Module		expected2("2", &fp, "");

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "/");
		fp::Module		expected2("name", &fp, "/");

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "/1");
		fp::Module		expected2("name", &fp, "/");

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		expected.addAttribute("attr");

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		expected.addAttribute("attr");
		expected2.addAttribute("attr");

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		expected.addAttribute("attr");
		expected2.addAttribute("attr");
		expected.addAttribute("attr2");

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Variable	*var = new fp::Variable("var");
		expected.addObject(var);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Variable	*var = new fp::Variable("var");
		expected.addObject(var);
		fp::Variable	*var2 = new fp::Variable("var");
		expected2.addObject(var2);

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Variable	*var = new fp::Variable("var");
		var->addAttribute("attr");
		expected.addObject(var);
		fp::Variable	*var2 = new fp::Variable("var");
		expected2.addObject(var2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Variable	*var = new fp::Variable("var");
		var->addAttribute("attr");
		expected.addObject(var);
		fp::Variable	*var2 = new fp::Variable("var");
		var2->addAttribute("attr");
		expected2.addObject(var2);

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Variable	*var = new fp::Variable("var");
		var->addAttribute("attr");
		var->setValue("value");
		expected.addObject(var);
		fp::Variable	*var2 = new fp::Variable("var");
		var2->addAttribute("attr");
		expected2.addObject(var2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Variable	*var = new fp::Variable("var");
		var->addAttribute("attr");
		var->setValue("value");
		expected.addObject(var);
		fp::Variable	*var2 = new fp::Variable("var");
		var2->addAttribute("attr");
		var2->setValue("value");
		expected2.addObject(var2);

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Variable	*var = new fp::Variable("var");
		var->addAttribute("attr1");
		var->setValue("value");
		expected.addObject(var);
		fp::Variable	*var2 = new fp::Variable("var");
		var2->addAttribute("attr");
		var2->setValue("value");
		expected2.addObject(var2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Variable	*var = new fp::Variable("var");
		var->addAttribute("attr");
		var->setValue("value1");
		expected.addObject(var);
		fp::Variable	*var2 = new fp::Variable("var");
		var2->addAttribute("attr");
		var2->setValue("value");
		expected2.addObject(var2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Variable	*var = new fp::Variable("var");
		var->addAttribute("attr");
		var->setValue("value");
		expected.addObject(var);
		fp::Variable	*var2 = new fp::Variable("var");
		var2->addAttribute("attr1");
		var2->setValue("value");
		expected2.addObject(var2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Variable	*var = new fp::Variable("var");
		var->addAttribute("attr");
		var->setValue("value");
		expected.addObject(var);
		fp::Variable	*var2 = new fp::Variable("var");
		var2->addAttribute("attr");
		var2->setValue("value1");
		expected2.addObject(var2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Module		*mod = new fp::Module("mod", &fp, "name/");
		expected.addObject(mod);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Module		*mod = new fp::Module("mod", &fp, "name/");
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod", &fp, "name/");
		expected2.addObject(mod2);

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Module		*mod = new fp::Module("mod", &fp, "name/");
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod2", &fp, "name/");
		expected2.addObject(mod2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Module		*mod = new fp::Module("mod", &fp, "name/");
		expected.addObject(mod);
		mod->addAttribute("attr");
		fp::Module		*mod2 = new fp::Module("mod", &fp, "name/");
		expected2.addObject(mod2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Module		*mod = new fp::Module("mod", &fp, "name/");
		expected.addObject(mod);
		mod->addAttribute("attr");
		fp::Module		*mod2 = new fp::Module("mod", &fp, "name/");
		expected2.addObject(mod2);
		mod2->addAttribute("attr");

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Module		*mod = new fp::Module("mod", &fp, "name/");
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod", &fp, "name/");
		expected2.addObject(mod2);
		fp::Variable	*var = new fp::Variable("var");
		mod->addObject(var);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: mod == mod2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Module		*mod = new fp::Module("mod", &fp, "name/");
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod", &fp, "name/");
		expected2.addObject(mod2);
		fp::Variable	*var = new fp::Variable("var");
		mod->addObject(var);
		fp::Variable	*var2 = new fp::Variable("var");
		mod2->addObject(var2);

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: mod != mod2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Module		*mod = new fp::Module("mod", &fp, "name/");
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod", &fp, "name/");
		expected2.addObject(mod2);
		fp::Variable	*var = new fp::Variable("var");
		mod->addObject(var);
		var->addAttribute("attr");
		fp::Variable	*var2 = new fp::Variable("var");
		mod2->addObject(var2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed mod == mod2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp, "");
		fp::Module		expected2("name", &fp, "");
		fp::Module		*mod = new fp::Module("mod", &fp, "name/");
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod", &fp, "name/");
		expected2.addObject(mod2);
		fp::Variable	*var = new fp::Variable("var");
		mod->addObject(var);
		var->addAttribute("attr");
		fp::Variable	*var2 = new fp::Variable("var");
		var2->addAttribute("attr");
		mod2->addObject(var2);

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed mod != mod2" << std::endl;
			return (1);
		}
	}
	return (0);
}

int	empty_file()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/empty_file");
	result = fp.parse();

	// Expected module

	// Checking
	std::cout << "test files/empty_file: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	no_module()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/no_module");
	result = fp.parse();

	// Expected module
	fp::Variable	*var = new fp::Variable("var");
	expected.addObject(var);

	// Checking
	std::cout << "test files/no_module: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	no_module_value()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/no_module_value");
	result = fp.parse();

	// Expected module
	fp::Variable	*var = new fp::Variable("var");
	var->setValue("1");
	expected.addObject(var);

	// Checking
	std::cout << "test files/no_module_value: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	no_module_multiple()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/no_module_multiple");
	result = fp.parse();

	// Expected module
	{
		fp::Variable	*var = new fp::Variable("var");
		expected.addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("var");
		var->setValue("1");
		expected.addObject(var);
	}

	// Checking
	std::cout << "test files/no_module_multiple: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	no_module_comma()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/no_module_comma");
	result = fp.parse();

	// Expected module
	{
		fp::Variable	*var = new fp::Variable("var");
		var->setValue("1");
		expected.addObject(var);
	}

	// Checking
	std::cout << "test files/no_module_comma: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	no_module_tests()
{
	int	ret;
	int	global_ret = 0;

	if ((ret = no_module()))
		global_ret += 1;
	if ((ret = no_module_value()))
		global_ret += 1;
	if ((ret = no_module_multiple()))
		global_ret += 1;
	if ((ret = no_module_comma()))
		global_ret += 1;
	return (global_ret);
}

int	simple_module_test()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/simple_module");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	fp::Variable	*var = new fp::Variable("var");
	var->setValue("1");
	mod->addObject(var);
	expected.addObject(mod);

	// Checking
	std::cout << "test files/simple_module: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	simple_module_comma()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/simple_module_comma");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("mod", &fp, "/");
	fp::Variable	*var = new fp::Variable("var");
	mod->addObject(var);
	expected.addObject(mod);

	// Checking
	std::cout << "test files/simple_module_comma: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	multiple_lines()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/multiple_lines");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module		*mod = new fp::Module("module", &fp, "/");
			{
				fp::Variable	*var = new fp::Variable("var");
				var->setValue("1");
				mod->addObject(var);
			}
			{
				fp::Variable	*var = new fp::Variable("var2");
				var->setValue("2");
				mod->addObject(var);
			}
			expected.addObject(mod);
		}
		{
			fp::Module		*mod = new fp::Module("module2", &fp, "/");
			{
				fp::Variable	*var = new fp::Variable("var");
				var->setValue("\"1\"");
				mod->addObject(var);
			}
			{
				fp::Variable	*var = new fp::Variable("var2");
				var->setValue("\"2\"");
				mod->addObject(var);
			}
			expected.addObject(mod);
		}
	}

	// Checking
	std::cout << "test files/multiple_lines: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	simple_compact()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/simple_compact");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module		*mod = new fp::Module("module", &fp, "/");
			{
				fp::Variable	*var = new fp::Variable("var");
				var->setValue("1");
				mod->addObject(var);
			}
			{
				fp::Variable	*var = new fp::Variable("var2");
				var->setValue("2");
				mod->addObject(var);
			}
			expected.addObject(mod);
		}
	}

	// Checking
	std::cout << "test files/simple_compact: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	global_test()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/global_test");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module		*mod = new fp::Module("module", &fp, "/");
			{
				fp::Variable	*var = new fp::Variable("\"key\"");
				var->setValue("\"value1\"");
				mod->addObject(var);
			}
			{
				fp::Variable	*var = new fp::Variable("key");
				var->setValue("\"value\"");
				mod->addObject(var);
			}
			{
				fp::Variable	*var = new fp::Variable("random");
				mod->addObject(var);
			}
			{
				fp::Variable	*var = new fp::Variable("\"random\"");
				mod->addObject(var);
			}
			{
				fp::Module		*mod2 = new fp::Module("\"module\"", &fp, "/module/");
				{
					fp::Variable	*var = new fp::Variable("\"key\"");
					var->setValue("\"value\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("module", &fp, "/module/");
				{
					fp::Variable	*var = new fp::Variable("\"key\"");
					var->setValue("\"value\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("\"module\"", &fp, "/module/");
				{
					fp::Variable	*var = new fp::Variable("\"key\"");
					var->setValue("\"value\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("module", &fp, "/module/");
				{
					fp::Variable	*var = new fp::Variable("\"key\"");
					var->setValue("\"value\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("module_name", &fp, "/module/");
				mod2->addAttribute("module_var");
				{
					fp::Variable	*var = new fp::Variable("key");
					var->setValue("value");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("\"array\"", &fp, "/module/");
				{
					fp::Variable	*var = new fp::Variable("\"item1\"");
					mod2->addObject(var);
				}
				{
					fp::Variable	*var = new fp::Variable("\"item2\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("array", &fp, "/module/");
				{
					fp::Variable	*var = new fp::Variable("\"item1\"");
					mod2->addObject(var);
				}
				{
					fp::Variable	*var = new fp::Variable("\"item2\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			expected.addObject(mod);
		}
	}

	// Checking
	std::cout << "test files/global_test: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	simple_module_no_value()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/simple_module_no_value");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module		*mod = new fp::Module("module", &fp, "/");
			{
				fp::Variable	*var = new fp::Variable("var");
				mod->addObject(var);
			}
			expected.addObject(mod);
		}
	}

	// Checking
	std::cout << "test files/simple_module_no_value: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	special_end_test()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/special_end_test");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module		*mod = new fp::Module("mod", &fp, "/");
			{
				fp::Variable	*var = new fp::Variable("var");
				mod->addObject(var);
			}
			expected.addObject(mod);
		}
		{
			fp::Module		*mod = new fp::Module("mod2", &fp, "/");
			{
				fp::Variable	*var = new fp::Variable("var");
				var->addAttribute("attr1");
				mod->addObject(var);
			}
			expected.addObject(mod);
		}
		{
			fp::Module		*mod = new fp::Module("mod3", &fp, "/");
			{
				fp::Variable	*var = new fp::Variable("var");
				var->addAttribute("attr1");
				mod->addObject(var);
			}
			{
				fp::Variable	*var = new fp::Variable("var");
				var->addAttribute("attr2");
				mod->addObject(var);
			}
			expected.addObject(mod);
		}
	}

	// Checking
	std::cout << "test files/special_end_test: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	test_json()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/test.json");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module *mod = new fp::Module("", &fp, "/");
			{
				fp::Variable *var = new fp::Variable("\"key\"");
				var->setValue("\"value\"");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("\"number\"");
				var->setValue("1");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("\"boolean\"");
				var->setValue("true");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("\"null\"");
				var->setValue("null");
				mod->addObject(var);
			}
			{
				fp::Module *mod2 = new fp::Module("\"object\"", &fp, "//");
				{
					fp::Variable *var = new fp::Variable("\"key\"");
					var->setValue("\"value\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module *mod2 = new fp::Module("\"array\"", &fp, "//");
				{
					fp::Variable *var = new fp::Variable("\"item1\"");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("\"item2\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module *mod2 = new fp::Module("\"arrayOfObjects\"", &fp, "//");
				{
					fp::Module *mod3 = new fp::Module("", &fp, "//\"arrayOfObjects\"/");
					{
						fp::Variable *var = new fp::Variable("\"key\"");
						var->setValue("\"value\"");
						mod3->addObject(var);
					}
					mod2->addObject(mod3);
				}
				{
					fp::Module *mod3 = new fp::Module("", &fp, "//\"arrayOfObjects\"/");
					{
						fp::Variable *var = new fp::Variable("\"key\"");
						var->setValue("\"value\"");
						mod3->addObject(var);
					}
					mod2->addObject(mod3);
				}
				mod->addObject(mod2);
			}
			expected.addObject(mod);
		}
	}

	// Checking
	std::cout << "test files/test.json: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	webserv_conf()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/webserv.conf");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module *mod = new fp::Module("server", &fp, "/");
			{
				fp::Variable *var = new fp::Variable("listen");
				var->addAttribute("8080");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("client_max_body_size");
				var->addAttribute("100000");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("root");
				var->addAttribute("/mnt/nfs/homes/user/www");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("index");
				var->addAttribute("/html/page/index.html");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("server_name");
				var->addAttribute("server_name");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("error_page");
				var->addAttribute("400");
				var->addAttribute("/html/wsstatus/ws_400.html");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("error_page");
				var->addAttribute("403");
				var->addAttribute("/html/wsstatus/ws_403.html");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("error_page");
				var->addAttribute("404");
				var->addAttribute("/html/wsstatus/ws_404.html");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("error_page");
				var->addAttribute("405");
				var->addAttribute("/html/wsstatus/ws_405.html");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("error_page");
				var->addAttribute("413");
				var->addAttribute("/html/wsstatus/ws_413.html");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("error_page");
				var->addAttribute("500");
				var->addAttribute("/html/wsstatus/ws_500.html");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("error_page");
				var->addAttribute("501");
				var->addAttribute("/html/wsstatus/ws_501.html");
				mod->addObject(var);
			}
			{
				fp::Variable *var = new fp::Variable("error_page");
				var->addAttribute("505");
				var->addAttribute("/html/wsstatus/ws_505.html");
				mod->addObject(var);
			}
			{
				fp::Module *mod2 = new fp::Module("location", &fp, "/server/");
				mod2->addAttribute("/");
				{
					fp::Variable *var = new fp::Variable("allow_methods");
					var->addAttribute("GET");
					var->addAttribute("POST");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("index");
					var->addAttribute("/html/page/index.html");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("autoindex");
					var->addAttribute("off");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module *mod2 = new fp::Module("location", &fp, "/server/");
				mod2->addAttribute("/css");
				{
					fp::Variable *var = new fp::Variable("allow_methods");
					var->addAttribute("GET");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("autoindex");
					var->addAttribute("off");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module *mod2 = new fp::Module("location", &fp, "/server/");
				mod2->addAttribute("/php");
				{
					fp::Variable *var = new fp::Variable("allow_methods");
					var->addAttribute("GET");
					var->addAttribute("POST");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("extension");
					var->addAttribute(".php");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("cgi_path");
					var->addAttribute("/usr/bin/php-cgi");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("autoindex");
					var->addAttribute("off");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module *mod2 = new fp::Module("location", &fp, "/server/");
				mod2->addAttribute("/python");
				{
					fp::Variable *var = new fp::Variable("allow_methods");
					var->addAttribute("GET");
					var->addAttribute("POST");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("extension");
					var->addAttribute(".py");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("cgi_path");
					var->addAttribute("/usr/bin/python3");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("autoindex");
					var->addAttribute("off");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module *mod2 = new fp::Module("location", &fp, "/server/");
				mod2->addAttribute("/html/kitty");
				{
					fp::Variable *var = new fp::Variable("allow_methods");
					var->addAttribute("GET");
					var->addAttribute("POST");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("upload_path");
					var->addAttribute("/mnt/nfs/homes/user/www/upload/");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("autoindex");
					var->addAttribute("off");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module *mod2 = new fp::Module("location", &fp, "/server/");
				mod2->addAttribute("/upload");
				{
					fp::Variable *var = new fp::Variable("allow_methods");
					var->addAttribute("GET");
					var->addAttribute("POST");
					var->addAttribute("DELETE");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("autoindex");
					var->addAttribute("on");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module *mod2 = new fp::Module("location", &fp, "/server/");
				mod2->addAttribute("/img");
				{
					fp::Variable *var = new fp::Variable("allow_methods");
					var->addAttribute("GET");
					var->addAttribute("POST");
					mod2->addObject(var);
				}
				{
					fp::Variable *var = new fp::Variable("autoindex");
					var->addAttribute("off");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module *mod2 = new fp::Module("location", &fp, "/server/");
				mod2->addAttribute("/img/toDelete");
				{
					fp::Variable *var = new fp::Variable("allow_methods");
					var->addAttribute("DELETE");
					var->addAttribute("POST");
					var->addAttribute("GET");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			expected.addObject(mod);
		}
	}

	// Checking
	std::cout << "test files/webserv.conf: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	white_list_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/white_list");
	fp.addToWhitelist("/module/var");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	fp::Variable	*var = new fp::Variable("var");
	var->setValue("1");
	mod->addObject(var);
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/white_list: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	white_list_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/white_list");
	fp.addToWhitelist("/module");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/white_list: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/white_list: ❌" << std::endl;
	delete result;
	return (1);
}

int	white_list_2_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/white_list_2");
	fp.addToWhitelist("/module/mod/key");
	fp.addToWhitelist("/module/var");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	fp::Variable	*var = new fp::Variable("var");
	mod->addObject(var);
	{
		fp::Module		*mod2 = new fp::Module("mod", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/white_list_2: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	white_list_2_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/white_list_2");
	fp.addToWhitelist("/module/mod/key");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/white_list_2: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/white_list_2: ❌" << std::endl;
	delete result;
	return (1);
}

int	white_list_2_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/white_list_2");
	fp.addToWhitelist("/module/var");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/white_list_2: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/white_list_2: ❌" << std::endl;
	delete result;
	return (1);
}

int	white_list_2_2_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/white_list_2_2");
	fp.addToWhitelist("/module/mod/key");
	fp.addToWhitelist("/module/var");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	{
		fp::Module		*mod2 = new fp::Module("mod", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	fp::Variable	*var = new fp::Variable("var");
	mod->addObject(var);
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/white_list_2_2: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	white_list_2_2_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/white_list_2_2");
	fp.addToWhitelist("/module/mod/key");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/white_list_2_2: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/white_list_2_2: ❌" << std::endl;
	delete result;
	return (1);
}

int	white_list_2_2_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/white_list_2_2");
	fp.addToWhitelist("/module/var");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/white_list_2_2: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/white_list_2_2: ❌" << std::endl;
	delete result;
	return (1);
}

int	white_list()
{
	int	ret;
	int	global_ret = 0;

	if ((ret = white_list_test_1()))
		global_ret += 1;
	if ((ret = white_list_test_2()))
		global_ret += 1;
	if ((ret = white_list_2_test_1()))
		global_ret += 1;
	if ((ret = white_list_2_test_2()))
		global_ret += 1;
	if ((ret = white_list_2_test_3()))
		global_ret += 1;
	if ((ret = white_list_2_2_test_1()))
		global_ret += 1;
	if ((ret = white_list_2_2_test_2()))
		global_ret += 1;
	if ((ret = white_list_2_2_test_3()))
		global_ret += 1;
	return (global_ret);
}

int	requirement_list_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/requirement_list");
	fp.require("/module/var");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	{
		fp::Variable	*var = new fp::Variable("var");
		var->setValue("1");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("var2");
		mod->addObject(var);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/requirement_list: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	requirement_list_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/requirement_list");
	fp.require("/module");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	{
		fp::Variable	*var = new fp::Variable("var");
		var->setValue("1");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("var2");
		mod->addObject(var);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/requirement_list: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	requirement_list_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/requirement_list");
	fp.require("/module/var2");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	{
		fp::Variable	*var = new fp::Variable("var");
		var->setValue("1");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("var2");
		mod->addObject(var);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/requirement_list: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	requirement_list_test_4()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/requirement_list");
	fp.require("/module/var3");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/requirement_list: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/requirement_list: ❌" << std::endl;
	delete result;
	return (1);
}

int	requirement_list_2_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/requirement_list_2");
	fp.require("/module/mod/key");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	{
		fp::Module	*mod2 = new fp::Module("mod", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	{
		fp::Variable	*var = new fp::Variable("var");
		var->setValue("1");
		mod->addObject(var);
	}
	{
		fp::Module	*mod2 = new fp::Module("mod2", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	{
		fp::Variable	*var = new fp::Variable("var2");
		mod->addObject(var);
	}
	{
		fp::Module	*mod2 = new fp::Module("mod3", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/requirement_list_2: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	requirement_list_2_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/requirement_list_2");
	fp.require("/module/mod2/key");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	{
		fp::Module	*mod2 = new fp::Module("mod", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	{
		fp::Variable	*var = new fp::Variable("var");
		var->setValue("1");
		mod->addObject(var);
	}
	{
		fp::Module	*mod2 = new fp::Module("mod2", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	{
		fp::Variable	*var = new fp::Variable("var2");
		mod->addObject(var);
	}
	{
		fp::Module	*mod2 = new fp::Module("mod3", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/requirement_list_2: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	requirement_list_2_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/requirement_list_2");
	fp.require("/module/mod3/key");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	{
		fp::Module	*mod2 = new fp::Module("mod", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	{
		fp::Variable	*var = new fp::Variable("var");
		var->setValue("1");
		mod->addObject(var);
	}
	{
		fp::Module	*mod2 = new fp::Module("mod2", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	{
		fp::Variable	*var = new fp::Variable("var2");
		mod->addObject(var);
	}
	{
		fp::Module	*mod2 = new fp::Module("mod3", &fp, "/module/");
		fp::Variable	*var = new fp::Variable("key");
		var->setValue("2");
		mod2->addObject(var);
		mod->addObject(mod2);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/requirement_list_2: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	requirement_list_2_test_4()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/requirement_list_2");
	fp.require("/module/mod3/key2");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/requirement_list_2: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/requirement_list_2: ❌" << std::endl;
	delete result;
	return (1);
}

int	requirement_list_3_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/requirement_list_3");
	fp.require("/module/var");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/requirement_list_3: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/requirement_list_3: ❌" << std::endl;
	delete result;
	return (1);
}

int	requirement_list_4_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/requirement_list_4");
	fp.require("/module/var");

	result = fp.parse();

	// Expected module
	{
		fp::Module	*mod = new fp::Module("module", &fp, "/");
		fp::Variable	*var = new fp::Variable("var");
		mod->addObject(var);
		expected.addObject(mod);
	}
	{
		fp::Module	*mod = new fp::Module("module", &fp, "/");
		fp::Variable	*var = new fp::Variable("var2");
		fp::Variable	*var2 = new fp::Variable("var");
		mod->addObject(var);
		mod->addObject(var2);
		expected.addObject(mod);
	}

	// Checking
	std::cout << "test 1 files/requirement_list_4: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	requirement_list()
{
	int	ret;
	int	global_ret = 0;

	if ((ret = requirement_list_test_1()))
		global_ret += 1;
	if ((ret = requirement_list_test_2()))
		global_ret += 1;
	if ((ret = requirement_list_test_3()))
		global_ret += 1;
	if ((ret = requirement_list_test_4()))
		global_ret += 1;
	if ((ret = requirement_list_2_test_1()))
		global_ret += 1;
	if ((ret = requirement_list_2_test_2()))
		global_ret += 1;
	if ((ret = requirement_list_2_test_3()))
		global_ret += 1;
	if ((ret = requirement_list_2_test_4()))
		global_ret += 1;
	if ((ret = requirement_list_3_test_1()))
		global_ret += 1;
	if ((ret = requirement_list_4_test_1()))
		global_ret += 1;
	return (global_ret);
}

int	variable_value_presence_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence");
	fp.banVariableValue();
	result = fp.parse();

	// Expected module
	fp::Variable	*var = new fp::Variable("var");
	expected.addObject(var);

	// Checking
	std::cout << "test 1 files/variable_value_presence: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	variable_value_presence_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence");
	fp.allowVariableValue();
	result = fp.parse();

	// Expected module
	fp::Variable	*var = new fp::Variable("var");
	expected.addObject(var);

	// Checking
	std::cout << "test 2 files/variable_value_presence: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	variable_value_presence_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/variable_value_presence");
	fp.forceVariableValue();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/variable_value_presence: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/variable_value_presence: ❌" << std::endl;
	delete result;
	return (1);
}

int	variable_value_presence_2_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence_2");
	fp.forceVariableValue();
	result = fp.parse();

	// Expected module
	fp::Variable	*var = new fp::Variable("var");
	var->setValue("2");
	expected.addObject(var);

	// Checking
	std::cout << "test 1 files/variable_value_presence_2: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	variable_value_presence_2_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence_2");
	fp.allowVariableValue();
	result = fp.parse();

	// Expected module
	fp::Variable	*var = new fp::Variable("var");
	var->setValue("2");
	expected.addObject(var);

	// Checking
	std::cout << "test 2 files/variable_value_presence_2: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	variable_value_presence_2_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/variable_value_presence_2");
	fp.banVariableValue();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/variable_value_presence_2: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/variable_value_presence_2: ❌" << std::endl;
	delete result;
	return (1);
}

int	variable_value_presence_3_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence_3");
	fp.allowVariableValue();
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp, "/");
	{
		fp::Variable	*var = new fp::Variable("TextDecoderStream");
		var->setValue("2");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("addEventListener");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("var");
		var->setValue("OUIIIIIIIIIIIII");
		mod->addObject(var);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/variable_value_presence_3: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	variable_value_presence_3_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence_3");
	fp.forceVariableValue();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/variable_value_presence_3: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/variable_value_presence_3: ❌" << std::endl;
	delete result;
	return (1);
}

int	variable_value_presence_3_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/variable_value_presence_3");
	fp.banVariableValue();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/variable_value_presence_3: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/variable_value_presence_3: ❌" << std::endl;
	delete result;
	return (1);
}

int	variable_value_presence_4_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence_4");
	fp.forceVariableValue();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("module", &fp, "/");
	{
		fp::Variable	*var = new fp::Variable("TextDecoderStream");
		var->setValue("3123123");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("addEventListener");
		var->setValue("hgsgadhiajskdsa");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("var");
		var->addAttribute("attr");
		var->setValue("OUIIIIIIIIIIIII");
		mod->addObject(var);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/variable_value_presence_4: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	variable_value_presence_4_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence_4");
	fp.allowVariableValue();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("module", &fp, "/");
	{
		fp::Variable	*var = new fp::Variable("TextDecoderStream");
		var->setValue("3123123");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("addEventListener");
		var->setValue("hgsgadhiajskdsa");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("var");
		var->addAttribute("attr");
		var->setValue("OUIIIIIIIIIIIII");
		mod->addObject(var);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 2 files/variable_value_presence_4: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	variable_value_presence_4_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/variable_value_presence_4");
	fp.banVariableValue();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/variable_value_presence_4: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/variable_value_presence_4: ❌" << std::endl;
	delete result;
	return (1);
}

int	variable_value_presence_5_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence_5");
	fp.allowVariableValue();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("module", &fp, "/");
	{
		fp::Variable	*var = new fp::Variable("TextDecoderStream");
		var->addAttribute("adsad");
		var->addAttribute("sad");
		var->addAttribute("debugger");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("asdasd");
		var->addAttribute("a");
		var->setValue("2");
		mod->addObject(var);
	}
	{
		fp::Variable	*var = new fp::Variable("asdhashd");
		var->setValue("nmvccv");
		mod->addObject(var);
	}
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/variable_value_presence_5: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	variable_value_presence_5_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence_5");
	fp.forceVariableValue();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/variable_value_presence_5: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/variable_value_presence_5: ❌" << std::endl;
	delete result;
	return (1);
}

int	variable_value_presence_5_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/variable_value_presence_5");
	fp.banVariableValue();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/variable_value_presence_5: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/variable_value_presence_5: ❌" << std::endl;
	delete result;
	return (1);
}

int	variable_value_presence_6_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence_6");
	fp.forceVariableValue();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 1 files/variable_value_presence_6: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 1 files/variable_value_presence_6: ❌" << std::endl;
	delete result;
	return (1);
}

int	variable_value_presence_6_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/variable_value_presence_6");
	fp.allowVariableValue();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/variable_value_presence_6: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/variable_value_presence_6: ❌" << std::endl;
	delete result;
	return (1);
}

int	variable_value_presence_6_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/variable_value_presence_6");
	fp.banVariableValue();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/variable_value_presence_6: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/variable_value_presence_6: ❌" << std::endl;
	delete result;
	return (1);
}

int	variable_value_presence()
{
	int	ret;
	int	global_ret = 0;

	if ((ret = variable_value_presence_test_1()))
		global_ret += 1;
	if ((ret = variable_value_presence_test_2()))
		global_ret += 1;
	if ((ret = variable_value_presence_test_3()))
		global_ret += 1;
	if ((ret = variable_value_presence_2_test_1()))
		global_ret += 1;
	if ((ret = variable_value_presence_2_test_2()))
		global_ret += 1;
	if ((ret = variable_value_presence_2_test_3()))
		global_ret += 1;
	if ((ret = variable_value_presence_3_test_1()))
		global_ret += 1;
	if ((ret = variable_value_presence_3_test_2()))
		global_ret += 1;
	if ((ret = variable_value_presence_3_test_3()))
		global_ret += 1;
	if ((ret = variable_value_presence_4_test_1()))
		global_ret += 1;
	if ((ret = variable_value_presence_4_test_2()))
		global_ret += 1;
	if ((ret = variable_value_presence_4_test_3()))
		global_ret += 1;
	if ((ret = variable_value_presence_5_test_1()))
		global_ret += 1;
	if ((ret = variable_value_presence_5_test_2()))
		global_ret += 1;
	if ((ret = variable_value_presence_5_test_3()))
		global_ret += 1;
	if ((ret = variable_value_presence_6_test_1()))
		global_ret += 1;
	if ((ret = variable_value_presence_6_test_2()))
		global_ret += 1;
	if ((ret = variable_value_presence_6_test_3()))
		global_ret += 1;
	return (global_ret);
}

int	module_name_presence_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence");
	fp.allowModuleName();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("", &fp, "/");
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/module_name_presence: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	module_name_presence_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence");
	fp.forceModuleName();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/module_name_presence: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/module_name_presence: ❌" << std::endl;
	delete result;
	return (1);
}

int	module_name_presence_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence");
	fp.banModuleName();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("", &fp, "/");
	expected.addObject(mod);

	// Checking
	std::cout << "test 3 files/module_name_presence: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	module_name_presence_2_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence_2");
	fp.allowModuleName();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("m", &fp, "/");
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/module_name_presence_2: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	module_name_presence_2_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence_2");
	fp.forceModuleName();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("m", &fp, "/");
	expected.addObject(mod);

	// Checking
	std::cout << "test 2 files/module_name_presence_2: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	module_name_presence_2_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/module_name_presence_2");
	fp.banModuleName();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/module_name_presence_2: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/module_name_presence_2: ❌" << std::endl;
	delete result;
	return (1);
}

int	module_name_presence_3_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence_3");
	fp.allowModuleName();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("", &fp, "/");
	fp::Module	*mod2 = new fp::Module("m", &fp, "//");
	mod->addObject(mod2);
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/module_name_presence_3: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	module_name_presence_3_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence_3");
	fp.forceModuleName();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/module_name_presence_3: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/module_name_presence_3: ❌" << std::endl;
	delete result;
	return (1);
}

int	module_name_presence_3_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/module_name_presence_3");
	fp.banModuleName();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/module_name_presence_3: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/module_name_presence_3: ❌" << std::endl;
	delete result;
	return (1);
}

int	module_name_presence_4_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence_4");
	fp.allowModuleName();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("m", &fp, "/");
	fp::Module	*mod2 = new fp::Module("m", &fp, "/m/");
	mod->addObject(mod2);
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/module_name_presence_4: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	module_name_presence_4_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence_4");
	fp.forceModuleName();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("m", &fp, "/");
	fp::Module	*mod2 = new fp::Module("m", &fp, "/m/");
	mod->addObject(mod2);
	expected.addObject(mod);

	// Checking
	std::cout << "test 2 files/module_name_presence_4: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	module_name_presence_4_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/module_name_presence_4");
	fp.banModuleName();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/module_name_presence_4: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/module_name_presence_4: ❌" << std::endl;
	delete result;
	return (1);
}

int	module_name_presence_5_test_1()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence_5");
	fp.allowModuleName();
	result = fp.parse();

	// Expected module
	fp::Module	*mod = new fp::Module("m", &fp, "/");
	fp::Module	*mod2 = new fp::Module("", &fp, "/m/");
	mod->addObject(mod2);
	expected.addObject(mod);

	// Checking
	std::cout << "test 1 files/module_name_presence_5: ";
	if (*result == expected)
		std::cout << "✅" << std::endl;
	else
	{
		std::cout << "❌" << std::endl;
		std::cout << "  Expected:" << std::endl;
		expected.print(2);
		std::cout << "  Found:" << std::endl;
		result->print(2);
		delete result;
		return (1);
	}
	delete result;
	return (0);
}

int	module_name_presence_5_test_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp, "");

	// File parsing
	fp.setFileName("files/module_name_presence_5");
	fp.forceModuleName();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 2 files/module_name_presence_5: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 2 files/module_name_presence_5: ❌" << std::endl;
	delete result;
	return (1);
}

int	module_name_presence_5_test_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/module_name_presence_5");
	fp.banModuleName();

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/module_name_presence_5: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/module_name_presence_5: ❌" << std::endl;
	delete result;
	return (1);
}

int	module_name_presence()
{
	int	ret;
	int	global_ret = 0;

	if ((ret = module_name_presence_test_1()))
		global_ret += 1;
	if ((ret = module_name_presence_test_2()))
		global_ret += 1;
	if ((ret = module_name_presence_test_3()))
		global_ret += 1;
	if ((ret = module_name_presence_2_test_1()))
		global_ret += 1;
	if ((ret = module_name_presence_2_test_2()))
		global_ret += 1;
	if ((ret = module_name_presence_2_test_3()))
		global_ret += 1;
	if ((ret = module_name_presence_3_test_1()))
		global_ret += 1;
	if ((ret = module_name_presence_3_test_2()))
		global_ret += 1;
	if ((ret = module_name_presence_3_test_3()))
		global_ret += 1;
	if ((ret = module_name_presence_4_test_1()))
		global_ret += 1;
	if ((ret = module_name_presence_4_test_2()))
		global_ret += 1;
	if ((ret = module_name_presence_4_test_3()))
		global_ret += 1;
	if ((ret = module_name_presence_5_test_1()))
		global_ret += 1;
	if ((ret = module_name_presence_5_test_2()))
		global_ret += 1;
	if ((ret = module_name_presence_5_test_3()))
		global_ret += 1;
	return (global_ret);
}

int	bad_end()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/bad_end");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/bad_end: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/bad_end: ❌" << std::endl;
	delete result;
	return (1);
}

int	bad_end_nl()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/bad_end_nl");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/bad_end_nl: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/bad_end_nl: ❌" << std::endl;
	delete result;
	return (1);
}

int	bad_end_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/bad_end_2");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/bad_end_2: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/bad_end_2: ❌" << std::endl;
	delete result;
	return (1);
}

int	bad_end_3()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/bad_end_3");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/bad_end_3: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/bad_end_3: ❌" << std::endl;
	delete result;
	return (1);
}

int	bad_end_tests()
{
	int	ret;
	int	global_ret = 0;

	if ((ret = bad_end()))
		global_ret += 1;
	if ((ret = bad_end_nl()))
		global_ret += 1;
	if ((ret = bad_end_2()))
		global_ret += 1;
	if ((ret = bad_end_3()))
		global_ret += 1;
	return (global_ret);
}

int	bad_double_comma()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/bad_double_comma");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/bad_double_comma: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/bad_double_comma: ❌" << std::endl;
	delete result;
	return (1);
}

int	bad_double_comma_2()
{
	fp::FileParser	fp;
	fp::Module 		*result;

	// File parsing
	fp.setFileName("files/bad_double_comma_2");

	try {
		result = fp.parse();
	}
	catch (fp::FileParser::FileParserSyntaxException &e)
	{
		std::cout << "test 3 files/bad_double_comma_2: ✅: " << e.what() << std::endl;
		return (0);
	}
	std::cout << "test 3 files/bad_double_comma_2: ❌" << std::endl;
	delete result;
	return (1);
}

int	main(void)
{
	int	ret;
	int	global_ret = 0;

	if (equal_operator_test())
	{
		std::cerr << "equal_operator_test failed: can't continue test while equal_operator_test is failing" << std::endl;
		return (1);
	}

	if ((ret = empty_file()))
		global_ret += ret;

	if ((ret = no_module_tests()))
		global_ret += ret;

	if ((ret = simple_module_test()))
		global_ret += ret;

	if ((ret = simple_module_comma()))
		global_ret += ret;

	if ((ret = multiple_lines()))
		global_ret += ret;

	if ((ret = simple_compact()))
		global_ret += ret;

	if ((ret = global_test()))
		global_ret += ret;

	if ((ret = simple_module_no_value()))
		global_ret += ret;

	if ((ret = special_end_test()))
		global_ret += ret;

	if ((ret = test_json()))
		global_ret += ret;

	if ((ret = webserv_conf()))
		global_ret += ret;

	if ((ret = variable_value_presence()))
		global_ret += ret;

	if ((ret = module_name_presence()))
		global_ret += ret;

	if ((ret = white_list()))
		global_ret += ret;

	if ((ret = requirement_list()))
		global_ret += ret;

	if ((ret = bad_end_tests()))
		global_ret += ret;

	if ((ret = bad_double_comma()))
		global_ret += ret;

	if ((ret = bad_double_comma_2()))
		global_ret += ret;

	if (global_ret)
		std::cout << "total: ❌ (" << global_ret << " errors)" << std::endl;
	else
		std::cout << "total: ✅" << std::endl;
	return (0);
}