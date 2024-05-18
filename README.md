# WIP

## Pull Requests instructions
In order to maintain code quality and readability through the whole project structure, it is needed to follow a couple guidelines for classes code:
1. Keep the portability at its best! Each structure is taken directly from official header files from their own executable structures and included in their own `wrapper headers` (I.E. `winstructs.h` & `wintypes.h` for windows and `linuxstructs.h` & `linuxtypes.h` for linux etc...)
2. When creating a new BinaryManager Template, create it in its own, explicitly named, `.hpp` file, into the `include` folder; so that the template classes are easily separated and not keen to confusion.
3. Use explicit and non-vague types: don't use `int` or such, use int32_t instead
4. If a structure uses `DWORD` for a field type, use `DWORD` for the values that goes in there, same for other "original" typedefs
