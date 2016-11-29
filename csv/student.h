#ifndef _STUDENT_H
#define _STUDENT_H

#define STUDENT_ID_SIZE 6
#define STUDENT_NAME_SIZE 32
#define STUDENT_SURNAME_SIZE 64
#define STUDENT_DATE_SIZE 11

struct STUDENT {
  char id[STUDENT_ID_SIZE];
  char name[STUDENT_NAME_SIZE];
  char surname[STUDENT_SURNAME_SIZE];
  int t_pts, e_pts, w_pts;
  char date[STUDENT_DATE_SIZE];
};

typedef struct STUDENT student;

#endif
