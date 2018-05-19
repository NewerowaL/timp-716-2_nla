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

//Инициализация
node* create(int key, int value)
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


/*ПРЯМОЙ ОБХОД*/
 void Show(node* root)
{if(root) {
printf("%d",root->value); //Посетили узел
    if (root->left!=NULL)
    Show(root->left); //Обошли правое поддерево
    if (root->right!=NULL)
    Show(root->right); //Обошли левое поддерево
}
}
int main()
{
  int n, key, value;
  scanf ("%d", &n);
  scanf("%d", &key);
  scanf("%d", &value);
  node *root = create(key, value);
  for (int i=1; i<n; i++)
 {
           scanf("%d", &key);
           scanf("%d", &value);
           add (root, key, value);
        }
        Show(root);
        printf ("\n");
        }







