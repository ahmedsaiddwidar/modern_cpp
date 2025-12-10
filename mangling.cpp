Name mangling (also called symbol mangling) is a process used by C++ compilers to encode additional information (like types, namespaces, class names) into function and variable names in the compiled output (object files or binaries). This is needed because C++ supports features that C doesn't, such as:

    Function overloading

    Namespaces

    Templates

    Classes with member functions