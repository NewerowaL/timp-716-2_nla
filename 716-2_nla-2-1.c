 #include<stdio.h>
 int main()
   {
   int n,i,h,min=0;
   printf("Vvedite kolichestvo chisel:");
   scanf ("%d",&n);
   printf("Vvedite %d chisel:",n);
   scanf ("%d",&min);
       for (i=1;i<n;i++) {
           scanf("%d",&h);
           if (h<min) min=h;
                          }
   printf("%d\n",min);
   return 0;
    }
    

