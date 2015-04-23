#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

class stck
{
public:
char data[200];
int top1;

stck()
{
top1=-1;
}

void push(char x)
{
top1++;
data[top1]=x;
}

char pop()
{
top1--;
return data[top1+1];
}

char top()
{
if(top1<0)
{
return -1;
}
return data[top1];
}
} ;

stck stack;

int getpriority(char x)
{
if((x=='(')||(x==')'))
{
return 0;
}

if((x=='+')||(x=='-'))
{
return 1;
}
if((x=='*')||(x=='/'))
{
return 2;
}
if(x=='^')
{
return 3;
}
}


void revstring(char s[200])
{
char temp;
int length=strlen(s);
for(int i=0;i<(length/2);i++)
{
temp=s[i];
s[i]=s[length-i-1];
s[length-i-1]=temp;
}
}

void getpostfix(char infix[200],char postfix[200])
{
int length=strlen(infix);
int postfixcounter=0;
int priority;
for(int i=0;i<length;i++)
{
if(infix[i]==')')
{
while(1)
{
if(stack.top()=='(')
{
char s=stack.pop();
break;
}
postfix[postfixcounter]=stack.pop();
cout<<postfix[postfixcounter]<<endl;
postfixcounter++;
}
continue;
}
if(infix[i]=='(')
{
stack.push(infix[i]);
continue;
}
if(isalpha(infix[i]))
{

postfix[postfixcounter]=infix[i];
cout<<postfix[postfixcounter]<<endl;
postfixcounter++;
}
else
{
priority=getpriority(infix[i]);
if(priority>=getpriority(stack.top()))
{
stack.push(infix[i]);
}
else
{
while(getpriority(stack.top())>priority)
{
postfix[postfixcounter]=stack.pop();
cout<<postfix[postfixcounter]<<endl;
postfixcounter++;
}
stack.push(infix[i]);
}
}
}
while(stack.top()>0)
{
postfix[postfixcounter]=stack.pop();
cout<<postfix[postfixcounter]<<endl;
postfixcounter++;
}
}

void fixbrackets(char s[200])
{

}

int main()
{
char a[200];
cout<<"Enter the infix expression";
cin>>a;
revstring(a);
int length=strlen(a);
for(int i=0;i<length;i++)
{
if(a[i]=='(')
{
a[i]=')';
continue;
}
else if(a[i]==')')
{
a[i]='(';
}
}

char postfix[200];
getpostfix(a,postfix);
revstring(postfix);
cout<<endl<<"Prefix expression is: ";
for(int i=0;i<strlen(a);i++)
{
cout<<postfix[i];
} 
}

