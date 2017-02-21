# Notes regarding Ch 3

Regarding assignment to variables, the assumption is made that the variable name is written into the assembly file in the data section. As such, the generated assembly cannot be immediately compiled, and needs to be modified to include variables.

In the main file, there is an example of initializing a variable in NASM syntax. Note that the variable names are always capitalized since names are always made to be upper case in the compiler.

Additionally, in NASM, the `lea` instruction is unnecessary to store data in a variable. We can just invoke `mov` with the bracket notation directly as will be shown when you try to generate the assembly.
