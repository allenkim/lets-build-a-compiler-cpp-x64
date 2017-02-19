#include <iostream>
#include <string>

#include "cradle.h"

using std::string;

void Term() {
  EmitLn("mov rax, " + CharToStr(GetNum()));
}

void Add() {
  Match('+');
  Term();
  EmitLn("add rax, rbx");
}

void Subtract() {
  Match('-');
  Term();
  EmitLn("sub rax, rbx");
}

// Parse and translate a math expression
void Expression() {
  Term();
  EmitLn("mov rbx, rax");

  switch(Look) {
    case '+':
      Add();
      break;
    case '-':
      Subtract();
      break;
    default:
      Expected("....");
  }
}

int main() {

    Init();
    EmitLn("global main");
    EmitLn("section .text");
    EmitLn("main:");
    Expression();

    return 0;
}
