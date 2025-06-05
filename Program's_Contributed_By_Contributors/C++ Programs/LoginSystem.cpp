#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void login();
void registration();
void forgot();

int main(){
    int c; //choice 
    cout<<"\t\t\t\t\t\t__________________________________________________\n\n";
    cout<<"\t\t\t\t\t\t            Welcome to the login page      \n\n\n";
    p:
    cout<<"\t\t\t\t\t\t        _______       Menu       _______\n\n";
    cout<<"                                  \n";
    cout<<"\t\t\t\t|  Press 1 to Login                        |\n";
    cout<<"\t\t\t\t|  Press 2 to Register                     |\n";
    cout<<"\t\t\t\t|  Press 3 if you forgot your password     |\n";
    cout<<"\t\t\t\t|  Press 4 to Exit!                        |\n";
    cout<<"\n\t\t\t Please enter your choice : ";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"\t\t Thank You🙏🫂\n\n";
            // exit();
            break;
        default:
            system("cls");// for clearing screen
            cout<<"\t\t please select from given option . \n\n";
            // main(); 
            goto p;
    }
}

void login(){
    int count ;
    string userid,password,id,pass;
    system("cls");
    cout<<"\t\t Please enter the user name and password : " <<endl;
    cout<<"\t\t\t USENAME ";
    cin>>userid;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;


    //checking given user name and password are alredy exist or not
    //ifstream is used for read the data
    ifstream input("records.txt"); //input object name
    while(input>>id>>pass){//reading that if that id and password is there and then we match them with id and password given by user
        if(id==userid && pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<userid<<"\n Your LOGIN is successful \n";
        cout<<"\t\t Thanks for loggin in ! \n ";
        main();
    }else{
        cout<<"\t\t\n **LOGIN ERROR** \n Please check you username and password ! and Try Again :) \n ";
        main();
        // goto p;
    }

}


void registration(){
    string reguserId,regpassword,regid,regpass;
    system("cls");
    cout<<"\t\t\n For new account Enter the username : ";
    cin>>reguserId;
    cout<<" Enter the password : ";
    cin>>regpassword;

    //to write in the file
    ofstream  f1("records.txt",ios::app); //app open the file and append the output in the end 
     f1<<reguserId<<' '<<regpassword<<' '<<endl;
     system("cls");
     cout<<"\t\t\t Registration is successfull !\n";
     main();

}
void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\nYou forgot the password no worries :\n";
    cout<<"\t\t Press 1 to search your id by username "<<endl;
    cout<<"\t\t Press 2 to go back to main menu "<<endl;
    cout<<"\t\t Enter your choice : ";
    cin>>option;
    switch(option){
        case 1:{
            int count=0;
            string suserid,sid,spass;
            cout<<"\n\t\t Enter the user name you remembered : ";
            cin>>suserid;
            ifstream f2("records.txt");
            while(f2>>sid>>spass){
                if(sid==suserid){
                    count=1;
                }
            }
            f2.close();

            if(count==1){
                cout<<"\t\t\n\n Your account is found ! \n";
                cout<<"\n\n Your password is : "<<spass<<endl;
                main();
            }
            else{
                cout<<"\n\t\t Sorry! your account is not found .\n";
                main();
            }
            break;
        }
        case 2:{
            main();
        }
        default :
            cout<<" \t\t\t Wrong ! please try again  "<<endl;
            forgot();

            
    }
}
