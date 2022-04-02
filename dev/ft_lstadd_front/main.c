#include <stdio.h>
 
int main () {

   int  var;
   int  *ptr;
   int  **pptr;

   var = 3000;

   /* take the address of var */
   ptr = &var;

   /* take the address of ptr using address of operator & */
   pptr = &ptr;

   /* take the value using pptr */
   printf("%lu\n",sizeof(int**));
   printf("Value of var = %d\n", var );
   printf("Value available at *ptr = %d\n", *ptr );
   printf("Value available at **pptr = %d\n", **pptr);
   printf("adress of pptr = %p\n", &pptr);
   printf("adress of ptr = %p\n", pptr);
   printf("value in *pptr = %p\n", *pptr);
   printf("address of num = %p\n", ptr);
  

   return 0;
}