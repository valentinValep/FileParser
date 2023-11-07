# FileParser
@TODO: explain it's a lib project with a central class FileParser that can be used to parse different file types

FileParser is a c++ library that can be used to parse different file types. The library is written in c++98 and can be used in any c++ project. The library is compiled and tested with clang 12.0.1-19ubuntu3.

# ROADMAP
## TODO
- Add whitelist for variable names (tests)
- Add whitelist for module names
- Add requirement list for mix module names and variable names (ex: "module1.variable1")
- Add a check of double like requirement list
- variable value presence (tests)
- module name presence (tests)
- attribute presence
- last attribute become value
- blacklist for module names
- blacklist for variable names

## TO TEST
```
mod {
	var,
}
```
```
mod {
	var,,
}
```
```
mod {
	var,,var
}
```
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
