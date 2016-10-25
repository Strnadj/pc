#include <stdio.h>

void swap(int **a, int **b) {
  int *tmp = NULL;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(void) {
  int a = 5, b = 6;
  int *aa, *bb;

  printf("Pred: %d, %d\n", a, b);

  aa = &a;
  bb = &b;

  printf("hodnoty: %d, %d\n", *aa, *bb);

  swap(&(aa), &(bb));

  printf("Po: %d, %d\n", a, b);
  printf("hodnoty: %d, %d\n", *aa, *bb);

  return 0;
}
