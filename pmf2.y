%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <stdbool.h>

// AST struktura
typedef struct ASTNode {
    int nodetype;
    struct ASTNode *left;
    struct ASTNode *right;
    union {
        int int_value;
        double double_value;
        char* string_value;
        char* ident;
        char* decl;
        int bool_value;
    } value;
} ASTNode;

ASTNode *newNode(int nodetype, ASTNode *left, ASTNode *right);
ASTNode *newIntNode(int int_value);
ASTNode *newDoubleNode(double double_value);
ASTNode *newStringNode(char *string_value);
ASTNode *newIdentNode(char *ident);
ASTNode *newDeclNode(char *decl);
void printAST(ASTNode *node, int level);

void yyerror(const char* s);

// Funkcije za kreiranje čvorova
ASTNode *newNode(int nodetype, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->nodetype = nodetype;
    node->left = left;
    node->right = right;
    return node;
}

ASTNode *newIntNode(int int_value) {
    ASTNode *node = newNode('I', NULL, NULL);
    node->value.int_value = int_value;
    return node;
}

ASTNode *newDoubleNode(double double_value) {
    ASTNode *node = newNode('D', NULL, NULL);
    node->value.double_value = double_value;
    return node;
}

ASTNode *newStringNode(char *string_value) {
    ASTNode *node = newNode('S', NULL, NULL);
    node->value.string_value = strdup(string_value);
    return node;
}

ASTNode *newIdentNode(char *ident) {
    ASTNode *node = newNode('V', NULL, NULL);
    node->value.ident = strdup(ident);
    return node;
}

ASTNode *newDeclNode(char *decl){
    ASTNode *node = newNode('M',NULL,NULL);
    node->value.decl = strdup(decl);
}

// Funkcija za ispisivanje AST stabla
void printAST(ASTNode *node, int level) {
    if (node == NULL) return;
    int i;
    for ( i = 0; i < level; i++) printf("  ");
    switch (node->nodetype) {
        case 'I': printf("Int: %d\n", node->value.int_value); break;
        case 'D': printf("Double: %f\n", node->value.double_value); break;
        case 'S': printf("String: %s\n", node->value.string_value); break;
        case 'V': printf("Ident: %s\n", node->value.ident); break;
        //case 'i':printf("If\n");break;
        //case 'e':printf("Else:\n");break;
        //case "==": printf("Op:%s\n",node->nodetype); break;
        case ';':break;
        
        case '+': case '-': case '*': case '/': case '%':
        case '<': case '>': case '=': case '!': case '&': case '|':
        
            printf("Op: %c\n", node->nodetype); break;
        default: printf("Kljucna rijec: %c\n", node->nodetype);
    }
    //nekako da se dodaje u neki niz sve sto je na istom nivou i onda da se printa
   
    printAST(node->left, level +1);
    printAST(node->right, level +1);
}
%}
%union{
    int int_value;
    double double_value;
    char* string_value;
    char* ident;
    int bool_value;
    ASTNode *node;
}

%start program
%token IF
%token <node>THEN
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

%type <node> program dekl sekv_komandi komanda if_statement else_blok while_statement int_exp double_exp string_exp

%%

program: LET dekl IN sekv_komandi END {
                                        printAST($4, 0);  }
;

dekl : dekl INT T_ID T_SC { $$ = newNode(';', $1, newDeclNode("INT")); }
     | dekl DOUBLE T_ID T_SC {  }
     | dekl STRING T_ID T_SC {  }
     | { $$ = NULL; }
;

sekv_komandi: sekv_komandi komanda { $$ = newNode(';', $1, $2); }
            | { $$ = NULL; }
;

