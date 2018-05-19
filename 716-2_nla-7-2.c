#include <stdio.h>
#include <stdlib.h>
void shellsort(int m[], int n,int *sr,int *p)
{
    int i, j, k, tmp;
    for (i = n / 2; i > 0; i = i / 2)
    {
        for (j = i; j < n; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {	(*sr)++;
                if (m[k+i] >= m[k])
                    break;
		 else
                {(*sr)++;

                    tmp = m[k];
                    m[k] = m[k+i];
                    m[k+i] = tmp;(*p)++; 
                }
            }
        }
    }
}
int main() {
        int sr,p;
        int g;
        scanf("%d",&g);
        double srSr=0,srPr=0;
       // for(int ch=0;ch<100;ch++){

        int n=g;
        sr=0,p=0;
        int m[n];

        for(int i=0;i<n;i++) {m[i]=n-i; } 

     shellsort(m,n,&sr,&p);
for(int i=0;i<n;i++){ printf("%d ", m[i]); }//отсортированный массив
printf("\n");
printf("Sravneniy: %d\n",sr);
printf("Perestanovok: %d\n",p);
srSr+=sr;
srPr+=p;
//}
srSr=srSr/100;
srPr=srPr/100;
//printf("Srednee Sravn: %.0f\n",srSr);
//printf("Srednee Perest: %.2f\n",srPr);
return 0        ;
}


