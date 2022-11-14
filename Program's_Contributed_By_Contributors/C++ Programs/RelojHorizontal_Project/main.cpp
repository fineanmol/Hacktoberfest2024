#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int minut=00,
    segun=00;
int horaDiv[4];

void delay(){
    for(int i = (time(0) + 1); time(0) != i; time(0) );
}

void Imprimir(int m, int s){
    horaDiv[0] = (minut/10); //Toma el Primer digito de los minutos y lo guarda en la posicion 0
    horaDiv[1] = (minut%10); //Toma el Segundo digito de los minutos y lo guarda en la posicion 1
    horaDiv[2] = (segun/10); //Toma el Primer digito de los Segundos y lo guarda en la posicion 2
    horaDiv[3] = (segun%10); //Toma el Segundo digito de los Segundos y lo guarda en la posicion 3
    /*
    Al separarlos de esta forma podemos hacer que se vallan imprimiendo en la posicion correcta
    segun la vuelta que valla dando el ciclo en su fila y columna; ejemplo: en la primera condicion
    Imprime la primera linea de arriba de todos los numeros; vemos en la condicion que pregunta
    si esta en la primera fila y en la primera columna osea la fila y columna cero; tengase en cuenta
    que aqui cada digito es una columna.
    */
    for(int i = 0; i < 5; i++){ //Ciclo de cambio de fila
        for(int x = 0; x < 4; x++){ //ciclo de cambio de fila
            if(i==0 && x==0){ //Columna 1 y fila 1
                if(horaDiv[x]==0 || horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==5 || horaDiv[x]==7 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==4){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==6){
                    cout<<horaDiv[x]<<"  \t";
                }
            }
            else if(i==0 && x==1){ //Columna 2 y fila 1
                if(horaDiv[x]==0 || horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==5 || horaDiv[x]==7 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==4){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==6){
                    cout<<horaDiv[x]<<"  \t";
                }
            }
            /*else if(i==0 && x==2){
                cout<<"**\t";
            }*/
            else if(i==0 && x==2){ //columna 3 y fila 1
                if(horaDiv[x]==0 || horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==5 || horaDiv[x]==7 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==4){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==6){
                    cout<<horaDiv[x]<<"  \t";
                }
            }
            else if(i==0 && x==3){ //columna 4 y ultima por ser 4 digitos y fila 1
                if(horaDiv[x]==0 || horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==5 || horaDiv[x]==7 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==4){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==6){
                    cout<<horaDiv[x]<<"  \t";
                }
            }

            if(i==1 && x==0){
                if(horaDiv[x]==0 || horaDiv[x]==4 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==7){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==5 || horaDiv[x]==6){
                    cout<<horaDiv[x]<<"  \t";
                }
            }
            else if(i==1 && x==1){
                if(horaDiv[x]==0 || horaDiv[x]==4 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==7){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==5 || horaDiv[x]==6){
                    cout<<horaDiv[x]<<"  \t";
                }
            }
            /*else if(i==1 && x==2){
                cout<<"**\t";
            }*/
            else if(i==1 && x==2){
                if(horaDiv[x]==0 || horaDiv[x]==4 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==7){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==5 || horaDiv[x]==6){
                    cout<<horaDiv[x]<<"  \t";
                }
            }
            else if(i==1 && x==3){
                if(horaDiv[x]==0 || horaDiv[x]==4 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==7){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==5 || horaDiv[x]==6){
                    cout<<horaDiv[x]<<"  \t";
                }
            }

            if(i==2 && x==0){
                if(horaDiv[x]==0){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2 || horaDiv[x]==4 || horaDiv[x]==5 || horaDiv[x]==6 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==3 || horaDiv[x]==7){
                    cout<<" "<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
            }
            else if(i==2 && x==1){
                if(horaDiv[x]==0){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2 || horaDiv[x]==4 || horaDiv[x]==5 || horaDiv[x]==6 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==3 || horaDiv[x]==7){
                    cout<<" "<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
            }
            /*else if(i==2 && x==2){
                cout<<"  \t";
            }*/
            else if(i==2 && x==2){
                if(horaDiv[x]==0){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2 || horaDiv[x]==4 || horaDiv[x]==5 || horaDiv[x]==6 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==3 || horaDiv[x]==7){
                    cout<<" "<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
            }
            else if(i==2 && x==3){
                if(horaDiv[x]==0){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2 || horaDiv[x]==4 || horaDiv[x]==5 || horaDiv[x]==6 || horaDiv[x]==8 || horaDiv[x]==9){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==3 || horaDiv[x]==7){
                    cout<<" "<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
            }

            if(i==3 && x==0){
                if(horaDiv[x]==0 || horaDiv[x]==6 || horaDiv[x]==8){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2){
                    cout<<horaDiv[x]<<"  \t";
                }
                else if(horaDiv[x]==3 || horaDiv[x]==4 || horaDiv[x]==5 || horaDiv[x]==7 || horaDiv[x]==9){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
            }
            else if(i==3 && x==1){
                if(horaDiv[x]==0 || horaDiv[x]==6 || horaDiv[x]==8){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2){
                    cout<<horaDiv[x]<<"  \t";
                }
                else if(horaDiv[x]==3 || horaDiv[x]==4 || horaDiv[x]==5 || horaDiv[x]==7 || horaDiv[x]==9){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
            }
            /*else if(i==3 && x==2){
                cout<<"**\t";
            }*/
            else if(i==3 && x==2){
                if(horaDiv[x]==0 || horaDiv[x]==6 || horaDiv[x]==8){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2){
                    cout<<horaDiv[x]<<"  \t";
                }
                else if(horaDiv[x]==3 || horaDiv[x]==4 || horaDiv[x]==5 || horaDiv[x]==7 || horaDiv[x]==9){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
            }
            else if(i==3 && x==3){
                if(horaDiv[x]==0 || horaDiv[x]==6 || horaDiv[x]==8){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2){
                    cout<<horaDiv[x]<<"  \t";
                }
                else if(horaDiv[x]==3 || horaDiv[x]==4 || horaDiv[x]==5 || horaDiv[x]==7 || horaDiv[x]==9){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
            }
            else if(i==3 && x==4){
                if(horaDiv[x]==0 || horaDiv[x]==6 || horaDiv[x]==8){
                    cout<<horaDiv[x]<<" "<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==2){
                    cout<<horaDiv[x]<<"  \t";
                }
                else if(horaDiv[x]==3 || horaDiv[x]==4 || horaDiv[x]==5 || horaDiv[x]==7 || horaDiv[x]==9){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
            }

            if(i==4 && x==0){
                if(horaDiv[x]==0 || horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==5 || horaDiv[x]==6 || horaDiv[x]==8){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==4 || horaDiv[x]==7 || horaDiv[x]==9){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
            }
            else if(i==4 && x==1){
                if(horaDiv[x]==0 || horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==5 || horaDiv[x]==6 || horaDiv[x]==8){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==4 || horaDiv[x]==7 || horaDiv[x]==9){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
            }
            /*else if(i==4 && x==2){
                cout<<"**";
            }*/
            else if(i==4 && x==2){
                if(horaDiv[x]==0 || horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==5 || horaDiv[x]==6 || horaDiv[x]==8){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==4 || horaDiv[x]==7 || horaDiv[x]==9){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
            }
            if(i==4 && x==3){
                if(horaDiv[x]==0 || horaDiv[x]==2 || horaDiv[x]==3 || horaDiv[x]==5 || horaDiv[x]==6 || horaDiv[x]==8){
                    cout<<horaDiv[x]<<horaDiv[x]<<horaDiv[x]<<"\t";
                }
                else if(horaDiv[x]==1){
                    cout<<" "<<horaDiv[x]<<" \t";
                }
                else if(horaDiv[x]==4 || horaDiv[x]==7 || horaDiv[x]==9){
                    cout<<"  "<<horaDiv[x]<<"\t";
                }
            }


        }
        cout<<endl;
    }
}

int main()
{
    srand(time(0));

    while(1){
            Imprimir(minut, segun);
            delay();
            segun++;
            if(segun==60){
                segun=00;
                minut++;
            }
            system("cls");
    }
    /*while(1){
        cout<<minut<<" "<<segun;
        delay();
        segun++;
        if(segun==60){
                segun=00;
                minut++;
            }
        system("cls");
    }*/

    return 0;
}
