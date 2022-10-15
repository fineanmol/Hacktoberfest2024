

#include <stdio.h>

int main()

{

int nilai;

printf(“Input Nilai\t:”);

scanf(“%i”, &nilai);

if(nilai >= 80 && nilai <=100)

{

printf(“Grade nilai\t: Sangat Baik”);

}

else if(nilai >= 70 && nilai <=79)

{

printf(“Grade nilai\t: Baik”);

}

else if(nilai >= 60 && nilai <=69)

{

printf(“Grade nilai\t: Cukup”);

}

else if(nilai >= 50 && nilai <=59)

{

printf(“Grade nilai\t: Kurang”);

}

else

{

printf(“Grade nilai\t: Gagal”);

}

return 0;

}
