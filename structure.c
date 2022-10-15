
// program to display the marks of students using structures

#include<stdio.h>


int main(){
    struct marks
{
    char name[30];
    char subject[20];
    float marks;
    int mobile;
};

    struct marks stud[3];
    int n,i;
    printf("Number of students: ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        printf("Enter details of %d : \n",i+1);
        printf("Name: ");
        scanf("%s",stud[i].name);
        printf("Subject: ");
        scanf("%s",stud[i].subject);
        printf("Marks: ");
        scanf("%f",&stud[i].marks);
        printf("Mobile no: ");
        scanf("%d",&stud[i].mobile);
    }
    for (i = 0; i < n; i++)
    {
        printf("Mark sheet data of %d: ",i+1);
        printf("Name:%s  Subject:%s  Marks:%f  Mobile:%d \n",stud[i].name,stud[i].subject,stud[i].marks,stud[i].mobile);
    }
    
    
}

/* OUTPUT
Number of students: 3
Enter details of 1 : 
Name: HARSHED
Subject: MATHS
Marks: 99
Mobile no: 8802017910
Enter details of 2 : 
Name: ATHUL 
Subject: GRAPHICS 
Marks: 99
Mobile no: 3942342324
Enter details of 3 : 
Name: JAZIM
Subject: PROBABILITY
Marks: 95
Mobile no: 2342389492
Mark sheet data of 1: Name:HARSHED  Subject:MATHS  Marks:99.000000  Mobile:598085578 
Mark sheet data of 2: Name:ATHUL  Subject:GRAPHICS  Marks:99.000000  Mobile:-352624972
Mark sheet data of 3: Name:JAZIM  Subject:PROBABILITY  Marks:95.000000  Mobile:-1952577804

*/