#include<iostream>

using namespace std;

int a[100];
int top=-1;

void push(int x)
{
top++;
a[top]=x;
}

int topelem()
{
if(top>=0)
return a[top];
}

void pop()
{
if(top>=0)
top--;
}

int main()
{
int a[200];
int n;
cout<<"Enter no of days";
cin>>n;
cout<<"\n Enter values";
int x[200];
for(int i=0;i<200;i++)
{
a[i]=0;
x[i]=0;
}
x[0]=1;
cin>>a[0];
push(a[0]);
int max=a[0];
for(int i=1;i<n;i++)
{
cin>>a[i];
if(a[i]>max)
{
x[i]=i+1;
max=a[i];
push(a[i]);
}
else if(a[i]>topelem())
{
x[i]=x[i-1]+1;
push(a[i]);
}
else if(a[i]<topelem())
{
x[i]=1;
push(a[i]);
}
}
cout<<endl;
for(int i=0;i<n;i++)
{
cout<<x[i]<<" ";
}
}
