#include<stdio.h>

int main()
{
  int a[1000006] ,b[1000006], j, i, t;
  scanf("%d",&t);

  for(i = 1; i <= t; i++) {
      scanf("%d",&b[i]);
  }

  for(i = 1; i <= t; i++) {
      a[b[i]]++;
  }

  for(j = 1; j < 1000006; j++) {
      while(a[j]--) {
          printf("%d\n", j);
      }
  }

  return 0;
}
