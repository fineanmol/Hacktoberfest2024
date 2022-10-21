#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
char s[max];
int top=-1;
void push(char data);
char pop();
int pre(char data);
int main()
{
    char a[max],r1,r2;
    int i,l,k1,k2;
    scanf("%s", &a);
    l=strlen(a);
    for(i=0;i<l;i++)
    {
        if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='('||a[i]==')'||a[i]=='^')
        {
            if(top==-1)
            {
                push(a[i]);
            }
            else
            {
                if(a[i]=='(')
                {
                    push(a[i]);
                }
                else if(a[i]!=')')
                {
                    k1=pre(a[i]);
                    k2=pre(s[top]);
                    if(s[top]=='(')
                    {
                        push(a[i]);
                    }
                    else if(k1>k2)
                    {
                        push(a[i]);
                    }
                    else
                    {
                        while(top!=-1&&k2>=k1)
                        {
                            if(s[top]=='(')
                            {
                                break;
                            }
                            printf("%c", pop());
                            k2=pre(s[top]);
                        }
                        push(a[i]);
                    }
                }
                else if(a[i]==s[top]&&s[top]=='^')
                {
                    push(a[i]);
                }
                else
                {
                    r2=pop();
                    while(r2!='(')
                    {
                        printf("%c", r2);
                        r2=pop();
                    }
                }
            }
        }
        else
        {
            printf("%c", a[i]);
        }
    }
    for(i=top;i!=-1;i--)
    {
        printf("%c", pop());
    }
    printf("\n");
}
int pre(char data)
{
    if(data=='^')
    {
        return 3;
    }
    else if(data=='*'||data=='/')
    {
        return 2;
    }
    else if(data=='+'||data=='-')
    {
        return 1;
    }
    else if(data=='(')
    {
        return 4;
    }
}
void push(char data)
{
    if(top==max-1)
    {
        printf("Stack overflow\n");
    }
    top++;
    s[top]=data;
}
char pop()
{
    char k;
    if(top==-1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    k=s[top];
    top=top-1;
    return k;
}
