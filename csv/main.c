#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define BUFF_SIZE 256

size_t arrayPos = 0;
student *array[1000];

void free_mem() {
  size_t i = 0;

  for (i = 0; i < arrayPos; i++) {
    free(array[i]);
  }
}

int parse_line(char buff[]) {
  student *tmp = NULL;
  char *pch;

  tmp = malloc(sizeof(student));

  if (tmp == NULL) {
    printf("Chyba alokace\n");
    return -1;
  }

  // Ziskame osobni cislo
  pch = strtok(buff, ";");
  strncpy(tmp->id, pch, STUDENT_ID_SIZE - 1);
  tmp->id[STUDENT_ID_SIZE - 1] = '\0';

  // Vlozim do pole
  array[arrayPos] = tmp;
  arrayPos++;

  // Preskocim katedru
  pch = strtok(NULL, ";");

  // Nactu jmeno
  pch = strtok(NULL, ";");
  strncpy(tmp->name, pch, STUDENT_NAME_SIZE - 1);
  tmp->name[STUDENT_NAME_SIZE - 1] = '\0';

  // Nactu prijmeni
  pch = strtok(NULL, ";");
  strncpy(tmp->surname, pch, STUDENT_SURNAME_SIZE - 1);
  tmp->surname[STUDENT_SURNAME_SIZE - 1] = '\0';

  // Nactu tri cisla
  pch = strtok(NULL, ";");
  tmp->t_pts = atoi(pch);

  pch = strtok(NULL, ";");
  tmp->e_pts = atoi(pch);

  pch = strtok(NULL, ";");
  tmp->w_pts = atoi(pch);

  pch = strtok(NULL, ";");

  if (pch[0] == '\n' || pch[0] == '\r') {
    pch[0] = '\0';
  }
  strncpy(tmp->date, pch, STUDENT_DATE_SIZE - 1);
  tmp->date[STUDENT_DATE_SIZE - 1] = '\0';

  return 1;
}

void vypis_data() {
  size_t i = 0;
  student *tmp;

  for (i = 0; i < arrayPos; i++) {
    tmp = array[i];
    printf("%ld) ID: %s, Jmeno: %s %s, Epts: %d, Date: %s\n", i+1, tmp->id, tmp->name, tmp->surname, tmp->e_pts, tmp->date);
  }
}

int compare(const void *a, const void *b) {
  student **aS, **bS, *aaS, *bbS;

  // dostavame void * -> student **
  aS = (student**) a;
  bS = (student**) b;

  // chci originalni pointer student*
  aaS = *aS;
  bbS = *bS;

  return strncmp(aaS->surname, bbS->surname, STUDENT_SURNAME_SIZE);
}

int main(int argc, char *argv[]) {
  FILE *csv;
  char buff[BUFF_SIZE];
  size_t i;
  student *tmp;

  if (argc == 2) {
    printf("Chybny vstup, prvni parameter musi byt csv soubor\n");
    return -1;
  }

  // soubor je v argv[1]
  csv = fopen(argv[1], "r");

  if (!csv) {
    printf("Soubor neexistuje!\n");
    return -1;
  }

  printf("Nacitam vstupni data...\n");

  while(fgets(buff, BUFF_SIZE, csv)) {
    parse_line(buff);
  }

  // zavrit soubor
  fclose(csv);

  // Seradim
  // student *array[1000]
  printf("Radim podle prijmeni:\n");
  qsort(array, arrayPos - 1, sizeof(student*), compare);

  // soubor je v argv[1]
  csv = fopen(argv[2], "w");

  for (i = 0; i < arrayPos; i++) {
    tmp = array[i];
    fprintf(csv, "%ld;%s;%s;%s\n", i, tmp->surname, tmp->name, tmp->id);
  }

  fclose(csv);

  // Uvolnit spojak
  free_mem();

  return 0;
}
