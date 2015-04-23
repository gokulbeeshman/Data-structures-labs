#include<iostream>
#include<ctype.h>
#include<string.h>

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

int isvalid(char infix[200])
{
int leftcount=0,rightcount=0;
for(int i=0;i<strlen(infix);i++)
{
if(infix[i]=='(')
{
leftcount++;
continue;
}
if(infix[i]==')')
{
rightcount++;
continue;
}
if(stack.top()<0)
{
stack.push(infix[i]);
}
else
{

if(isalpha(stack.top()))
{
if(isalpha(infix[i]))
{
return 0;
}
}
if(!isalpha(stack.top()))
{
if(!isalpha(infix[i]))
{
return 0;
}
}
stack.push(infix[i]);

}
}
if(leftcount==rightcount)
return 1;
else return 0;
}

int main()
{
char a[200];
cout<<"Enter infix expression";
cin>>a;
if(isvalid(a))
{
cout<<endl<<"Expression is valid";
}
else cout<<endl<<"Expression is not valid";
}
