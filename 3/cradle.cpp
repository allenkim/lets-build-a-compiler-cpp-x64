#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>

#include "cradle.h"

using std::cout;
using std::endl;
using std::string;

std::locale loc;
char Look;

void GetChar() {
  Look = getchar();
}

string CharToStr(char x) {
  return string(1,x);
}

void Error(string s) {
  cout << "\nError: " << s << '.' << endl;
}

void Abort(string s) {
  Error(s);
  exit(1);
}

void Expected(string s) {
  Abort(s + " Expected");
}

void Match(char x) {
  if (Look != x){
    Expected("'" + CharToStr(x) + "'");
  }
  else{
    GetChar();
    SkipWhite();
  }

}


bool IsAlpha(char c) {
  return std::isalpha(c, loc);
}

bool IsDigit(char c) {
  return std::isdigit(c, loc);
}
bool IsAlnum(char c) {
  return std::isalnum(c, loc);
}
bool IsWhite(char c) {
  if (c == '\n')
    return false;
  return std::isspace(c, loc);
}

void SkipWhite() {
  while (IsWhite(Look))
    GetChar();
}

string GetName() {
  string Token = "";

  if (!IsAlpha(Look))
    Expected("Name");

  while (IsAlpha(Look)){
    Token += std::toupper(Look, loc);
    GetChar();
  }

  SkipWhite();
  return Token;
}

string GetNum() {
  string Token = "";

  if (!IsDigit(Look))
    Expected("Integer");

  while (IsDigit(Look)){
    Token += Look;
    GetChar();
  }

  SkipWhite();
  return Token;
}


void Emit(string s) {
  cout << "\t" << s;
}

void EmitLn(string s) {
  Emit(s);
  cout << endl;
}

void Init() {
  GetChar();
  SkipWhite();
}
