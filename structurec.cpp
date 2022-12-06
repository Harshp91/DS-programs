#include<stdio.h>

struct student
{
    int rollno;
    int section;
    float percentage;
    int mobno;
}s;

int main()
{
  struct student s[5];
  int i;
  for(i=0;i<5;i++)
  {
     scanf("%d",&s[i].rollno);
     scanf("%d",&s[i].section);
     scanf("%f",&s[i].percentage);
     scanf("%d",&s[i].mobno);
  }
  
  for(i=0;i<5;i++)
  {
     printf("%d ",s[i].rollno);
     printf("%d ",s[i].section);
     printf("%0.1f%% ",s[i].percentage);
     printf("%d\n",s[i].mobno);
  }

 return 0;
}