#include <stdio.h>
#include <string.h>

void parser(char * str){
    // Variable to track whether we are inside the tag
    int in=0; 
    int index=0;
    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i]=='<'){
            in =1; 
            continue;
        }
        else if(str[i]=='>'){
               in =0;
               continue;
        }
        if (in==0)
        {
            str[index]=str[i];
            index++;
        }
    }    
        str[index]='\0';
        //Removing Spaces From Both Sides
        while(str[0]==' ')
        {
            //shift the string to left
            for (int j = 0; j < strlen(str); j++)
            {
               str[j]=str[j+1];
            }  
        }
        while (str[strlen(str)-1]==' ')
        {
            str[strlen(str)-1]='\0';
        }        
}



int main(){
    char str[]="<h1> hello brother </h1>";
    parser(str);
    printf("After passing %s is",str);

   return 0;
}