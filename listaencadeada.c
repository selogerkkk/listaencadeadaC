#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *next;
} node;

void insert(node **list, int value)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->value = value;
  new_node->next = *list;
  *list = new_node;
}

void print(node *list)
{
  while (list != NULL)
  {
    printf("%d ", list->value);
    list = list->next;
  }
  printf("\n");
}

void clear(node *list)
{
  node *atual = list;
  while (atual != NULL)
  {
    node *next = atual->next;
    clear(atual);
    atual = next;
  }
}

int main()
{
  node *list = NULL;
  insert(&list, 1);
  insert(&list, 2);
  insert(&list, 3);
  print(list);
  clear(list);
  return 0;
}
