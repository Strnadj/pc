#ifndef TREE_H
#define TREE_H

struct NODE {
  int val;
  struct NODE *lft, *rgt;
};

typedef struct NODE node;

void add_node(node **top, int val);
//remove_node(node **top, int val);
node * find_node(node **top, int val);
void print_tree(node **top);
void remove_tree(node **top);

#endif
