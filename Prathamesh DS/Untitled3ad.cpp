#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#dene MAX 20
void push(int);
char pop();
void inx_to_prex();
int precedence (char);
char stack[20],inx[20],prex[20];
int top = -1;
int main()
{
printf("\nINPUT THE INFIX EXPRESSION : ");
scanf("%s",inx);
inx_to_prex();
return 0;
}
// method that pushes the elements onto the character stack
void push(int pos)
{
if(top == MAX-1)
{
printf("\nSTACK OVERFLOW\n");
}
else {
top++;
stack[top] = inx[pos];
}}
// method that removes character from stack and returns them
char pop()
{
char ch;
if(top < 0)
{
printf("\nSTACK UNDERFLOW\n");
exit(0);
}
else
{
ch = stack[top];
stack[top] = '\0';
top--;
return(ch);
}
return 0;
}
// method that converts String from inx to prex
// all the strings are assumed to be valid expressions
void inx_to_prex()
{
int i = 0,j = 0;
strrev(inx); // Reverse the inx expression
while(inx[i] != '\0')
{
// if an alphabet is found then copy it to the output string
if(inx[i] >= 'a' && inx[i] <= 'z')
{
prex[j] = inx[i];
j++;
i++;
}
// In the reversed string, closing bracket will be found rst so put it in the stack
else if(inx[i] == ')' || inx[i] == '}' || inx[i] == ']')
{
push(i);
i++;
}
// if an opening bracket is found, then
else if(inx[i] == '(' || inx[i] == '{' || inx[i] == '[') /* when closing bracket is found */
{
if(inx[i] == '(')
{
while(stack[top] != ')') /* pop till opening bracket is found */
{
prex[j] = pop();
j++;
}
pop();
i++;
}
else if(inx[i] == '[')
{
while(stack[top] != ']') /* pop till corresponding opening bracket is found */
{
prex[j] = pop();
j++;
}
pop();
i++;
}
else if(inx[i] == '{')
{
while(stack[top] != '}') /*pop till corresponding opening bracket is found*/
{
prex[j] = pop();
j++;
}
pop();
i++;
}}
else
{
// if the stack if empty, then we simply put the operator in stack
if(top == -1)
{
push(i);
i++;
}
// if the precedence of operator is less than the stack top then
else if( precedence(inx[i]) < precedence(stack[top]))
{
prex[j] = pop(); // pop the stack top and add it to the prex string
j++;
// if you have an operator that has precedence greater than operator
while(precedence(stack[top]) > precedence(inx[i])){
prex[j] = pop(); // Pop the operator
j++;
if(top < 0) {
break;
}}
push(i);
i++;
}
// if the precedence of operator is greater than or equal to the stack top
else if(precedence(inx[i]) >= precedence(stack[top]))
{
push(i); // Push it onto the stack
i++;
}}}
// At the end remove all the operators from the stack
while(top != -1)
{
prex[j] = pop();
j++;
}
// Reverse the nal string before output
strrev(prex);
prex[j] = '\0';
printf("EQUIVALENT PREFIX NOTATION : %s ",prex);
}
/* Function to return precedence of operators */
int precedence(char alpha)
{
if(alpha == '+' || alpha =='-')
{
return(1);
}
if(alpha == '*' || alpha =='/')
{
return(2);
}
return 0;
}

