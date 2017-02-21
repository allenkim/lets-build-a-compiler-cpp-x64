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
std::map<string,int> Table;

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
  return c == ' ' || c == '\t';
}

bool IsAddop(char c) {
  return string("+-").find(c) != string::npos;
}

bool IsMulop(char c) {
  return string("*/").find(c) != string::npos;
}

void SkipWhite() {
  while (IsWhite(Look))
    GetChar();
}

void NewLine() {
  if (Look == '\r'){
    GetChar();
    if (Look == '\n')
      GetChar();
  }
  else if (Look == '\n')
    GetChar();
}

string GetName() {
  string Token = "";

  if (!IsAlpha(Look)){
    Expected("Name");
  }

  while (IsAlpha(Look)){
    Token += std::toupper(Look, loc);
    GetChar();
  }

  SkipWhite();
  return Token;
}

int GetNum() {
  if (!IsDigit(Look))
    Expected("Integer");

  int Value = 0;
  while (IsDigit(Look)){
    Value = 10 * Value + (Look - '0');
    GetChar();
  }
  return Value;
}


void Emit(string s) {
  cout << "\t" << s;
}

void EmitLn(string s) {
  Emit(s);
  cout << endl;
}

void Init() {
  InitTable();
  GetChar();
}

void InitTable() {
  // no need to initialize for std::map!
  // just here for completeness
}
