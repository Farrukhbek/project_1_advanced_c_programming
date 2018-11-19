#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a=0;
int b,c,d,e,f,g,h,x,y,z;

typedef struct student
                    {
                       char name[50];
                       char phone_number[50];
                       char birth_date[50];
                    }talaba;
                    talaba information[100];
                    talaba information_1[100];
                    talaba temp;


void registration()
{
    if(a<100)
                {
                         printf("Name:");
                         scanf("%s", information[a].name);
                         printf("Phone_number:");
                         scanf("%s", information[a].phone_number);
                         printf("Birth:");
                         scanf("%s", information[a].birth_date);
                         a++;
                         printf("<<%d>>\n", a);
                         for(b=0;b<a-1;b++)
                         {
                             for(c=b+1;c<a;c++)
                             {
                                 d = strcmp(information[b].name,information[c].name);
                                 if(d>0)
                                 {
                                     temp = information[b];
                                     information[b] = information[c];
                                     information[c] =temp;
                                 }
                             }
                         }
                 }
                 else if (a == 100)
                 {
                   printf("OVERFLOW\n");
                 }

}


void show_all()
{
    if(a>0)
        {
             for(x=0;x<a;x++)
             {
                printf("%s %s %s\n", information[x].name, information[x].phone_number,information[x].birth_date);
             }
        }

}

void delete_function()
{
        char search_by_name[100];
        char nullStr[2] = {"\0"};
        if(a==0)
        {
            printf("NO MEMBER\n");
        }
        else if(a != 0)
        {
            printf("Name:");
            scanf("%s", &search_by_name);
            for(b=0;b<a;b++)
            {
                e = strcmp(search_by_name,information[b].name);
                if(e==0)
                {
                    strcpy(information[b].name,nullStr);
                    strcpy(information[b].phone_number,nullStr);
                    strcpy(information[b].birth_date,nullStr);
                    a--;
                    for(f=b;f<a;f++)
                    {
                        information[b] = information[b+1];
                        b++;
                    }
                }
            }
        }
}

void find_by_birth()
{
          char find_by_birth[100];
          char find_by_birth_2[100];
          char very_temp[2] = "0";
          printf("Birth:");
          scanf("%s", &find_by_birth);
          if(strlen(find_by_birth)<2)
          {
              char allo[2] = "0";
              strcat(allo, find_by_birth);
              strcpy(find_by_birth,allo);
          }
          for(b=0;b<a;b++)
          {
              strcpy(find_by_birth_2,information[b].birth_date);
              find_by_birth_2[6] = '\0';
              sprintf(very_temp,"%*s",1,find_by_birth_2 + 4);
              h = strcmp(find_by_birth,very_temp);
              if(h == 0)
              {
                  printf("%s %s %s\n", information[b].name,information[b].phone_number,information[b].birth_date);
              }
       }
}
int main()
{
    while(1)
    {
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
        printf("Enter the menu number:");
        int function_chosen;
        scanf("%d", &function_chosen);
    switch(function_chosen)
    {
        case 1: {registration();break;}
        case 2: {show_all();break;}
        case 3: {delete_function();break;}
        case 4: {find_by_birth();break;}
        case 5: {return 0; break;}
    }
}
}
