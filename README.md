# Let's Build a Compiler
## C++ Version with x86-64 Assembly

["Let's Build a Compiler"](http://compilers.iecc.com/crenshaw/) is an awesome series by Jack Crenshaw to introduce beginners to compilers, but the code for the compiler is written in Turbo Pascal and outputs assembly in 68000 code.

This will try to convert the Turbo Pascal code into C++ equivalent, and the assembly into x86-64 equivalent. The assembly will use Intel syntax using the NASM assembler. I tried using AT&T syntax since the GNU assembler (GAS) uses it by default, but it was pretty horrendous looking in my eyes compared to the Intel style...

However, in a 64bit Linux environment, we can now run the generated assembly! With nasm installed, we first run:
```sh
nasm -felf64 test.asm
```
where test.asm can be replaced with whatever the assembly file was named. This generates the object file and now we need to link it. Generally, we link it with the C library, so we can call:
```sh
gcc test.o
```
That's it to get the executable! For many beginning programs though, it doesn't really output anything, but theres stuff going on in the registers. To follow the code, I recommend GDB and using `layout asm` and `stepi` to go through the program.
