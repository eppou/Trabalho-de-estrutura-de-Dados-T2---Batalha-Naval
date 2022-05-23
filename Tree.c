#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct root_tree{
  double fd;
  node_tree root;
  int size_tree;
  int size_tree_r;
}tree;

typedef struct node_tree{
  double x;
  double y;
  node_tree parent;
  node_tree left;
  node_tree center;
  node_tree rifgt;
}node_tree;
