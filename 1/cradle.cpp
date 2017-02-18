#include "cradle.h"
#include <iostream>
#include <string>
#include <locale>
#include <cstdio>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

void GetChar() {
    Look = getchar();
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
    if (Look == x)
        GetChar();
    else
        Expected("'" + string(1,x) + "'");
}

int IsAlpha(char c) {
    return std::isalpha(c, loc);
}

int IsDigit(char c) {
    return std::isdigit(c, loc);
}


char GetName()
{
    if (!IsAlpha(Look))
        Expected(string("Name"));
    char c = Look;
    GetChar();
    return std::toupper(c, loc);
}


char GetNum()
{
    if (!IsDigit(Look))
        Expected("Integer");
    char c = Look;
    GetChar();
    return c;
}

void Emit(string s)
{
    cout << "\t" << s;
}

void EmitLn(string s)
{
    Emit(s);
    cout << endl;
}

void Init()
{
    GetChar();
}
