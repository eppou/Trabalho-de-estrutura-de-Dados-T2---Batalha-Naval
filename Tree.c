#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

typedef struct root_tree{
  double fd;
  node_tree *root;
  int size_tree;
  int size_tree_r;
}tree_struc;

typedef struct node_tree{
  void *data; 
  double x;
  double y;
  node_tree *parent;
  node_tree *left;
  node_tree *center;
  node_tree *right;
  int targetremoved; //USAR BOOL?
  //0 para não removido e 1 para removido?
}node_tree;

XyyTree createTree(double Fd) // não entendi mt bem o fator de degradação
{
  tree_struc *new_tree = (tree_struc*)malloc(sizeof(tree_struc));
  new_tree->root = NULL;
  new_tree->size_tree = 0;
  new_tree->size_tree_r = 0;
  new_tree->fd = Fd; //?
  
  return new_tree;
}


Node InsertElement(XyyTree tree, Info info, double x, double y)
{
    tree_struc *tree_aux = (tree_struc*)tree;
    node_tree **aux = &tree_aux->root;

    node_tree *node = (node_tree*)malloc(sizeof(node_tree));

      node->data = info;
      node->x= x;
      node->y = y;
      node->parent = NULL;
      node->left = NULL;
      node->right = NULL;
      node->center = NULL;
      node->targetremoved = 0;

  if(tree_aux->root == NULL) // inserir na raiz
  {
    tree_aux->root = node;
  }
  else{
    while(*aux)
    {
      node->parent = *aux;
      if(x < (*aux)->x)
      {
        aux = &(*aux)->left;
      }
      else if(x >= (*aux)->x)
      {
        if(y < (*aux)->y)
        {
          aux = &(*aux)->center;
        }
        else if(y >= (*aux)->y)
        {
          aux = &(*aux)->right;
        }
       }
      }
     }
    *aux = node;
    tree_aux->size_tree++;
}


Node getNodeXyyT (XyyTree t, double x, double y, double epsilon){

  tree_struc *tree_aux = (tree_struc*)t;
  node_tree *aux = tree_aux->root;

  if(aux->x - x < epsilon && aux->y - y < epsilon || aux==NULL)
  {
    return aux;
  }

  if(x < aux->x)
  {
    return getNodeXyyT(tree_aux->root->left, x, y, epsilon);
  }
  else if(y < aux->y)
  {
    return getNodeXyyT(tree_aux->root->center, x, y, epsilon);
  }
  else if(y >= aux->y)
  {
    return getNodeXyyT(tree_aux->root->right, x, y, epsilon);
  }

  
}

Info getInfoXyyT (XyyTree t, Node n)
{
  node_tree *aux = (node_tree*)n;
  return aux->data;
}
