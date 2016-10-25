#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

node * find_node(node **top, int val) {
  node *tmp = *top;

  while(tmp != NULL) {
    if (tmp->val == val) {
      return tmp;
    } else if(val > tmp->val) {
      tmp = tmp->rgt;
    } else {
      tmp = tmp->lft;
    }
  }

  return NULL;
}

void add_node(node **top, int val) {
  node *tmp = NULL, *iterator = *top;

  // Zkusi uzel najit
  tmp = find_node(top, val);

  // Pokud existuje => nic nedelat
  if (tmp != NULL) return;

  // Vytvorim uzel
  tmp = malloc(sizeof(node));
  if (tmp == NULL) return;

  tmp->val = val;
  tmp->rgt = tmp->lft = NULL;

  // Strom je prazdny
  if (*top == NULL) {
    *top = tmp;
  } else {
    while(((iterator->val > val) && iterator->lft != NULL) ||
        ((iterator->val < val) && iterator->rgt != NULL)) {
      if (iterator->val > val) {
        iterator = iterator->lft;
      } else {
        iterator = iterator->rgt;
      }
    }

    if (iterator->val > val) {
      iterator->lft = tmp;
    } else {
      iterator->rgt = tmp;
    }
  }
}

void print_rec(node *tmp) {
  if (tmp == NULL) return;
  print_rec(tmp->lft);
  printf("%d\n", tmp->val);
  print_rec(tmp->rgt);
}

void print_tree(node **top) {
  print_rec(*top);
}

void remove_tree(node **top) {

}
