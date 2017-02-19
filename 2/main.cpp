#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#include "cradle.h"

using std::string;

bool IsAddop(char c);
bool IsMulop(char c);
void Factor();
void Term();
void Add();
void Subtract();
void Multiply();
void Divide();
void Expression();

bool IsAddop(char c) {
  return string("+-").find(c) != string::npos;
}

bool IsMulop(char c) {
  return string("*/").find(c) != string::npos;
}

void Factor() {
  if (Look == '('){
    Match('(');
    Expression();
    Match(')');
  }
  else{
    EmitLn("mov rax, " + CharToStr(GetNum()));
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
      default:
        Expected("Mulop");
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
      default:
        Expected("Addop");
      }
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
