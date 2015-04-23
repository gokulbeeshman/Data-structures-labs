#include<iostream>
#include<ctype.h>
#include<string.h>

using namespace std;


class stck
{
public:
int a[100];
int top1;

stck()
{
top1=-1;
for(int i=0;i<100;i++)
a[i]=0;
}
void push(int x)
{
top1++;
a[top1]=x;
}
int top()
{
return a[top1];
}
int pop()
{
top1--;
return a[top1+1];
}
}; 
stck stack;

int getint(char a)
{
return ((int) a-48);
}

int evaluator(char prefix[200], int len)
{
int tempno=0; int n1,n2;
for(int i=len ;i>=0;i--)
{

if(!isdigit(prefix[i]))
{
n1=stack.pop();
n2=stack.pop();
if(prefix[i]=='+')
{
stack.push(n1+n2);
}
if(prefix[i]=='-')
{
stack.push(n2-n1);
}
if(prefix[i]=='*')
{
stack.push(n2*n1);
}
if(prefix[i]=='/')
{
stack.push(n2/n1);
}
}
if(isdigit(prefix[i]))
{
stack.push(getint(prefix[i]));

tempno*=10;
tempno+=getint(prefix[i]); 
}
else if(prefix[i]==' ')
{

stack.push(tempno);
tempno=0;
}
} // end loop
return stack.top();
} //end fn


int main()
{
char a[200]; char x;
cout<<endl<<"Enter the prefix expression, with elements separated by spaces";
cin>>x;
std::string gets(a);
int len=0;
for(int i=0;a[i]!='n';i++)
{
len++;
if(a[i]==' ')
{
continue;
}
if(a[i]=='n') {break;}
}
cout<<endl<<len<<endl;
cout<<evaluator(a,len);
}
