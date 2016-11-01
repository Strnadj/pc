#include "stack.h"
#include <stdlib.h>

stack *createstack(int size, int item_len) {
  stack *tmp;

  // [stack *] = (stack *)[void *](malloc)
  tmp = (stack *) malloc(sizeof(stack));

  if (tmp == NULL) {
    return NULL;
  }

  tmp->item_len = item_len;
  tmp->stack_size = size;
  tmp->item_count = -1;

  tmp->data = malloc(size * item_len);

  if (tmp->data == NULL) {
    free(tmp);
    return NULL;
  }

  return tmp;
}

void push(stack *s, void *data) {
  char *charData = (char *) data;
  int i = 0, start_index;

  s->item_count++; // Aktualni volne misto

  start_index = s->item_count * s->item_len;

  for (i = 0; i < s->item_len; i++) {
    ((char *) s->data)[start_index + i] = charData[i];
  }
}

void pop(stack *s, void *d) {
  int i = 0, start_index;

  start_index = s->item_count * s->item_len;

  for (i = 0; i < s->item_len; i++) {
    ((char *) d)[i] = ((char *) s->data)[start_index + i];
  }

  s->item_count--;
}

void delete_stack(stack **field) {
  stack *tmp = *field;

  if (tmp != NULL) {
    free(tmp->data);
    free(tmp);
    *field = NULL;
  }
}
