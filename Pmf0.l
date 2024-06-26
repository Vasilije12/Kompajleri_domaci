%{
#include "Pmf0.tab.h"   
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
%}


%%
let                        { return LET; }
in                          { return IN; }
end                         { return END; }
fi                          {return FI;}
if                          {return IF;}
then                        {return THEN;}
else                        {return ELSE;}
continue                    {return CONTINUE;}
while                       {return WHILE;}
for                         {return FOR;}
break                       {return BREAK;}
int                         {return INT;}
double                      {return DOUBLE;}
true                        {return T_TRUE;}   //regularni izraz za boolean konstante
false                       {return T_FALSE;}
string                      {return STRING;}
do                          {return DO;}
read                        {return READ;}
write                       {return WRITE;}


[a-zA-Z][a-zA-Z0-9_]*            {yylval.ident=(char*)strdup(yytext);//bio je problem {0.30}\b
                                        return T_ID;}//regularni izraz za identifikatore duge 31 karakter,posle 31 karaktera nece registrovati da je identifikator
([0]|[1-9][0-9]*)|(0(x|X)[0-9a-fA-F])   {yylval.int_value=atoi(yytext);
                                            return T_INT;}//regualarni izraz za cijele brojeve sa decimalnom i heksadecimalnom notacijom
[0-9]+\.[0-9]*([eE]\+[0-9]+)?           {yylval.double_value=strtod(yytext,NULL);
                                        return T_DOUBLE;}  //regularni izraz za double brojeve
\"([^\"\\]|\\.)*\"                      {yylval.string_value=(char*)strdup(yytext);
                                        return T_STRING;}  //regularni izraz za stringove
\/\/[^\n]*\n                            {} //regularni izraz za komentare u jednoj liniji 
\/\*([^*]|\*+[^*/])*\*\/                {} //regularni izraz za multi line komentare
"+"                                     {return T_PLUS;}
"-"                                     {return T_MINUS;}
"*"                                     {return T_MNOZENJE;}
"/"                                     {return T_DIJELJENJE;}
"%"                                     {return T_MOD;}                          
\\                                      {return T_BACKSLASH;}
"<"                                     {return T_MANJE;}
"<="                                    {return T_MANJE_JEDNAKO;}
">"                                     {return T_VECE;} 
">="                                    {return T_VECE_JEDNAKO;}
"="                                     {return T_DODJELE;} 
"=="                                    {return T_JEDNAKOSTI;}
"!="                                    {return T_NEJEDNAKOSTI;}
"&&"                                    {return T_AND;}
"||"                                    {return T_OR;}
"!"                                     {return T_NOT;}
";"                                     {return T_SC;}
","                                     {return T_ZAREZ;}
"."                                     {return T_TACKA;}
"("                                     {return T_LIJEVAZ;}
")"                                     {return T_DESNAZ;}

[ \n\t\r\f]+                            {}
.                                       {}                                         //za svaki slucaj









%%


