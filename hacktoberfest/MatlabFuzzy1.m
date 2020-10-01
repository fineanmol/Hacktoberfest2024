clc
clear 
close all

UA=0:0.1:10
UC=10000: 100:50000
UP=0:0.1:30


% Atencion de la mesera/o
AM=FuncGauss(UA,0,2.5);
AR=FuncGauss(UA,5,2.5)
AB=FuncGauss(UA,7.5,2.5)
AMB=FuncGauss(UA,10,2.5)
% Costo del plato
CB=FuncGauss(UC,10000,10700)
CN=FuncGauss(UC,30000,10700)
CC=FuncGauss(UC,40000,10700)
CMC=FuncGauss(UC,50000,10700)
% Salida Propina
PP=FuncGauss(UP,0,10)
PM=FuncGauss(UP,15,7)
PA=FuncGauss(UP,30,10)


figure(1)
subplot(3,1,1)
plot(UA,AM,UA,AB,UA,AR,UA,AMB)
title('Atencion')
grid on
subplot(3,1,2)
plot(UC,CB,UC,CC,UC,CN,UC,CMC)
title('Costo Plato')
grid on
subplot(3,1,3)
plot(UP,PP,UP,PM,UP,PA)
title('Propina')
grid on

%  Entradas del sistema 

A=0
C=50000

A_M=FuncGauss(A,0,2.5)
A_R=FuncGauss(A,5,2.5)
A_B=FuncGauss(A,7.5,2.5)
A_MB=FuncGauss(A,10,2.5)
C_B=FuncGauss(C,10000,10700)
C_N=FuncGauss(C,30000,10700)
C_C=FuncGauss(C,40000,10700)
C_MC=FuncGauss(C,50000,10700)

% Regla 1 Mala y Barato
R1=min(A_M,C_B)
R1=min(R1,PP)

% Regla 2 mala y normal
R2=min(A_M,C_N)
R2=min(R2,PP)

% Regla 3 mala y costosa
R3=min(A_M,C_C)
R3=min(R3,PP)

% Regla 4 mala y muy costosa
R4=min(A_M,C_MC)
R4=min(R4,PP)


% Regla 5 regular y Barato
R5=min(A_R,C_B)
R5=min(R5,PP)

% Regla 6 regular y normal
R6=min(A_R,C_N)
R6=min(R6,PP)

% Regla 7 regular y costosa
R7=min(A_R,C_C)
R7=min(R7,PP)

% Regla 8 regular y muy costosa
R8=min(A_R,C_MC)
R8=min(R8,PP)


% Regla 9 BUENA y Barato
R9=min(A_B,C_B)
R9=min(R9,PA)

% Regla 10 BUENA y normal
R10=min(A_B,C_N)
R10=min(R2,PA)

% Regla 11 BUENA y costosa
R11=min(A_B,C_C)
R11=min(R3,PM)

% Regla 12 BUENA y muy costosa
R12=min(A_B,C_MC)
R12=min(R12,PM)


% Regla 13 MUY BUENA y Barato
R13=min(A_MB,C_B)
R13=min(R13,PA)

% Regla 14 MUY BUENA y normal
R14=min(A_MB,C_N)
R14=min(R14,PA)

% Regla 15 MUY BUENA y costosa
R15=min(A_MB,C_C)
R15=min(R15,PA)

% Regla 16 MUY BUENA y muy costosa
R16=min(A_MB,C_MC)
R16=min(R16,PM)


Salida=max(R16,max(R15,max(R14,max(R13,max(R12,max(R11,max(R10,max(R9,max(R8,max(R7,max(R6,max(R5,max(R4,max(R3,max(R1,R2)))))))))))))));


figure(2)
subplot(4,4,1)
plot(UP,PP,UP,R1)
subplot(4,4,2)
plot(UP,PP,UP,R2)
subplot(4,4,3)
plot(UP,PP,UP,R3)
subplot(4,4,4)
plot(UP,PP,UP,R4)
subplot(4,4,5)
plot(UP,PP,UP,R5)
subplot(4,4,6)
plot(UP,PP,UP,R6)
subplot(4,4,7)
plot(UP,PP,UP,R7)
subplot(4,4,8)
plot(UP,PP,UP,R8)
subplot(4,4,9)
plot(UP,PA,UP,R9)
subplot(4,4,10)
plot(UP,PA,UP,R10)
subplot(4,4,11)
plot(UP,PM,UP,R11)
subplot(4,4,12)
plot(UP,PM,UP,R12)
subplot(4,4,13)
plot(UP,PA,UP,R13)
subplot(4,4,14)
plot(UP,PA,UP,R14)
subplot(4,4,15)
plot(UP,PA,UP,R15)
subplot(4,4,16)
plot(UP,PM,UP,R16)

figure(3)
plot(UP,Salida)

SaldaFinal=sum(Salida.*UP)/sum(Salida)


% Superficie de control
UA=0:0.1:10
UC=10000: 100:50000
x=0;
y=0;
for A=0:0.1:10
    x=x+1;
    y=0;
    for C=10000:100:50000
        y=y+1;
A_M=FuncGauss(A,0,2.5);
A_R=FuncGauss(A,5,2.5);
A_B=FuncGauss(A,7.5,2.5);
A_MB=FuncGauss(A,10,2.5);
C_B=FuncGauss(C,10000,10700);
C_N=FuncGauss(C,30000,10700);
C_C=FuncGauss(C,40000,10700);
C_MC=FuncGauss(C,50000,10700);

% Regla 1 Mala y Barato
R1=min(A_M,C_B);
R1=min(R1,PP);

% Regla 2 mala y normal
R2=min(A_M,C_N);
R2=min(R2,PP);

% Regla 3 mala y costosa
R3=min(A_M,C_C);
R3=min(R3,PP);

% Regla 4 mala y muy costosa
R4=min(A_M,C_MC);
R4=min(R4,PP);


% Regla 5 regular y Barato
R5=min(A_R,C_B);
R5=min(R5,PP);

% Regla 6 regular y normal
R6=min(A_R,C_N);
R6=min(R6,PP);

% Regla 7 regular y costosa
R7=min(A_R,C_C);
R7=min(R7,PP);

% Regla 8 regular y muy costosa
R8=min(A_R,C_MC);
R8=min(R8,PP);


% Regla 9 BUENA y Barato
R9=min(A_B,C_B);
R9=min(R9,PA);

% Regla 10 BUENA y normal
R10=min(A_B,C_N);
R10=min(R2,PA);

% Regla 11 BUENA y costosa
R11=min(A_B,C_C);
R11=min(R3,PM);

% Regla 12 BUENA y muy costosa
R12=min(A_B,C_MC);
R12=min(R12,PM);


% Regla 13 MUY BUENA y Barato
R13=min(A_MB,C_B);
R13=min(R13,PA);

% Regla 14 MUY BUENA y normal
R14=min(A_MB,C_N);
R14=min(R14,PA);

% Regla 15 MUY BUENA y costosa
R15=min(A_MB,C_C);
R15=min(R15,PA);

% Regla 16 MUY BUENA y muy costosa
R16=min(A_MB,C_MC);
R16=min(R16,PM);



Salida=max(R16,max(R15,max(R14,max(R13,max(R12,max(R11,max(R10,max(R9,max(R8,max(R7,max(R6,max(R5,max(R4,max(R3,max(R1,R2)))))))))))))));

SalidaFinal=sum(Salida.*UP)/sum(Salida);

Superficie(x,y)=SalidaFinal;

    end
end

figure(4)
surf(Superficie)