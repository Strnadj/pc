#ifndef _STACK_H
#define _STACK_H

struct STACK {
  int stack_size;
  int item_count;
  int item_len;
  void *data;
};

typedef struct STACK stack;

stack *createstack(int size, int itemlen);
void delete_stack(stack **field);
void push(stack *s, void *data);
void pop(stack *s, void *data);

#endif
