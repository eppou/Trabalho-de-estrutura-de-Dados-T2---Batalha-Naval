#include "lista.h"


typedef struct node_t {
  void *data;
  struct node_t *prev;
  struct node_t *next;
  char sel[2]; //char para definir se o elemento esta ou não selecioonado
} no_lista;


typedef struct {
  int size;
  no_lista *first;
  no_lista *last;
} lista_deg;

void *inicia() 
{
  lista_deg *list = (lista_deg *) malloc(sizeof(lista_deg));
  list->size = 0;
  list->first = NULL;
  list->last = NULL;
  return list;
}

void *inicia_no(void *data) 
{
  no_lista *node = (no_lista*)malloc(sizeof(no_lista));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  strcpy(node->sel,"n");
  return (node);
}


void *procura_no(void *lista, int pos) 
{
  lista_deg *list = (lista_deg*)malloc(sizeof(lista_deg));
  list = (lista_deg*)lista;
  if(pos > list->size)
    return NULL;  

  no_lista *currNode;
  int currPos;
  int reverse; 
 
  if(pos > ((list->size-1) / 2)) {
    reverse  = 1;
    currPos  =  list->size - 1;
    currNode =  list->last;
  } else {
    reverse  = 0;
    currPos  = 0;
    currNode =  list->first;
  }  
  while(currNode != NULL) {
  

    if(currPos==pos){
      break;
    }
    if(reverse==1){
      currNode=currNode->prev;
      currPos= currPos-1;
    }
    if(reverse==0){
      currNode=currNode->next;
      currPos= currPos+1;
    }
  }
  void *ptrCurrNode;
  ptrCurrNode=currNode;
  return (ptrCurrNode);
}

void *aux_remove(void *list, int pos) 
{
  void *currNode = procura_no(list, pos);
  void *data = NULL;

  if(currNode == NULL)
    return NULL;

  data = ((no_lista*)currNode)->data;

  if(((no_lista*)currNode)->prev == NULL) 
     ((lista_deg*)list)->first = ((no_lista*)currNode)->next;
  else {
    ((no_lista*)currNode)->prev->next = ((no_lista*)currNode)->next;
  }
  if(((no_lista*)currNode)->next == NULL)
    ((lista_deg*)list)->last = ((no_lista*)currNode)->prev; 
  else
    ((no_lista*)currNode)->next->prev = ((no_lista*)currNode)->prev;

   ((lista_deg*)list)->size--;
  free(currNode);
  return(data);
}

int lista_inserenofim(void *list, void *data) 
{
  /* inicia um novo nó */
  void *newNode = inicia_no(data);

  /* se a lista está vazia */
  if( ((lista_deg*)list)->size == 0) {
     ((lista_deg*)list)->first = (no_lista*)newNode;
  } 
  else {
  
     ((lista_deg*)list)->last->next = (no_lista*)newNode;
    ((no_lista*)newNode)->prev =  ((lista_deg*)list)->last;
  }
   ((lista_deg*)list)->last = (no_lista*)newNode;
   ((lista_deg*)list)->size++;
  return 0;
}




void *lista_pop(void *list) 
{
  if(!list)
    return NULL;

  no_lista *node = ((lista_deg*)list)->first;
  if(node == NULL)
    return NULL;

  void *data = node->data;

  if(aux_remove(list, 0) == NULL)
    return NULL;

  return data;
}

int returnlistsize(void *lista){
  lista_deg *List = (lista_deg*)malloc(sizeof(lista_deg));
  List = (lista_deg*)lista;
  return(List->size);

}

void *returnData (void *list,int pos){
  void *ptrCurrNode;
  ptrCurrNode = procura_no(list,pos);
  void *ptrCurrNodeData;
  ptrCurrNodeData= ((no_lista*)ptrCurrNode)->data;
  return (ptrCurrNodeData);
}

