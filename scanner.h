/* The filename is Scanner.h
 */

#ifndef _H_scanner
#define _H_scanner

#include <stdio.h>

#define MaxIdentLen 31    // Maximum length for identifiers

  
typedef enum { 
    T_Void = 256,
    T_Int, T_Double, T_Bool, T_String, T_Class, T_Null, T_Dims,
    T_LessEqual, T_GreaterEqual, T_Equal, T_NotEqual, T_And, T_Or,
    T_While, T_For, T_If, T_Else, T_Return, T_Break,
    T_Extends, T_This, T_Implements, T_Interface, T_New, T_NewArray,
    T_Identifier, T_StringConstant, T_IntConstant, T_DoubleConstant,
    T_BoolConstant, T_Print, T_ReadInteger, T_ReadLine,
    T_NumTokenTypes
} TokenType;

 
/* The below list is the list of all the names that is used to print when a token is matched with a category
 */
static const char *gTokenNames[T_NumTokenTypes] = {
  "T_Void", "T_Int", "T_Double", "T_Bool", "T_String", "T_Class", "T_Null", "T_Dims",
  "T_LessEqual", "T_GreaterEqual", "T_Equal", "T_NotEqual",
  "T_And", "T_Or", "T_While", "T_For", "T_If", "T_Else", "T_Return",
  "T_Break", "T_Extends", "T_This", "T_Implements", "T_Interface",
  "T_New", "T_NewArray","T_Identifier", "T_StringConstant",
  "T_IntConstant", "T_DoubleConstant", "T_BoolConstant", "T_Print",
  "T_ReadInteger", "T_ReadLine"
};

 

typedef union {
    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1]; 
} YYSTYPE;

 

extern YYSTYPE yylval;

extern char *yytext;      


int yylex();              

void InitScanner();                 
 
#endif