#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#include "cradle.h"

using std::string;

void Ident();
void Factor();
void Term();
void Add();
void Subtract();
void Multiply();
void Divide();
void Expression();
void Assignment();

void Ident() {
  string Name = GetName();
  if (Look == '('){
    Match('(');
    Match(')');
    EmitLn("call " + Name);
  }
  else{
    EmitLn("mov rax, " + Name);
  }
}

void Factor() {
  if (Look == '('){
    Match('(');
    Expression();
    Match(')');
  }
  else if (IsAlpha(Look)){
    Ident();
  }
  else{
    EmitLn("mov rax, " + GetNum());
  }
}

void Term() {
  Factor();
  while (IsMulop(Look)){
    EmitLn("push rax");
    switch(Look) {
      case '*':
        Multiply();
        break;
      case '/':
        Divide();
        break;
      }
    }
}

void Add() {
  Match('+');
  Term();
  EmitLn("pop rbx");
  EmitLn("add rax, rbx");
}

void Subtract() {
  Match('-');
  Term();
  EmitLn("pop rbx");
  EmitLn("sub rax, rbx");
  EmitLn("neg rax");
}

void Multiply() {
  Match('*');
  Term();
  EmitLn("pop rbx");
  EmitLn("mul rbx");
}

void Divide() {
  Match('/');
  Term();
  EmitLn("mov rbx, rax");
  EmitLn("pop rax");
  EmitLn("xor rdx, rdx");
  EmitLn("div rbx");
}

// Parse and translate a math expression
void Expression() {
  if (IsAddop(Look))
    EmitLn("xor rax, rax");
  else
    Term();
  while (IsAddop(Look)){
    EmitLn("push rax");
    switch(Look) {
      case '+':
        Add();
        break;
      case '-':
        Subtract();
        break;
      }
    }
}

void Assignment() {
  string Name = GetName();
  Match('=');
  Expression();
  EmitLn("mov [" + Name + "], rax");
}

int main() {

    Init();
    EmitLn("global main");
    // required by gcc for labeled memory locations in NASM
    EmitLn("default rel");

    // this is not addressed in the series and is ASM specific
    EmitLn("section .data");
    // example of initializing variable in data, adjust as needed
    EmitLn("TMP dw 0");

    EmitLn("section .text");
    EmitLn("main:");
    Assignment();
    if (Look != '\n')
      Expected("Newline");
    return 0;
}
