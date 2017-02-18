#include <iostream>
#include <string>

#include "cradle.h"

using std::string;

// Parse and translate a math expression
void Expression() {
  EmitLn(string("movl $" + CharToStr(GetNum()) + ", %eax" ));
}

int main() {

    Init();
    EmitLn(".globl main");
    EmitLn("main:");
    Expression();

    return 0;
}
