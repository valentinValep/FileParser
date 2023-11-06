#include "FileParser.hpp"
#include "Module.hpp"
#include "Variable.hpp"
#include <iostream>

int	equal_operator_test()
{
	fp::FileParser	fp;
	{
		fp::Module		expected("1", &fp);
		fp::Module		expected2("2", &fp);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		expected.addAttribute("attr");

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		expected.addAttribute("attr");
		expected2.addAttribute("attr");

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		fp::Variable	*var = new fp::Variable("var");
		expected.addObject(var);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		fp::Module		*mod = new fp::Module("mod", &fp);
		expected.addObject(mod);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		fp::Module		*mod = new fp::Module("mod", &fp);
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod", &fp);
		expected2.addObject(mod2);

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		fp::Module		*mod = new fp::Module("mod", &fp);
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod2", &fp);
		expected2.addObject(mod2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		fp::Module		*mod = new fp::Module("mod", &fp);
		expected.addObject(mod);
		mod->addAttribute("attr");
		fp::Module		*mod2 = new fp::Module("mod", &fp);
		expected2.addObject(mod2);

		if (expected == expected2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected == expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		fp::Module		*mod = new fp::Module("mod", &fp);
		expected.addObject(mod);
		mod->addAttribute("attr");
		fp::Module		*mod2 = new fp::Module("mod", &fp);
		expected2.addObject(mod2);
		mod2->addAttribute("attr");

		if (!(expected == expected2))
		{
			std::cerr << __FILE__ << ":" << __LINE__ << ": " << "equal_operator_test failed: expected != expected2" << std::endl;
			return (1);
		}
	}
	{
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		fp::Module		*mod = new fp::Module("mod", &fp);
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		fp::Module		*mod = new fp::Module("mod", &fp);
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		fp::Module		*mod = new fp::Module("mod", &fp);
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod", &fp);
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
		fp::Module		expected("name", &fp);
		fp::Module		expected2("name", &fp);
		fp::Module		*mod = new fp::Module("mod", &fp);
		expected.addObject(mod);
		fp::Module		*mod2 = new fp::Module("mod", &fp);
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

int	simple_module_test()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp);

	// File parsing
	fp.setFileName("files/simple_module");
	result = fp.parse();

	// Expected module
	fp::Module		*mod = new fp::Module("module", &fp);
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

int	multiple_lines()
{
	fp::FileParser	fp;
	fp::Module 		*result;
	fp::Module		expected("", &fp);

	// File parsing
	fp.setFileName("files/multiple_lines");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module		*mod = new fp::Module("module", &fp);
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
			fp::Module		*mod = new fp::Module("module2", &fp);
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
	fp::Module		expected("", &fp);

	// File parsing
	fp.setFileName("files/simple_compact");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module		*mod = new fp::Module("module", &fp);
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
	fp::Module		expected("", &fp);

	// File parsing
	fp.setFileName("files/global_test");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module		*mod = new fp::Module("module", &fp);
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
				fp::Module		*mod2 = new fp::Module("\"module\"", &fp);
				{
					fp::Variable	*var = new fp::Variable("\"key\"");
					var->setValue("\"value\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("module", &fp);
				{
					fp::Variable	*var = new fp::Variable("\"key\"");
					var->setValue("\"value\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("\"module\"", &fp);
				{
					fp::Variable	*var = new fp::Variable("\"key\"");
					var->setValue("\"value\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("module", &fp);
				{
					fp::Variable	*var = new fp::Variable("\"key\"");
					var->setValue("\"value\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("module_name", &fp);
				mod2->addAttribute("module_var");
				{
					fp::Variable	*var = new fp::Variable("key");
					var->setValue("value");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module		*mod2 = new fp::Module("\"array\"", &fp);
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
				fp::Module		*mod2 = new fp::Module("array", &fp);
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
	fp::Module		expected("", &fp);

	// File parsing
	fp.setFileName("files/simple_module_no_value");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module		*mod = new fp::Module("module", &fp);
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
	fp::Module		expected("", &fp);

	// File parsing
	fp.setFileName("files/special_end_test");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module		*mod = new fp::Module("mod", &fp);
			{
				fp::Variable	*var = new fp::Variable("var");
				mod->addObject(var);
			}
			expected.addObject(mod);
		}
		{
			fp::Module		*mod = new fp::Module("mod2", &fp);
			{
				fp::Variable	*var = new fp::Variable("var");
				var->addAttribute("attr1");
				mod->addObject(var);
			}
			expected.addObject(mod);
		}
		{
			fp::Module		*mod = new fp::Module("mod3", &fp);
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
	fp::Module		expected("", &fp);

	// File parsing
	fp.setFileName("files/test.json");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module *mod = new fp::Module("", &fp);
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
				fp::Module *mod2 = new fp::Module("\"object\"", &fp);
				{
					fp::Variable *var = new fp::Variable("\"key\"");
					var->setValue("\"value\"");
					mod2->addObject(var);
				}
				mod->addObject(mod2);
			}
			{
				fp::Module *mod2 = new fp::Module("\"array\"", &fp);
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
				fp::Module *mod2 = new fp::Module("\"arrayOfObjects\"", &fp);
				{
					fp::Module *mod3 = new fp::Module("", &fp);
					{
						fp::Variable *var = new fp::Variable("\"key\"");
						var->setValue("\"value\"");
						mod3->addObject(var);
					}
					mod2->addObject(mod3);
				}
				{
					fp::Module *mod3 = new fp::Module("", &fp);
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
	fp::Module		expected("", &fp);

	// File parsing
	fp.setFileName("files/webserv.conf");
	result = fp.parse();

	// Expected module
	{
		{
			fp::Module *mod = new fp::Module("server", &fp);
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
				fp::Module *mod2 = new fp::Module("location", &fp);
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
				fp::Module *mod2 = new fp::Module("location", &fp);
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
				fp::Module *mod2 = new fp::Module("location", &fp);
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
				fp::Module *mod2 = new fp::Module("location", &fp);
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
				fp::Module *mod2 = new fp::Module("location", &fp);
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
				fp::Module *mod2 = new fp::Module("location", &fp);
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
				fp::Module *mod2 = new fp::Module("location", &fp);
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
				fp::Module *mod2 = new fp::Module("location", &fp);
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

int	main(void)
{
	int	ret;
	int	global_ret = 0;

	if (equal_operator_test())
	{
		std::cerr << "equal_operator_test failed: can't continue test while equal_operator_test is failing" << std::endl;
		return (1);
	}

	if ((ret = simple_module_test()))
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

	// variable value presence tests

	// module name presence tests

	// attribute presence tests

	// whitelist tests

	// last attribute become value tests

	// @TODO test different file parsers (variables value presence, etc.)

	return (0);
}