#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int value;
    int key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} node;

int yrv=0;

//Инициализация
node* init(int key, int value)
{
// Выделение памяти под корень дерева
    node *tmp = malloc(sizeof(node));
// Присваивание значения ключу
    tmp -> value = value;
    tmp -> key = key;
// Присваивание указателю на родителя значения NULL
    tmp -> parent = NULL;
// Присваивание указателю на левое и правое поддерево значения NULL
    tmp -> left = NULL;
    tmp -> right = NULL;
         
    return tmp;
}

//Добавляем узел
void add(node* root, int key, int value)
{

	while(1)
	{
		if (root->key==key)
		{
			root->value=value;
			break;
		}
		
		if (key>root->key)
		{
			if (root->right==NULL)
			{
				node *tmp = malloc(sizeof(node));
				root->right = tmp;
				tmp->key=key;
				tmp->value=value;
				tmp->parent=root;
				break;
			}
			else
			{
				root=root->right;
				continue;
			}
		}
		
		if (key<root->key)
		{
			if (root->left==NULL)
			{
				node *tmp = malloc(sizeof(node));
				root->left = tmp;
				tmp->key=key;
				tmp->value=value;
				tmp->parent=root;
				break;
			}
			else
			{
				root=root->left;
				continue;
			}
		}
    }
}

//Найдём нужный узел
int search(node* root, int key)
{
yrv++;
// Если дерево пусто или ключ корня равен искомому ключу, то возвращается указатель на корень
	if (root==NULL)
		return -1;	
		
	if (root -> key == key)
		return root->value;

// Поиск нужного узла
    if (key < root -> key)
        return search(root -> left, key);
    else return search(root -> right, key);
}

//Вывод дерева
void print(node *root)
{
    if (root == NULL)
        return;
    if (root -> key)
        printf("%d ", root -> key);
    print(root -> left);
    print(root -> right);
}

int main()
{
  int n, key, value;
  scanf ("%d", &n);
  scanf("%d", &key);
  scanf("%d", &value);
  node *root = init(key, value);
  for (int i=1; i<n; i++)
 {
           scanf("%d", &key);
           scanf("%d", &value);
           add (root, key, value);
        }
        for (int i=0; i<3; i++)
        {
        int temp=0;
        	yrv=-1;
                scanf("%d", &key);
                temp=search(root,key);
                if (temp!=-1)
                	printf("%d ", yrv);
                printf("%d", temp);
                
                printf ("\n");
        }
}

