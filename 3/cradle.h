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

// Recognize Add/Minus Operation
bool IsAddop(char c);
// Recognize Multiplication/Divide Operation
bool IsMulop(char c);
// Recognize an Alpha character
bool IsAlpha(char c);
// Recognize a Decimal digit
bool IsDigit(char c);
// Recognize a Alphanumeric
bool IsAlnum(char c);
// Recognize White Space
bool IsWhite(char c);

// Skip Over Leading White Space
void SkipWhite();

// Get an Identifier
string GetName();
// Get a Number
string GetNum();

// Output a string with a tab
void Emit(string s);
// Output a string with new line
void EmitLn(string s);

// Initialize
void Init();
