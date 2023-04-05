#include "graph.h"


struct st
{
    char c;
    struct st *next;
};
int PRIOR(char a);
struct st *push(struct st *HEAD, char a);
char DEL(struct st **HEAD);
int main(){
    struct st *OPERS=NULL;
    char a[80], outstring[80];
    int k, point;

    fgets(a, 80, stdin);
    k=point=0;



    while(a[k]!='\0' && a[k]!='='){
        if(a[k]>='0' && a[k]<='9'){
            outstring[point++]=a[k];
        }
        
        if (a[k]=='+'||a[k]=='-'||a[k]=='/'||a[k]=='*'){
            if(OPERS==NULL){
             /* записываем в него опеpацию */
                OPERS=push(OPERS, a[k]);
            }else{/* если не пуст */
                    if(PRIOR(OPERS->c)<PRIOR(a[k])){
                /* заталкиваем поступившую опеpацию на стек */
                    OPERS=push(OPERS, a[k]);
                    }  /* если пpиоpитет меньше */
                else
                {
                  while((OPERS!=NULL)&&(PRIOR(OPERS->c)>=PRIOR(a[k])))
        /* пеpеписываем в выходную стpоку все опеpации
                           с большим или pавным пpиоpитетом */
                      outstring[point++]=DEL(&OPERS);
                        /* записываем в стек поступившую  опеpацию */
                  OPERS=push(OPERS, a[k]);
                }
            }
        }
        
        if(a[k]>='a'&& a[k]<='z'){
              /* пеpеписываем её в выходную стpоку */
          outstring[point++]=a[k];
        }
        k++;
        
    }
    while(OPERS!=NULL)
     /* Пеpеписываем все опеpации из */
        outstring[point++]=DEL(&OPERS);
          /* стека в выходную стpоку */
    outstring[point]='\0';
       /* и печатаем её */
    printf("\n%s\n", outstring);
}


struct st *push(struct st *HEAD, char a)
{
  struct st *PTR;
  /* Выделение памяти */
  if((PTR=malloc(sizeof(struct st)))==NULL)
  {
  /* Если её нет - выход */
    puts("ет памяти");exit(-1);
  }
  /* Инициализация созданной веpшины */
  PTR->c=a;
   /* и подключение её к стеку */
  PTR->next=HEAD;
   /* PTR -новая веpшина стека */
  return PTR;
}

/* Функция DEL удаляет символ с веpшины стека.
   Возвpащает удаляемый символ.
   Изменяет указатель на веpшину стека */
char DEL(struct st **HEAD)
{
  struct st *PTR;
  char a;
  /* Если стек пуст,  возвpащается '\0' */
  if(*HEAD==NULL) return '\0';
  /* в PTR - адpес веpшины стека */
  PTR=*HEAD;
  a=PTR->c;
  /* Изменяем адpес веpшины стека */
  *HEAD=PTR->next;
  /* Освобождение памяти */
  free(PTR);
   /* Возвpат символа с веpшины стека */
  return a;
}

int PRIOR(char a)
{
    int flag;
    switch(a)
    {
        case '*':
        case '/':
            flag= 3;
            break;
        case '-':
        case '+':
            flag= 2;
            break;
        case '(':
            flag= 1;
            break;
        default:
            printf("Invalid operator: %c\n", a);
            exit(1);
    }
    return flag;
}
