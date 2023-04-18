#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 120



typedef struct Stack
{
    char data[MAX_SIZE];
    int top;
}Stack;


void init(Stack* p)
{
    p->top = -1;
}

int is_full(Stack* p)
{
    return (p->top == (MAX_SIZE - 1));
}

int is_empty(Stack* p)
{
    return (p->top == -1);
}

void push(Stack* p, char data)
{
    if (is_full(p))
    {
        printf("������ ��á���ϴ�\n"); return;
    }
    else
    {
        p->data[++(p->top)] = data;


    }
}

char pop(Stack* p){
    if (is_empty(p))
    {
        printf("������ ����ֽ��ϴ�\n");
        return;
    }

    return p->data[(p->top)--];
}
char peak(Stack * p)
{
    if (is_empty(p))
    {
        printf("������ ����ֽ��ϴ�\n");
        exit(1);
    }

    return p->data[(p->top)];
}

void * strwrSub(char str[],char strS[]) {// ������ȭ?
    int i = 0;
    int j = 0;
   
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            strS[j] = str[i] + 32;
           
            i++;
            j++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
  
            strS[j] = str[i];
            i++;
            j++;
        }
        else {//���� Ư������ ������
            //printf("%c", str[i]);
            i++;
            

        }
     
        strS[j] = '\0';
       
    }
 
    //return strS;
}

int is_pal(char *strS) {


    Stack s;
    init(&s);
    int len = strlen(strS);
    int palFlag = 1;
    for (int i = 0; i < len; i++) {

        push(&s, strS[i]);

    }
    if (len % 2 == 0) {

        for (int i = 0; i < len/2; i++) {

            if (strS[i] == pop(&s)) {
              
           }
            else {
                palFlag = 0;
            }

        }

    }
    else if (len % 2 == 1) {

        for (int i = 0; i < len / 2-1; i++) {

            if (strS[i] == pop(&s)) {
                
            }
            else {
                palFlag = 0;
            }

        }
    }
    return palFlag;


}

int main() {
    char input[100];
    char strS[100];
    int flag;

    printf("ȸ���� �Է��Ͻÿ�:");
    scanf_s("%s", input,sizeof(input));

  

    strwrSub(input,strS);
    printf("%s", strS);

    flag = is_pal(strS);

    if (flag == 1) {
        printf("ȸ���Դϴ�.");
 }
    else {
        printf("ȸ���� �ƴմϴ�.");
    }
    printf("%d", flag);
    printf("");
  





}
