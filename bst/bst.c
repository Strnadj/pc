#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define BUFF_SIZE 50

int load_int() {
  char buff[BUFF_SIZE];
  fgets(buff, BUFF_SIZE, stdin);
  return atoi(buff);
}

int get_operation() {
  printf("Zadejte vstup:\n[1] Vypisete strom\n[2] Pridate uzel\n[3] Konec\n");
  printf("Zadejte hodnotu: ");
  return load_int();
}

int get_value() {
  printf("Zadejte hodnotu uzlu: ");
  return load_int();
}

int main(void) {
  int operation = 0, val = 0;
  node *top = NULL;

  while((operation = get_operation()) != 3) {
    switch(operation) {
      case 1:
        print_tree(&top);
        break;

      case 2:
        val = get_value();
        add_node(&top, val);
        break;

      default:
        printf("-> Chybny vstup\n");
        break;
    }
  }

  return 0;
}
