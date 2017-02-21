#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#include "cradle.h"

using std::string;

int Factor();
int Term();
int Expression();
void Assignment();

// Parse and translate a math factor
int Factor() {
  int Value;
  if (Look == '('){
    Match('(');
    Value = Expression();
    Match(')');
  }
  else if (IsAlpha(Look)){
    Value = Table[GetName()];
  }
  else{
    Value = GetNum();
  }
  return Value;
}

// Parse and translate a math term
int Term() {
  int Value = Factor();
  while (IsMulop(Look)){
    switch(Look) {
      case '*':
        Match('*');
        Value *= Factor();
        break;
      case '/':
        Match('/');
        Value /= Factor();
        break;
      }
    }
    return Value;
}

// Parse and translate a math expression
int Expression() {
  int Value;
  if (IsAddop(Look))
    Value = 0;
  else
    Value = Term();
  while (IsAddop(Look)){
    switch(Look) {
      case '+':
        Match('+');
        Value += Term();
        break;
      case '-':
        Match('-');
        Value -= Term();
        break;
      }
    }
    return Value;
}

void Assignment() {
  string Name = GetName();
  Match('=');
  Table[Name] = Expression();
}

// A bit different from article - format for input is
// ?<variable name>(<expression>)
// note the mandatory set of parenthesis
void Input() {
  Match('?');
  string Name = GetName();
  Table[Name] = Expression();
}

void Output() {
  Match('!');
  std::cout << Table[GetName()] << std::endl;
}

int main() {
  Init();
  do {
    switch (Look){
      case '?':
        Input();
        break;
      case '!':
        Output();
        break;
      default:
        Assignment();
    }
    NewLine();
  } while(Look != '.');

  return 0;
}
