#include <stdlib.h>
#include <stdio.h>

typedef struct node { //Объявляем структуру и говорим что это будет тип "node"
	int value;
	struct node *next;
	struct node *prev;
} node;

node *head=NULL; //Указатель на голову
node *tail=NULL; //Указатель на хвост

int isEmpty() //Проверка списка на пустоту
{ 
	if ((head==NULL)&&(tail==NULL)) //Проверяем что head и tail равны NULL
		return 1; //Если верно => список пустой (его не существует)
	else
		return 0; //Если неверно => список не пустой (есть, как минимум, один элемент) 
} 

node *find_node_num(int k) //Поиск адреса по которому лежит k-ый элемент
{

	node *tmp = head; //Начинаем с головы
	
	for (int i=1;i<k;i++) //Ищем адрес k-го элемента
	{
		tmp=tmp->next; //Берём адрес следующего элемента
		if (tmp==NULL) //Проверяем существование следующего элемента
			break; //Если следующего элемента нет, то цикл закрывается и функция вернёт NULL
	}

	return tmp; //Если k-ый элемент найден - функция вернёт адрес элемента
				//Если k-го элемента нет, то функция вернёт NULL
}

node *find_node_val(int k) //Поиск адреса, по которому лежит элемент со значением k
{

	node *tmp = head; //Начинаем с головы
	
	while (tmp != NULL && tmp->value != k) //Проверяем что текущий адрес не NULL и
										   //значение элемента не равно искомому
	{
		tmp=tmp->next; //Берём адрес следующего элемента
	}
	
	return tmp; //Если нашли нужный элемент - вернётся его адрес
				//Если не нашли - вернётся NULL
}

void init (int value) //Инициализация списка
{
	node *tmp = malloc(sizeof(node));
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	head = tmp;
	tail = tmp;
}

void add (int val) //Добавление элементов в список
{
	if (isEmpty()==1) //Проверка необходимости инициализации списка
		init (val);
	else
	{
		node *tmp = malloc(sizeof(node)); 
		tmp->value=val; 
		tmp->prev=tail; 
		tmp->next=NULL; 
		tail=tmp; 
		tmp->prev->next=tmp; 
	}
}

void add_end(int num, int data) //Добавление элемента после текущего
{
	node *tmp = find_node_num(num); //Ищем адрес нужного элемента
	
	if (tmp==NULL||tmp==tail)
	//Если элемент с нужным номером не существует или это последний элемент списка
	{
		node *temp = malloc(sizeof(node));
		temp->value=data;
		temp->next=NULL;
		temp->prev=tail;
		temp->prev->next=temp;
		tail=temp;
	}
	else
	{
	//Если текущий элемент лежит где-то в середине списка
		node *temp = malloc(sizeof(node));
		temp->value=data;
		temp->next=tmp->next;
		temp->prev=tmp;
		tmp->next->prev=temp;
		tmp->next=temp;	
	}	
}

void add_pend(int num, int data) //Добавление элемента перед текущим
{ 
	node *tmp = find_node_num(num);
	if (tmp==NULL||tmp==head) 
	{
	//Если элемент не существует или это первый элемент списка
		node *temp = malloc(sizeof(node));
		temp->value=data; 
		temp->prev=NULL; 
		temp->next=head; 
		head=temp; 
		temp->next->prev=temp;
	}
	else
	{
	//Если элемент лежит где-то в середине списка
		node *temp = malloc(sizeof(node));
		temp->value=data;
		temp->prev=tmp->prev;
		temp->next=tmp;
		tmp->prev=temp;
		temp->prev->next=temp;	
	}	 
} 


 
void get_out() //Вывод содержимого списка
{ 
	node *tmp=head; 
 
	printf("%i",tmp->value); 
	while (tmp->next!=NULL) 
	{ 
		tmp=tmp->next; 
		printf(" ");
		printf("%i",tmp->value); 
	}
	printf("\n");
} 

void destroy() // Удаление всего списка
{
	if (isEmpty()==0)
	{
		node *tmp=head;
		node *temp=NULL;
		do{
			temp=tmp->next;
			free(tmp);
			tmp=temp;
		}while (tmp!=NULL);
		head=NULL;
		tail=NULL;
	}
}

void remove_node(node *tmp) //Удаление конкретного элемента списка (по адресу)
{
	int no_op=0; //Флаг отсутствия операций
	
	if (tmp==NULL) //Если элемент и так не существует
		no_op = 1;
	
	if (tmp==head && tmp==tail && no_op==0) //Если элемент единственный в списке
	{
		destroy();
		no_op=1;
	}
		
	if (tmp==head && no_op==0)//Если элемент первый в списке
	{
		head=tmp->next;
		tmp->next->prev=NULL;
		free(tmp);
		no_op=1;
	}
	
	if(tmp==tail && no_op==0)//Если элемент последний в списке
	{
		tail=tmp->prev;
		tmp->prev->next=NULL;
		free(tmp);
		no_op=1;
	}
	
	if (tmp!=head && tmp!=head && no_op==0)//Если элемент где-то в середине списка
	{
		tmp->next->prev=tmp->prev;
		tmp->prev->next=tmp->next;
		free(tmp);
		no_op=1;
	}

	
}

int main()
{
	int n=0;
	int val=0;
	int k=0; 

	scanf("%i",&n); 
	
	for (int i=0;i<n;i++) 
	{ 
		scanf ("%i", &val); 
		add(val); 
	} 

	if (isEmpty()==0)
		get_out();
		
	scanf("%i",&k);
	remove_node(find_node_num(k));

	if (isEmpty()==0)
		get_out();
	
	scanf("%i",&k);
	
	remove_node(find_node_val(k));
	
	if (isEmpty()==0)
		get_out();
		
	scanf ("%i",&k);
	scanf ("%i", &val);
	
	add_end(k,val);
	
	if (isEmpty()==0)
		get_out();
		
	scanf ("%i",&k);
	scanf ("%i", &val);
	
	add_pend(k,val);	
	
	if (isEmpty()==0)
		get_out();
		
	destroy();
	
	return 0; 
}



