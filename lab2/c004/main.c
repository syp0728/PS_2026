// Enter your student ID and Fullname

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class
{
    int code;      // class code
    char name[30]; // class name
    int unit;      // credites
    int grading;   // grading (1:A+~F, 2:P/F)
};

char kname[2][10] = {"A+~F", "P/F"}; // String for grading

// Functions provided
int loadData(struct st_class *c[]);                            // Load all class list from data file.
void printAllClasses(struct st_class *c[], int csize);         // Print all class list
void findClasses(char *name, struct st_class *c[], int csize); // Search a class by name from the list
void saveAllClasses(struct st_class *c[], int csize);          // Save all class list

// Functions for modifying
int addNewClass(struct st_class *c[], int csize); // Add a class into the list
void editClass(struct st_class *c[], int csize);  // Modify a class in the list

// Functions for making
int applyMyClasses(int my[], int msize, struct st_class *c[], int csize);  // Apply a class
void printMyClasses(int my[], int msize, struct st_class *c[], int csize); // Print my classes
void saveMyClass(int my[], int msize, struct st_class *c[], int csize);    // Save my classes

int main(void)
{
    int no;                       // menu number
    struct st_class *classes[50]; // Class list (max. 50 classes)

    int myclass[10]; // My classes (max. 10 classes of code)
    int mycount = 0; // Amount of my classes

    srand(time(0));
    int count = loadData(classes);
    printf("> Load %d classes.\n", count);

    while (1)
    {
        printf("\n> Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n");
        printf(">> Menu? > ");
        scanf("%d", &no);

        if (no == 1)
        {
            printf("> 1.Class list (%d classes)\n", count);
            printAllClasses(classes, count);
        }
        else if (no == 2)
        {
            printf("> 2.Add a Class\n");
            count = addNewClass(classes, count);
        }
        else if (no == 3)
        {
            printf("> 3.Modify a Class\n");
            editClass(classes, count);
        }
        else if (no == 4)
        {
            printf("> 4.Search a Class\n");
            printf(">> Enter class name > ");
            char name[30];
            scanf("%s", name);
            findClasses(name, classes, count);
        }
        else if (no == 5)
        {
            printf("> 5.Apply a class\n");
            mycount = applyMyClasses(myclass, mycount, classes, count);
            printf("%d classes has been applied.\n", mycount);
        }
        else if (no == 6)
        {
            printf("> 6.My classes\n");
            printMyClasses(myclass, mycount, classes, count);
        }
        else if (no == 7)
        {
            printf("> 7.Save\n");
            saveMyClass(myclass, mycount, classes, count);
            printf("\n> All my classes ware saved to my_classes.txt.\n");
            saveAllClasses(classes, count);
            printf("\n> All of class list ware saved to classes.txt.\n");
        }
        else
            break;
    }
    return 0;
}

int loadData(struct st_class *c[])
{
    int count = 0;
    FILE *file;

    file = fopen("classes.txt", "r");
    while (!feof(file))
    {
        c[count] = (struct st_class *)malloc(sizeof(struct st_class));
        int r = fscanf(file, "%d %s %d %d", &(c[count]->code), c[count]->name, &(c[count]->unit), &(c[count]->grading));
        if (r < 4)
            break;
        count++;
    }
    fclose(file);
    return count;
}

void printAllClasses(struct st_class *c[], int csize)
{
    for (int i = 0; i < csize; i++)
    {
        printf("[%d] %s [credit %d - %s]\n", c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading - 1]);
    }
}

void saveAllClasses(struct st_class *c[], int csize)
{
    FILE *file;
    file = fopen("classes.txt", "w");
    for (int i = 0; i < csize; i++)
    {
        fprintf(file, "%d %s %d %d\n", c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
    }
    fclose(file);
}

void findClasses(char *name, struct st_class *c[], int csize)
{
    int count = 0;

    printf("Searching (keyword : %s)\n", name);
    for (int i = 0; i < csize; i++)
    {
        if (strstr(c[i]->name, name))
        {
            printf("[%d] %s [credit %d - %s]\n", c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading - 1]);
            count++;
        }
    }
    printf("%d classes found.\n", count);
}

