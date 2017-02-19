#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#include "cradle.h"

using std::string;

void Factor();
void Term();
void Add();
void Subtract();
void Multiply();
void Divide();
void Expression();

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
  while (string("*/").find(Look) != string::npos){
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
  EmitLn("mov rdx, 0");
  EmitLn("div rbx");
}

// Parse and translate a math expression
void Expression() {
  Term();
  while (string("+-").find(Look) != string::npos){
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
