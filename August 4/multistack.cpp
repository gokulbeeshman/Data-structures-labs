#include<iostream>
#include<string.h>
using namespace std;

class element
{
public:
union
{
public:
int integer;
char word[50];
float decimal;
} a;
char type;

};

int top=-1;

element stack[100];
void push()
{
if(top!=99)
{
top++;
cout<<"Enter i-> integer, w->string, f-> float";
cin>>stack[top].type;
if(stack[top].type=='i')
{
cin>>stack[top].a.integer;
}
else if(stack[top].type=='w')
{
cin>>stack[top].a.word;
}
else if(stack[top].type=='f')
{
cin>>stack[top].a.decimal;
}
else cout<<"Invalid type";
}
else
cout<<"Overflow";
cout<<endl;
}

void pop()
{
if(top!=-1)
{
if(stack[top].type=='i')
{
cout<<stack[top].a.integer;
}
else if(stack[top].type=='w')
{
cout<<stack[top].a.word;
}
else if(stack[top].type=='f')
{
cout<<stack[top].a.decimal;
}
top--;
}
else cout<<"Underflow";

cout<<endl;
}

void display()
{
for(int i=0;i<=top;i++)
{
if(stack[i].type=='i')
{
cout<<stack[i].a.integer;
}
else if(stack[i].type=='w')
{
cout<<stack[i].a.word;
}
else if(stack[i].type=='f')
{
cout<<stack[i].a.decimal;
}
cout<<endl;
}
}

int main()
{
int choice=0;
while(choice!=4)
{
cout<<endl<<"Enter 1.Push 2.Pop 3.Display 4.Exit";
cin>>choice;
if(choice==1)
{
push();
}
if(choice==2)
{
pop();
}
if(choice==3)
{
display();
}
}
}
