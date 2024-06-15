%{
#include<stdio.h>
%}


%%
if                          {printf("registrovano IF\n");}
then                        {printf("registrovano THEN\n");}
else                        {printf("registrovano ELSE\n");}
continue                    {printf("registrovano CONTINUE\n");}
while                       {printf("registrovano WHILE\n");}
for                         {printf("registrovano FOR\n");}
break                       {printf("registrovano BREAK\n");}
int                         {printf("registrovano INT\n");}
double                      {printf("registrovano DOUBLE\n");}
true                        {printf("registrovano TRUE\n");}   //regularni izraz za boolean konstante
false                       {printf("registrovano FALSE\n");}


[a-zA-Z][a-zA-Z0-9_]{0,30}\b            {printf("registrovan identifikator\n");}//regularni izraz za identifikatore duge 31 karakter,posle 31 karaktera nece registrovati da je identifikator
([0]|[1-9][0-9]*)|(0(x|X)[0-9a-fA-F])   {printf("registrovan integer\n");}//regualarni izraz za cijele brojeve sa decimalnom i heksadecimalnom notacijom
[0-9]+\.[0-9]*([eE]\+[0-9]+)?           {printf("registrovan double\n");}  //regularni izraz za double brojeve
\"([^\"\\]|\\.)*\"                      {printf("registrovan string\n");}  //regularni izraz za stringove
\/\/[^\n]*\n                            {printf("registrovan komentar u jednoj liniji\n");} //regularni izraz za komentare u jednoj liniji 
\/\*([^*]|\*+[^*/])*\*\/                {printf("registrovan multi line komentar");} //regularni izraz za multi line komentare
"+"                                     {printf("registrovan plus\n");}
"-"                                     {printf("registrovan minus\n");}
"*"                                     {printf("registrovan operator mnozenja\n");}
"/"                                     {printf("registrovan operator dijeljenja\n");}
"%"                                     {printf("registrovan procenat\n");}                          
\\                                      {printf("registrovan backslash\n");}
"<"                                     {printf("registrovan znak manje\n");}
"<="                                    {printf("registrovan znak manje ili jednako\n");}
">"                                     {printf("registrovan znak vece\n");} 
">="                                    {printf("registrovan znak vece ili jednako\n");}
"="                                     {printf("registrovan operator dodjeljivanja\n");} 
"=="                                    {printf("registrovan provjera jednakosti\n");}
"!="                                    {printf("registrovana provjera nejednakosti\n");}
"&&"                                    {printf("registrovan operator i\n");}
"||"                                    {printf("registrovan operator ili\n");}
"!"                                     {printf("registrovana negacija\n");}
";"                                     {printf("registrovan tacka zarez\n");}
","                                     {printf("registrovan zarez\n");}
"."                                     {printf("registrovana tacka\n");}
"("                                     {printf("registrovan lijeva zagrada\n");}
")"                                     {printf("registrovan desna zagrada\n");}
[ \n\t\r\f]+                            {printf("registrovana bjelina\n");}
.                                       {}                                         //za svaki slucaj









%%


int main(){
    yylex();
    return 0;
}