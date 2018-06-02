%{
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "yystruct.hpp"
#include "output.hpp"
#include "parser.tab.hpp"

using namespace std;
void showError();
void yyerror(const char*);

%}

%option yylineno
%option noyywrap

ID					[a-zA-Z][a-zA-Z0-9]*
NUM					0|[1-9][0-9]*
STRING				\"([^\n\r\"\\]|\\[rnt"\\])+\"
whitespace			[\n\r\t ]
comment				\/\/[^\r\n]*[ \r|\n|\r\n]?

%x bk_comment

%%

"void"				{yylval.type = string("VOID"); return VOID;}
"int"				{yylval.type = string("INT"); return INT;}
"byte"				{yylval.type = string("BYTE"); return BYTE;}
"b"					{return B;}
"bool"				{yylval.type = string("BOOL"); return BOOL;}
"and"				{return AND;}
"or"				{return OR;}
"not"				{return NOT;}
"true"				{yylval.type = string("BOOL"); return TRUE;}
"false"				{yylval.type = string("BOOL"); return FALSE;}
"return"			{return RETURN;}
"if"				{yylval.line = yylineno; return IF;}
"else"				{return ELSE;}
"while"				{yylval.line = yylineno; return WHILE;}
"switch"			{yylval.line = yylineno; return SWITCH;}
"case"				{return CASE;}
"break"				{return BREAK;}
"default"			{return DEFAULT;}
":"					{return COLON;}
";"					{return SC;}
","					{return COMMA;}
"("					{return LPAREN;}
")"					{return RPAREN;}
"{"					{return LBRACE;}
"}"					{return RBRACE;}
"="					{return ASSIGN;}

"/*"				{ BEGIN(bk_comment); }
<bk_comment>"*/"	{ BEGIN(0); }
<bk_comment>"/*"	{ showError(); }
<bk_comment>.|\n		;

"=="|"!="|"<"|">"|"<="|">="	{yylval.lexeme = string(yytext); return RELOP;}

"+"					{yylval.lexeme = string(yytext); return PLUS;}
"-"					{yylval.lexeme = string(yytext); return MINUS;}
"*"					{yylval.lexeme = string(yytext); return MULT;}
"/"					{yylval.lexeme = string(yytext); return DIV;}		
{ID}				{yylval.name = string(yytext); return ID;}
{STRING}			{yylval.type = string("STRING"); yylval.lexeme = string(yytext); return STRING;}
{NUM}				{
						yylval.type = string("INT");
						yylval.lexeme = string(yytext);
						yylval.val = atoi(yytext);
						return NUM;
					}
{whitespace}		;
{comment}			;
<<EOF>>				{return EOF_TOKEN;}
.					showError();


%%

void showError() {
	output::errorLex(yylineno);
	exit(1);
}
