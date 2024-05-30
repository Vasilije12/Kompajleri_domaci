%{
#include "Pmf0.tab.h"   
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
%}


%%
let                        { printf("Token LET\n");return LET; }
in                          { printf("Token IN\n");return IN; }
end                         { printf("Token END\n");return END; }
fi                          {printf("Token FI\n");return FI;}
if                          {printf("Token IF\n");return IF;}
then                        {printf("Token THEN\n");return THEN;}
else                        {printf("Token ELSE\n");return ELSE;}
continue                    {printf("Token CONTINUE\n");return CONTINUE;}
while                       {printf("Token WHILE\n");return WHILE;}
for                         {printf("Token FOR\n");return FOR;}
break                       {printf("Token BREAK\n");return BREAK;}
int                         {printf("Token INT\n");return INT;}
double                      {printf("Token DOUBLE\n");return DOUBLE;}
true                        {printf("Token TRUE\n");return T_TRUE;}   //regularni izraz za boolean konstante
false                       {printf("Token FALSE\n");return T_FALSE;}
string                      {printf("Token STRING\n");return STRING;}
do                          {printf("Token DO\n");return DO;}
read                        {printf("Token READ\n");return READ;}
write                       {printf("Token WRITE\n");return WRITE;}


[a-zA-Z][a-zA-Z0-9_]*            {printf("Token: T_ID(%s)\n", yytext);yylval.ident=(char*)strdup(yytext);//bio je problem {0.30}\b
                                        return T_ID;}//regularni izraz za identifikatore duge 31 karakter,posle 31 karaktera nece registrovati da je identifikator
([0]|[1-9][0-9]*)|(0(x|X)[0-9a-fA-F])   {yylval.int_value=atoi(yytext);
                                            return T_INT;}//regualarni izraz za cijele brojeve sa decimalnom i heksadecimalnom notacijom
[0-9]+\.[0-9]*([eE]\+[0-9]+)?           {yylval.double_value=strtod(yytext,NULL);
                                        return T_DOUBLE;}  //regularni izraz za double brojeve
\"([^\"\\]|\\.)*\"                      {yylval.string_value=(char*)strdup(yytext);
                                        return T_STRING;}  //regularni izraz za stringove
\/\/[^\n]*\n                            {} //regularni izraz za komentare u jednoj liniji 
\/\*([^*]|\*+[^*/])*\*\/                {} //regularni izraz za multi line komentare
"+"                                     {printf("Token: T_PLUS\n");return T_PLUS;}
"-"                                     {return T_MINUS;}
"*"                                     {return T_MNOZENJE;}
"/"                                     {return T_DIJELJENJE;}
"%"                                     {return T_MOD;}                          
\\                                      {return T_BACKSLASH;}
"<"                                     {return T_MANJE;}
"<="                                    {return T_MANJE_JEDNAKO;}
">"                                     {return T_VECE;} 
">="                                    {return T_VECE_JEDNAKO;}
"="                                     {printf("Token Dodjele\n");return T_DODJELE;} 
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


