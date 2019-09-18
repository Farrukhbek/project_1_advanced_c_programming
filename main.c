#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max_num;
int a=0;
int b,c,d,e,f,g,h,x;
struct STRUCTURENAME
{
     char *name;
     char *phone_number;
     char *birth_date;
};
struct STRUCTURENAME **STRUCTUREVARNAME;

void registration()
{
    if(a<100 && a < max_num)
                {
                         printf("Name:");
                         scanf("%s", STRUCTUREVARNAME[a]->name);
                         printf("Phone_number:");
                         scanf("%s", STRUCTUREVARNAME[a]->phone_number);
                         printf("Birth:");
                         scanf("%s", STRUCTUREVARNAME[a]->birth_date);
                         a++;
                         printf("<<%d>>\n", a);
                         struct STRUCTURENAME *temp;
                         for(b=0;b<a-1;b++)
                         {
                             for(c=b+1;c<a;c++)
                             {
                                 d = strcmp(STRUCTUREVARNAME[b]->name,STRUCTUREVARNAME[c]->name);
                                 if(d>0)
                                 {
                                     temp = STRUCTUREVARNAME[b];
                                     STRUCTUREVARNAME[b] = STRUCTUREVARNAME[c];
                                     STRUCTUREVARNAME[c] = temp;
                                 }
                             }
                         }
    }
    else if (a == max_num || a== 100)
        {
                   printf("OVERFLOW\n");
        }
}

void move_to_file()
{
    FILE *fp;
    fp  = fopen("PHONE_BOOK.txt", "w");
    for(int b=0; b<a; b++)
        {
            fprintf(fp,"%s", STRUCTUREVARNAME[b]->name);
            fprintf(fp," %s",STRUCTUREVARNAME[b]->phone_number);
            fprintf(fp," %s\n",STRUCTUREVARNAME[b]->birth_date);
        }
    fclose(fp);
}


void show_all()
{
    if(a>0)
        {
             for(c=0;c<a;c++)
             {
                printf("%s %s %s\n", STRUCTUREVARNAME[c]->name, STRUCTUREVARNAME[c]->phone_number,STRUCTUREVARNAME[c]->birth_date);
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
                e = strcmp(search_by_name,STRUCTUREVARNAME[b]->name);
                if(e==0)
                {
                    strcpy(STRUCTUREVARNAME[b]->name,nullStr);
                    strcpy(STRUCTUREVARNAME[b]->phone_number,nullStr);
                    strcpy(STRUCTUREVARNAME[b]->birth_date,nullStr);
                    free(STRUCTUREVARNAME[a]);
                    a--;
                    for(f=b;f<a;f++)
                    {
                        STRUCTUREVARNAME[b] = STRUCTUREVARNAME[b+1];
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
              strcpy(find_by_birth_2,STRUCTUREVARNAME[b]->birth_date);
              find_by_birth_2[6] = '\0';
              sprintf(very_temp,"%*s",1,find_by_birth_2 + 4);
              h = strcmp(find_by_birth,very_temp);
              if(h == 0)
              {
                  printf("%s %s %s\n", STRUCTUREVARNAME[b]->name,STRUCTUREVARNAME[b]->phone_number,STRUCTUREVARNAME[b]->birth_date);
              }
       }
}

void reg_from_file()
{
    FILE *fp;
    int count = a+1;
    char arr[32], arr_1[32], arr_2[32];
    fp = fopen("PHONE_BOOK.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp,"%s", &arr);
        fscanf(fp,"%s", &arr_1);
        fscanf(fp,"%s", &arr_2);
        strcpy(STRUCTUREVARNAME[count]->name, arr);
        strcpy(STRUCTUREVARNAME[count]->phone_number, arr_1);
        strcpy(STRUCTUREVARNAME[count]->birth_date, arr_2);
        count++;
    }
    a=count;
    fclose(fp);
}


int main()
{
    printf("Max_num:");
    scanf("%d",&max_num);
    STRUCTUREVARNAME = (struct STRUCTURENAME**)malloc(max_num*sizeof(struct STRUCTURENAME*));
    FILE *fp;
    fp = fopen("PHONE_BOOK.txt", "w");
    if(fp == NULL)
    {
            printf("Could not open file");
            return -1;
    }
    fclose(fp);

    for(b=0; b<max_num; b++)
        {
                STRUCTUREVARNAME[b] = (struct STRUCTURENAME*)malloc(sizeof(struct STRUCTURENAME));
                STRUCTUREVARNAME[b]->name =(char*)malloc(101*sizeof(char));
                STRUCTUREVARNAME[b]->phone_number =(char*)malloc(101*sizeof(char));
                STRUCTUREVARNAME[b]->birth_date =(char*)malloc(101*sizeof(char));
        }

    if(STRUCTUREVARNAME == NULL)
    {
        printf("Not enough space");
        return -1;
    }

    while(1)
    {
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
        printf("Enter_the_menu_number:");
        int function_chosen;
        scanf("%d", &function_chosen);
    switch(function_chosen)
    {
        case 1: {registration();break;}
        case 2: {show_all();break;}
        case 3: {delete_function();break;}
        case 4: {find_by_birth();break;}
        case 5: {reg_from_file();break;}
        case 6: {move_to_file();return 0; break;}
    }
}
}
