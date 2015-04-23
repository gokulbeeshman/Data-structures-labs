#include<iostream>

using namespace std;

int a[200];

int top1=-1,top2=200;

void push1(int x)
{
if(top1+1!=top2)
{
top1++;
a[top1]=x;
}
else cout<<"Overflow";
}

void push2(int x)
{
if(top1+1!=top2)
{
top2--;
a[top2]=x;
}
else cout<<"Overflow";
}

int pop1()
{
if(top1>0)
{
top1--;
return a[top1+1];
}
else cout<<"Underflow";
}

int pop2()
{
if(top2<200)
{
top2++;
return a[top2-1];
}
else cout<<"Underflow";
}

void display1()
{
for(int i=0;i<=top1;i++)
{
cout<<a[i]<<" ";
}
}

void display2()
{
for(int i=199;i>=top2;i--)
{
cout<<a[i]<<" ";
}
}

int main()
{
int choice=0;
int x;
while(choice!=7)
{
cout<<endl<<"Enter 1.Push-1 2.Pop-1 3.Display-1 4.Push-2 5.Pop-2 6.Display-2 7.Exit";
cin>>choice;
if(choice==1)
{
cin>>x;
push1(x);
}
if(choice==2)
{
x=pop1();
cout<<x<<" was popped\n";
}
if(choice==3)
{
display1();
}
if(choice==4)
{
cin>>x;
push2(x);
}
if(choice==5)
{
x=pop2();
cout<<x<<" was popped\n";
}
if(choice==6)
{
display2();
}
}
}
