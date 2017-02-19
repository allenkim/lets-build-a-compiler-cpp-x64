#pragma once

#include <locale>
#include <string>

using std::string;

// Used to specify the locale - uses default classic locale
extern std::locale loc;

// Lookahead character
extern char Look;

// Read character from input stream
void GetChar();

// Convert char to string - not in book, but helpful for C++
string CharToStr(char x);

// Report an error
void Error(string s);
// Report an error and halt
void Abort(string s);
// Report what was expected
void Expected(string s);
// Match a specific character
void Match(char x);

// Recognize an Alpha character
int IsAlpha(char c);
// Recognize a Decimal digit
int IsDigit(char c);

// Get an Identifier
char GetName();
// Get a Number
char GetNum();

// Output a string with a tab
void Emit(string s);
// Output a string with new line
void EmitLn(string s);

// Initialize
void Init();
