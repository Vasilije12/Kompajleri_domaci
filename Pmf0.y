%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h> 
    #include <stdbool.h>


    void yyerror(const char* s);
    //treba da napravim tabelu simbola
    //za to mi treba struct koji podrzava vise tipova promenljivih




    


    
%}

%union{
    int int_value;
    double double_value;
    char* string_value;
    char* ident;
    int bool_value;
    

}

%start program
%token IF
%token THEN
%token ELSE
%token CONTINUE
%token WHILE
%token FOR
%token BREAK
%token INT
%token DOUBLE
%token STRING
%token T_TRUE
%token T_FALSE
%token <ident>T_ID
%token <int_value>T_INT
%token <double_value>T_DOUBLE
%token <string_value>T_STRING
%token T_PLUS
%token T_MINUS
%token T_MNOZENJE
%token T_DIJELJENJE
%token T_MOD
%token T_BACKSLASH
%token T_MANJE
%token T_MANJE_JEDNAKO
%token T_VECE
%token T_VECE_JEDNAKO
%token T_DODJELE
%token T_JEDNAKOSTI
%token T_NEJEDNAKOSTI
%token T_AND
%token T_OR
%token T_NOT
%token T_SC
%token T_ZAREZ
%token T_TACKA
%token T_DESNAZ
%token T_LIJEVAZ
%token LET IN END FI 
%token DO
%token READ WRITE



%nonassoc T_DODJELE
%left T_AND T_OR
%nonassoc T_JEDNAKOSTI T_NEJEDNAKOSTI
%nonassoc T_MANJE T_MANJE_JEDNAKO T_VECE T_VECE_JEDNAKO
%left T_PLUS T_MINUS
%left T_MNOZENJE T_DIJELJENJE T_MOD
%right T_NOT

%type <int_value> int_exp



%%

program:LET dekl IN sekv_komandi END {printf("Uspjesno\n");} 
        
;

dekl : dekl INT T_ID T_SC {printf("Deklaracija int varijable\n");}
     | dekl DOUBLE T_ID T_SC {}
     | dekl STRING T_ID T_SC {}
     | {}
;

sekv_komandi: sekv_komandi komanda {}
            |    {}
;

komanda : T_ID T_DODJELE int_exp T_SC {printf("Dodjela uspjesna\n");}
        | int_exp T_SC {}
        | T_ID T_DODJELE double_exp T_SC {}
        | double_exp T_SC {}
        | string_exp T_SC {}
        | T_ID T_DODJELE string_exp T_SC {}
        | if_statement {}
        | while_statement{}
        | READ T_ID T_SC{}
        | WRITE int_exp T_SC{}
        | WRITE double_exp T_SC{}
        | WRITE string_exp T_SC{}
        
;

if_statement: IF int_exp THEN sekv_komandi else_blok FI{}
             |IF double_exp THEN sekv_komandi else_blok FI{}
            
;
else_blok: ELSE sekv_komandi{}
        | {}
;
while_statement:WHILE int_exp DO sekv_komandi END{}
                |WHILE double_exp DO sekv_komandi END{}
;

int_exp :  T_LIJEVAZ int_exp T_DESNAZ {}
        |int_exp T_PLUS int_exp {printf("Int exp: plus\n");}
        | int_exp T_MINUS int_exp {}
        | int_exp T_MNOZENJE int_exp {}
        | int_exp T_DIJELJENJE int_exp {}
        | int_exp T_MOD int_exp {}
        | int_exp T_VECE int_exp {}
        | int_exp T_VECE_JEDNAKO int_exp {}
        | int_exp T_MANJE int_exp {}
        | int_exp T_MANJE_JEDNAKO int_exp {}
        | int_exp T_JEDNAKOSTI int_exp {}
        | int_exp T_NEJEDNAKOSTI int_exp {} //treba promijeniti kad budemo ubacivali akcije
        | T_NOT int_exp {}
        | T_INT  {printf("Int exp: int %d\n", $1);}
        | T_ID {printf("Vracen ID\n");}
;
double_exp :  T_LIJEVAZ double_exp T_DESNAZ {}
        |double_exp T_PLUS double_exp {printf("Int exp: plus\n");}
        | double_exp T_MINUS double_exp {}
        | double_exp T_MNOZENJE double_exp {}
        | double_exp T_DIJELJENJE double_exp {}
        | double_exp T_MOD double_exp {}
        | double_exp T_VECE double_exp {}
        | double_exp T_VECE_JEDNAKO double_exp {}
        | double_exp T_MANJE double_exp {}
        | double_exp T_MANJE_JEDNAKO double_exp {}
        | double_exp T_JEDNAKOSTI double_exp {}
        | double_exp T_NEJEDNAKOSTI double_exp {} //treba promijeniti kad budemo ubacivali akcije
        | T_NOT double_exp {}
        | T_DOUBLE  {printf("Int exp: int %d\n", $1);}
        
        
;        

string_exp: T_STRING {}
;

     


%%

void yyerror(const char* s){
    fprintf(stderr, "Error: %s\n", s);
}


int main(){
    int res = yyparse();
    if(res==0){
        printf("0");
    }else{
        printf("1");
    }
    return 0;
}
