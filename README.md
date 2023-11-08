# FileParser
@TODO: explain it's a lib project with a central class FileParser that can be used to parse different file types

FileParser is a c++ library that can be used to parse different file types. The library is written in c++98 and can be used in any c++ project. The library is compiled and tested with clang 12.0.1-19ubuntu3.

# ROADMAP
## TODO
- variable value presence (tests)
- module name presence (tests)
- change whitelist and requirementlist exception
- attribute presence
- last attribute become value
- Add a check of unique variable names (for 2 possibility: for all the file and with path (unique name in a module))
- blacklist for module names
- blacklist for variable names
- Need coma after end of module -> json = true, conf = false
- Ban variables value for specific variables name
- Add whitelist for module names (More tests ?)
- Add requirement list for mix module names and variable names (more tests ?)

## TO TEST
- test different getter of objects (module, variable)
``` unique variable names
mod {
	var,
	var
}
```
``` unique variable names
mod {
	var,
	var2,
	var
}
```
``` FAKE: unique variable names
mod {
	var,
	var2,
	va
}
```
