#include <stdio.h>
#include <conio.h>
#include<stdlib.h>


void main()
{
    char name[100];
    char ch;
    int ans, cnt = 0;
    printf("KBC-programmer 2021");
    printf("\n\n\nPlease Enter Your Name : ");
    gets(name);
    printf("\n\n\nWelcome To KBC-programmer Mr/Ms :");
    puts(name);
    printf("\n\n\nRULES FOR KBC-PROGRAMMER :\n\n\n");
    printf("1.KBC-Programer Stands for 'Kon banega c-programmer' it's c-programing quiz");
    printf("\n\n2.The game consists of 25 Questions");
    printf("\n\n3.Every question consists of 4 options and there will be only one correct answer.");
    printf("\n\n4.For every correct answer you will get 4 points");
    printf("\n\n5.All questions are compulsory.");
    printf("\n\n6.There's not any negative marking for wrong answer but if you give wrong answer you will be exit out of game and the last points will be consider as your final score.");
    printf("\n\n7.Score will be given out of 100.");
    printf("\n\n\nIf you want to start the quiz press ENTER.");
    ch = getch();
    printf("\n\n\nThe Quiz starts now....Best Of Luck   ");
    puts(name);
    //1
    printf("\n\n\n1.Exceptions are caught at ?");
    printf("\n\n1.Compilation Time       2.Run Time");
    printf("\n3.Linking Time           4.Depend on program");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 2)
    {
        printf("\n\nThe answer is corrcet.you got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 0");
        exit(0);
    }
    //2
    printf("\n\n\n2.Logical expression produce______type of result.");
    printf("\n\n1.Explicit               2.Bool");
    printf("\n3.Static                   3.Garbage");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 2)
    {
        printf("\n\nThe answer is corrcet. you got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 4");
        exit(0);
    }
    //3
    printf("\n\n\3.Following in the invalid inclusion of a file to the current program.identify it.");
    printf("\n\n1.#include<file>        2.#include 'file'");
    printf("\n3.#include<file           4.All of the above are invalid.");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 3)
    {
        printf("\n\nThe answer is corrcet.you got  points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got  points=0");
        printf("\nFinal Score : 8");
        exit(0);
    }
    //4
    printf("\n\n\n4.Which header file can be used to define input/output function prototypes and macros?");
    printf("\n\n1.math.h          2.memory.h");
    printf("\n3.stdio.h           4.dos.h");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 3)
    {
        printf("\n\nThe answer is corrcet.you got  points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong.you got  points=0");
        printf("\nFinal Score : 12");
        exit(0);
    }
    //5
    printf("\n\n\n5.To print a float value which format specifier can be used?");
    printf("\n\n1.percentagef          2.percentageif");
    printf("\n3.percentageLf           4.None of the above");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 1)
    {
        printf("\n\nThe answer is corrcet. you got  points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 16");
        exit(0);
    }
    //6
    printf("\n\n\n6.Which is valid C expression?");
    printf("\n\n1.int my_num=100,000;       2.int my_num=100000;");
    printf("\n3.int my num=1000;            4.int $my_num=100000;");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 2)
    {
        printf("\n\nThe answer is corrcet.you got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got  points=0");
        printf("\nFinal Score : 20");
        exit(0);
    }
    //7
    printf("\n\n\n7.What is short int in C programming?");
    printf("\n\n1.The basic data type of C                                 2.Qualifier");
    printf("\n3.short is the qulifier and is the basic data type           4.All of the mentioned");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 3)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 24");
        exit(0);
    }
    //8
    printf("\n\n\n8.Which of the following declaration is not supported by C?");
    printf("\n\n1.string str;            2.char *str");
    printf("\n3.float str=3e2;           4.Both string str; & float str=3e2;");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 1)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 28");
        exit(0);
    }
    //9
    printf("\n\n\n9.Which keyword is used to prevent any changes in the variable within a C proram?");
    printf("\n\n1.immutabl         2.mutable");
    printf("\n3.const              4.volatile");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 3)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 32");
        exit(0);
    }
    //10
    printf("\n\n\n10.Which of the following typecasting is accpted by C?");
    printf("\n\n1.Widening conversions                 2.Narrowing conversions");
    printf("\n3.Widening & Narrowing conversions       4.None of the mentioned");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 3)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 36");
        exit(0);
    }
    //11
    printf("\n\n\n11.Where in C the order of precedence of operators do exist?");
    printf("\n\n1.Within conditional statements,if,else       2.within while,do-while");
    printf("\n3.Within a macro definition                     4.None of the mentioned");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 4)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 40");
        exit(0);
    }
    //12
    printf("\n\n\n12.What is an example of iteration in C?");
    printf("\n\n1.for              2.while");
    printf("\n3.do-while           4.all of the mentioned");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 4)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 44");
        exit(0);
    }
    //13
    printf("\n\n\n13.Functions can return enumeration constants in C?");
    printf("\n\n1.true                            2.false");
    printf("\n3.depends on the compiler           4.depends on the standard");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 1)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 48");
        exit(0);
    }
    //14
    printf("\n\n\n14.Functions in C are always_______");
    printf("\n\n1.Internal                           2.External");
    printf("\n3.Both internal and external           4.External and internal are not valid terms for functions");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 2)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 52");
        exit(0);
    }
    //15
    printf("\n\n\n15.Property which allows to produce different executable for different platforms in C is called?");
    printf("\n\n1.Selective inclusion              2.File inclusion");
    printf("\n3.Conditional compilation            4.Recursive macros");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 3)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 56");
        exit(0);
    }
    //16
    printf("\n\n\n16.What is #include<stdio.h> ?");
    printf("\n\n1.preprocessor directive           2.inclusion directive");
    printf("\n3.File inclusion directive           4.None of the mentioned");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 1)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 60");
        exit(0);
    }
    //17
    printf("\n\n\n17.Which of the following are C preprocessors?");
    printf("\n\n1.#ifdef         2.#define");
    printf("\n3.#endif           4.all of the mentioned");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 4)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 64");
        exit(0);
    }
    //18
    printf("\n\n\n18.The C-preprocessors are specified with_____symbol.");
    printf("\n\n1.#                   2.$");
    printf("\n3."
           "                   4.&");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 1)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 68");
        exit(0);
    }
    //19
    printf("\n\n\n19.Which of the following is not possible statically in C?");
    printf("\n\n1.Jagged Array           2.Rectangular Array");
    printf("\n3.Cuboidal Array           4.Multidimensional Array");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 1)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 72");
        exit(0);
    }
    //20
    printf("\n\n\n20.Which of the following return-type cannot be used for a function in C?");
    printf("\n\n1.char*        2.struct");
    printf("\n3.void           4.none of the mentioned");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 4)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 76");
        exit(0);
    }
    //21
    printf("\n\n\n21.The standard header____is used for variable list arguments(...) in C.");
    printf("\n\n1.<stdio.h>        2.<stdib.h>");
    printf("\n3.<math.h>           4.<stdarg.h>");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 4)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 80");
        exit(0);
    }
    //22
    printf("\n\n\n22.In C language,FILE is of which data type?");
    printf("\n\n1.int          2.char*");
    printf("\n3.struct         4.none of the mentioned");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 3)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 84");
        exit(0);
    }
    //23
    printf("\n\n\n23.What is the sizeof(char) in a 32-bit C compiler?");
    printf("\n\n1.1 bit          2.2 bits");
    printf("\n3.1 Bytes          4.2 Bytes");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 3)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 88");
        exit(0);
    }
    //24
    printf("\n\n\n24.Which of the following is not an operator in C?");
    printf("\n\n1.,        2.sizeof()");
    printf("\n3.~          4.none of the mentioned");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 4)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 92");
        exit(0);
    }
    //25
    printf("\n\n\n25.scanf() is a predefined function in___-header file.");
    printf("\n\n1.stdlib.h     2.ctype.h");
    printf("\n3.stdio.h        4.stdarg.h");
    printf("\n\nEnter your answer: ");
    scanf("%d", &ans);
    if (ans == 3)
    {
        printf("\n\nThe answer is corrcet. You got points=4");
        printf("\n\nCongrats you have scored 100 points.");
    }
    else
    {
        printf("\n\nThe answer is wrong. you got points=0");
        printf("\nFinal Score : 96");
        printf("\nCongrats you only give one wrong answer");
        exit(0);
    }
    getch();
}
