#ifndef CLASS_H
#define CLASS_H

struct st_class
{
    int code;
    char name[30];
    int unit;
    int grading;
};

extern char kname[2][10];

/* 제공된 함수 */
int loadData(struct st_class *c[]);
void printAllClasses(struct st_class *c[], int csize);
void findClasses(char *name, struct st_class *c[], int csize);
void saveAllClasses(struct st_class *c[], int csize);

/* 수정 함수 */
int addNewClass(struct st_class *c[], int csize);
void editClass(struct st_class *c[], int csize);

/* 구현 함수 */
int applyMyClasses(int my[], int msize, struct st_class *c[], int csize);
void printMyClasses(int my[], int msize, struct st_class *c[], int csize);
void saveMyClass(int my[], int msize, struct st_class *c[], int csize);

#endif