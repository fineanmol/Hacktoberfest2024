#include <iostream>
 
int main()
{
   unsigned int n = 1;
   char *c = (char*)&n;
   
   if (*c)   
       std::cout << "LITTLE ENDIAN";
   else
       std::cout << "BIG ENDIAN";
   
   return 0;
}
