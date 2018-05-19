#include <stdio.h>
#include <stdlib.h>
// Функция быстрой сортировки
void quickSort(int *n, int left, int right,int *sr,int *p)
{
  int pp; 
  int l_hold = left; //левая граница
  int r_hold = right; // правая граница
  pp = n[left];
  while (left < right) // пока границы не сомкнутся

  {(*sr)++;
    while ((n[right] >= pp) && (left < right))
      right--;

    if (left != right) 
    {
      n[left] = n[right];(*p)++;  
      left++;  
    }
    while ((n[left] <= pp) && (left < right))
      left++;
    if (left != right) // если границы не сомкнулись
    { 
      n[right] = n[left]; // перемещаем элемент [left] на место [right]
      right--;(*p)++;  // сдвигаем правую границу вправо 
    }
  }
  n[left] = pp; 
  pp = left;
  left = l_hold;
  right = r_hold;
  if (left <pp) // Рекурсивно вызываем сортировку для левой и правой части массива
  {
  quickSort(n, left, pp - 1,sr,p);}
  if (right > pp){
    quickSort(n, pp + 1, right,sr,p);}
}
int main()
{
  int *a;
    int sr,p,n;
     scanf("%d",&n);
double srSr=0,srPr=0;
//        for(int ch=0;ch<100;ch++){
	sr=0,p=0; 
	a  =  (int *)calloc(n, sizeof(int));

    for (int i = 0;i<n;i++)
    {
        a[i]=i+1;
    }
  quickSort(a,0,n,&sr,&p); // вызов функции сортировки
  // Вывод элементов массива после сортировки
for(int i=0;i<n;i++){ printf("%d ", a[i]); }//отсортированный массив
printf("\n");
printf("Sravneniy: %d\n",sr);
printf("Perestanovok: %d\n",p);
srSr+=sr;
srPr+=p;
free(a);
//}
srSr=srSr/100;
srPr=srPr/100;

//printf("Srednee Sravn: %.2f\n",srSr);
//printf("Srednee Perest: %.2f\n",srPr);
return 0        ;
}

