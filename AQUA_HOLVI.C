
// PROGRAM TO EVALUATE INFIX TO POSTFIX 
 EXPRESSION USING STACK IN C LANGUAGE 

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
char stack[20],infix[20],postfix[20];
int top=-1;

int pr(char oper)
{
  if(oper=='/'||oper=='*'||oper=='%')
  return 2;
  else if(oper=='+'||oper=='-')
  return 1;
  else if(oper=='('||')')
  return 0;
  else
  return -1;
}
void push(char oper)
{
 stack[++top]=oper;
}
char pop()
{
 return stack[top--];
}
void main()
{
 char ch;
 int i,j=0;
 clrscr();
 push('#');
 printf("\n Enter a Valid Postfix Expression:\n");
 scanf("%s",infix);
 for(i=0;i<strlen(infix);i++)
 {
  ch=infix[i];
  if(ch=='(')
  push(ch);
  else if(isalnum(ch))
  postfix[j++]=ch;
  else if(ch==')')
  {
   while(stack[top]!='(')
   postfix[j++]=pop();
   pop();
  }
  else if(pr(ch)==-1)
  {
  printf("\n invalid infix expression");
  getch();
  exit(0);
  }
  else
  {
   if(pr(ch)>pr(stack[top]))
   push(ch);
   else
   {
   while(stack[top]>=pr(ch)&&stack[top]!='#')
   postfix[j++]=pop();
   push(ch);
   }
  }
 }
 while(stack[top]!='#')
 postfix[j++]=pop();
 postfix[j]='\0';
 printf("\n postfix expression:\n");
 printf("%s",postfix);
 getch();
}



