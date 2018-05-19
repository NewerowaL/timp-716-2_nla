#include<stdio.h>
 int main()
  {
   int n,i,a,b;
   printf("Vvedite kolichestvo chisel:");
   scanf ("%d",&n);
   printf("1 = ");
   scanf("%d", &b); 
         for (i=2;i<=n;i++)
           {    
              printf("%d = ",i);
              a=b; 
              scanf("%d", &b);
                  
              if (b > a)
                 {
                  printf ("0\n");
                  break;
                  }
            } 
          if(i==n+1) printf("1\n");  
          return 0;
   }



