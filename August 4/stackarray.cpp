#include<iostream>

using namespace std;

int a[100];
void initialize()
{
for(int i=0;i<100;i++)
{
a[i]=0;
}
}

void push(int x)
{
if(a[0]==99)
{
cout<<"Overflow";
}
else
{
a[0]++;
a[a[0]]=x;
}
}

int pop()
{
if(a[0]==0)
{
cout<<"Underflow";
}
else
{
a[0]--;
return(a[a[0]+1]);
}
}

void display()
{
for(int i=1;i<=a[0];i++)
cout<<a[i]<<" ";
}

int main()
{
initialize();
int choice=0;
while(choice!=4)
{
cout<<endl<<"Enter 1.Push 2.Pop 3.Display 4.Exit";
cin>>choice;
if(choice==1)
{
int x;
cin>>x;
push(x);
}
if(choice==2)
{
int x=pop();
cout<<endl<<x<<" was popped";
}
if(choice==3)
{
display();
}
}

}
