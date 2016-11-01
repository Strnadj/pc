#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cur_position = 0;

char get_next(char *text) {
  size_t size = strlen(text);
  char ret;

  while (size > cur_position && ((int) text[cur_position]) == 32) {
    cur_position++;
  }

  if (size <= cur_position) {
    return 'E';
  }

  ret = text[cur_position];

  cur_position++;

  return ret;
}

int main(void) {
  stack *new;
  int run, x, y;
  char next;
  char input[] = "5 7 + 9 1 + *";

  new = createstack(10, sizeof(int));

  run = 1;
  while(run) {
    next = get_next(input);
    switch(next) {
      case '+':
        pop(new, &(x));
        pop(new, &(y));
        x += y;
        push(new, &(x));
        break;

      case '-':
        pop(new, &(x));
        pop(new, &(y));
        x = y - x;
        push(new, &(x));
        break;

      case '*':
        pop(new, &(x));
        pop(new, &(y));
        x = y * x;
        push(new, &(x));
        break;

      case 'E':
        run = 0;
        break;

      default:
        x = ((int) next) - 48;
        push(new, &(x));
    }
  }

  // if stack size > 1 (overeni ze vstup byl validni)
  pop(new, &(x));
  printf("Vysledek: %d\n", x);

  delete_stack(&new);

  return 0;
}
