#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define MAX = 100
struct stack
{
    char stck[100];
    int top;

}s;
void push(char item)
{
    if(s.top ==(100-1))
    printf("STACK IS FULL\n");
    else{
        s.top=s.top+1;
        s.stck[s.top]=item;
    }

}
void pop()
{
    if(s.top==-1)
    printf("STACK IS EMPTY\n");
    else
    s.top=s.top-1;

}
int checkpair(char val1,char val2)
{
    return((val1=='('&& val2==')')||(val1=='['&& val2==']')||(val1=='{'&& val2=='}'));
}
int checkbalance(char expr[],int len)
{
    for(int i =0 ;i<len;i++)
    {
    if(expr[i]=='('||expr[i]=='['||expr[i]=='{')
    push(expr[i]);
    
    else
    {
        if(s.top==-1)
        return 0;
        else if (checkpair(s.stck[s.top],expr[i]))
        {
            pop();
            continue;
        }
        return 0;
        
    }
    }
}
int main()
{
    char exp[100]="({})[]{}";
    int i=0;
    s.top=-1;
    int len =strlen(exp);
    checkbalance(exp,len)?printf("Balanced"):printf("Not Balanced");
    scanf("%d");
    return 0;
}