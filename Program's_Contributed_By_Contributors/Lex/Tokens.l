%{
int tCount = 0;
%}
%%
#.* {tCount++; printf("%s IS A PREPROCESSOR DIRECTIVE.",yytext);}
"main()" {tCount++; printf("\n%s IS A FUNCTION.",yytext);}
"while"|"if"|"else"|"printf"|"void"|"return"|"int"|"float"|"char" {tCount++; printf("%s IS A KEYWORD.\n", yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {tCount++; printf("%s IS AN IDENTIFIER.\n", yytext);}
"<="|"=="|"="|"++"|"-"|"*"|"+" {tCount++; printf("%s IS AN OPERATOR.\n", yytext);}
\".*\" {tCount++; printf("%s IS A STRING.\n",yytext);}
[(){}|,;] {tCount++; printf("%s IS A SEPARATOR.\n", yytext);}
[0-9]*"."[0-9]+ {tCount++; printf("\n%s IS A FLOAT.\n", yytext);}
[0-9]+ {tCount++; printf("\n%s IS AN INTEGER.\n", yytext);}
. ;
%%
int main(){
	yyin=fopen("C.c","r");
	yylex();
	printf("\n======================\nTotal No. Of Token: %d\n======================\n", tCount);
}
int yywrap(){
	return 1;
}