komanda : T_ID T_DODJELE int_exp T_SC { $$ = newNode('=', newIdentNode($1), $3);  }
        | int_exp T_SC { $$ = $1; }
        | T_ID T_DODJELE double_exp T_SC { $$ = newNode('=', newIdentNode($1), $3); }
        | double_exp T_SC { $$ = $1; }
        | string_exp T_SC { $$ = $1; }
        | T_ID T_DODJELE string_exp T_SC { $$ = newNode('=', newIdentNode($1), $3); }
        | if_statement { $$ = $1; }
        | while_statement { $$ = $1; }
        | READ T_ID T_SC { $$ = newNode('R', newIdentNode($2), NULL); }
        | WRITE int_exp T_SC { $$ = newNode('W', $2, NULL); }
        | WRITE double_exp T_SC { $$ = newNode('W', $2, NULL); }
        | WRITE string_exp T_SC { $$ = newNode('W', $2, NULL); }
;

if_statement: IF int_exp THEN sekv_komandi else_blok FI { $$ = newNode('i', $2,newNode('t',$4,$5)); }
            | IF double_exp THEN sekv_komandi else_blok FI { $$ = newNode('i', $2, newNode('k', NULL, $4)); }
;

else_blok: ELSE sekv_komandi { $$ = $2; }
        | { $$ = NULL; }
;

while_statement: WHILE int_exp DO sekv_komandi END { $$ = newNode('w', $2, $4); }
                | WHILE double_exp DO sekv_komandi END { $$ = newNode('w', $2, $4); }
;

int_exp : int_exp T_PLUS int_exp { $$ = newNode('+', $1, $3);  }
        | int_exp T_MINUS int_exp { $$ = newNode('-', $1, $3); }
        | int_exp T_MNOZENJE int_exp { $$ = newNode('*', $1, $3); }
        | int_exp T_DIJELJENJE int_exp { $$ = newNode('/', $1, $3); }
        | int_exp T_MOD int_exp { $$ = newNode('%', $1, $3); }
        | int_exp T_VECE int_exp { $$ = newNode('>', $1, $3); }
        | int_exp T_VECE_JEDNAKO int_exp { $$ = newNode('G', $1, $3); }
        | int_exp T_MANJE int_exp { $$ = newNode('<', $1, $3); }
        | int_exp T_MANJE_JEDNAKO int_exp { $$ = newNode('L', $1, $3); }
        | int_exp T_JEDNAKOSTI int_exp { $$ = newNode('Q', $1, $3); }
        | int_exp T_NEJEDNAKOSTI int_exp { $$ = newNode('!', $1, $3); }
        | T_NOT int_exp { $$ = newNode('!', $2, NULL); }
        | T_INT { $$ = newIntNode($1);  }
        | T_ID { $$ = newIdentNode($1);  }
;

double_exp : double_exp T_PLUS double_exp { $$ = newNode('+', $1, $3);  }
        | double_exp T_MINUS double_exp { $$ = newNode('-', $1, $3); }
        | double_exp T_MNOZENJE double_exp { $$ = newNode('*', $1, $3); }
        | double_exp T_DIJELJENJE double_exp { $$ = newNode('/', $1, $3); }
        | double_exp T_MOD double_exp { $$ = newNode('%', $1, $3); }
        | double_exp T_VECE double_exp { $$ = newNode('>', $1, $3); }
        | double_exp T_VECE_JEDNAKO double_exp { $$ = newNode('G', $1, $3); }
        | double_exp T_MANJE double_exp { $$ = newNode('<', $1, $3); }
        | double_exp T_MANJE_JEDNAKO double_exp { $$ = newNode('L', $1, $3); }
        | double_exp T_JEDNAKOSTI double_exp { $$ = newNode('=', $1, $3); }
        | double_exp T_NEJEDNAKOSTI double_exp { $$ = newNode('!', $1, $3); }
        | T_NOT double_exp { $$ = newNode('!', $2, NULL); }
        | T_DOUBLE { $$ = newDoubleNode($1);  }
;

string_exp: T_STRING { $$ = newStringNode($1); }
;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    int res = yyparse();
    return res == 0 ? 0 : 1;
}