// You must complete these functions.
int addNewClass(struct st_class *c[], int csize)
{
    // Caution : Don't allow the duplicate class code.
    // You must complete this function.

    struct st_class *p = (struct st_class *)malloc(sizeof(struct st_class));

    printf(">> code number > ");
    scanf("%d", &(p->code));
    printf(">> class name > ");
    scanf("%s", p->name);
    printf(">> credits > ");
    scanf("%d", &(p->unit));
    printf(">> grading (1: A+~F, 2: P/F) > ");
    scanf("%d", &(p->grading));

    c[csize] = p;
    return csize + 1;
}

void editClass(struct st_class *c[], int csize)
{
    struct st_class *p;
    int code;
    printf(">> Enter a code of class > ");
    scanf("%d", &code);

    // You must complete this section.
    for(int i=0; i<csize; i++){
        if(c[i]->code == code){
            p = c[i];
            break;
        }
    }

    if(p == NULL){
        printf("Error: there is no matching code\n");
        return;
    }

    printf("> Current: [%d] %s [credits %d - %s]\n", p->code, p->name, p->unit, kname[p->grading - 1]);
    printf("> Enter new class name > ");
    scanf("%s", p->name);
    printf("> Enter new credits > ");
    scanf("%d", &(p->unit));
    printf("> Enter new grading(1:Grade, 2: P/F) > ");
    scanf("%d", &(p->grading));

    printf("> Modified.\n");
}

// You must make all these functions.

int applyMyClasses(int my[], int msize, struct st_class *c[], int csize)
{

    int code; 

    while(1){

        printf("신청할 과목코드 입력 (0 입력시 종료): ");
        scanf("%d", &code);

        if(code == 0) break;

        // 과목 존재 확인
        int exist = 0;
        for(int i = 0; i < csize; i++){
            if(c[i]->code == code){
                exist = 1;
                break;
            }
        }

        if(!exist){
            printf("존재하지 않는 과목코드입니다.\n");
            continue;
        }

        // 중복 검사
        int duplicate = 0;
        for(int i = 0; i < msize; i++){
            if(my[i] == code){
                duplicate = 1;
                break;
            }
        }

        if(duplicate){
            printf("이미 신청한 과목입니다.\n");
            continue;
        }

        // 과목 추가
        my[msize] = code;
        msize++;

        printf("수강신청 완료\n");
    }

    return msize;
}

void printMyClasses(int my[], int msize, struct st_class *c[], int csize)
{
    printf("\n[내 수강신청 과목]\n");

    for(int i = 0; i < msize; i++){
        for(int j = 0; j < csize; j++){

            if(my[i] == c[j]->code){

                printf("%03d %s %d학점 ",
                       c[j]->code,
                       c[j]->name,
                       c[j]->unit);

                if(c[j]->grading == 1)
                    printf("A+~F\n");
                else
                    printf("P/F\n");
            }
        }
    }
}

void saveMyClass(int my[], int msize, struct st_class *c[], int csize)
{
    FILE *fp = fopen("my_classes.txt", "w");

    if(fp == NULL){
        printf("파일 저장 실패\n");
        return;
    }

    int total = 0;
    int grade_credit = 0;
    int pass_credit = 0;

    fprintf(fp, "My Classes\n");

    for(int i = 0; i < msize; i++){
        for(int j = 0; j < csize; j++){

            if(my[i] == c[j]->code){

                fprintf(fp,"%03d %s %d ",
                        c[j]->code,
                        c[j]->name,
                        c[j]->unit);

                if(c[j]->grading == 1){
                    fprintf(fp,"A+~F\n");
                    grade_credit += c[j]->unit;
                }
                else{
                    fprintf(fp,"P/F\n");
                    pass_credit += c[j]->unit;
                }

                total += c[j]->unit;
            }
        }
    }

    fprintf(fp,"\n수강 과목 수: %d\n", msize);
    fprintf(fp,"총 수강학점: %d\n", total);
    fprintf(fp,"A+~F 학점: %d\n", grade_credit);
    fprintf(fp,"P/F 학점: %d\n", pass_credit);

    fclose(fp);

    printf("my_classes.txt 파일 저장 완료\n");
}