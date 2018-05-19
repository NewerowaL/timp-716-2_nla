#include <stdio.h>
#include <stdlib.h>

void siftDown(int *n, int root, int b,int *sr,int *p)
{
  int max; // индекс максимального потомка
  int done = 0; 
  while ((root * 2 <= b) && (!done)) 
  {
    if (root * 2 == b)     
      max = root * 2;    
    else if (n[root * 2] > n[root * 2 + 1])
      max = root * 2;
    else
      max = root * 2 + 1;
   
    if (n[root] < n[max]) 
    {(*sr++);
      int temp = n[root]; // меняем их местами
      n[root] = n[max];
      n[max] = temp;
      root = max;(*p)++;
    }
    else{(*sr++);
 
      done = 1;} // пирамида сформирована
  }
}
// Функция сортировки 
void heapSort(int *n, int array_size,int *sr,int *p) 
{
 
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(n, i, array_size,sr,p);
  
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = n[0];
    n[0] = n[i];
    n[i] = temp;
    siftDown(n, 0, i - 1,sr,p);
  }
}
int main()
{
  int *a;
    int sr,p,n;
     scanf("%d",&n);
double srSr=0,srPr=0;
 for(int ch=0;ch<100;ch++){
        sr=0,p=0;
        a  =  (int *)calloc(n, sizeof(int));

    for (int i = 0;i<n;i++)
    {
        a[i]=rand()%(2*n)+1; 
    }
  heapSort(a,n,&sr,&p); // вызов функции сортировки
  // Вывод элементов массива после сортировки
for(int i=0;i<n;i++){ printf("%d ", a[i]); }//отсортированный массив
printf("\n");
printf("Sravneniy: %d\n",sr);
printf("Perestanovok: %d\n",p);
srSr+=sr;
srPr+=p;
free(a);
}
srSr=srSr/100;
srPr=srPr/100;

printf("Srednee Sravn: %.2f\n",srSr);
printf("Srednee Perest: %.2f\n",srPr);
return 0        ;
}
