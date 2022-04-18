#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int *a()
{
   int *p = (int *)malloc(20);
   p[0] = 1;
   p[1] = 2;
   p[2] = 3;
   p[3] = 4;
   p[4] = 5;
   return p;
}

void change(int *p)
{
   p[1] = 111;
}

void afree(int *a)
{
   free(a);
}

int recursive(int i)
{
   if (i == 1)
   {
      return 1;
   }

   return i * recursive(i - 1);
}

int step(int i)
{
   if (i == 2 || i == 1)
   {
      return i;
   }

   return step(i - 1) + step(i - 2);
}

typedef struct student
{
   int num;
   char name[20];
   char sex;
   int age;
   float score;
   char addr[30];
}student,*pstu;

int main()
{
   struct student s = {1001, "lele", 'M', 20, 88, "shenzhen"};
   pstu p = &s;
   printf("%d %s %c %d %6.2f %s", p->num, p->name, p->sex, p->age, p->score, p->addr);
   // int a[3] = {1,2,3};
   // int *p = a;
   // printf("%d",p[0]);
   // printf("%d",p[1]);
   // printf("%d",p[2]);
   char o = '2';
   char *p1 = &o;
}