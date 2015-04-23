#include<iostream>
#include<string.h>
using namespace std;


class queue
{
	public:
	union{
	int i;
	float f;
	char c[100];
	} a[200];
	
	char dtype[200];
	
	int front,end;
	
	queue()
	{
	front=0;
	end=-1;
	
	}
	
	void enqueue()
	{
	if(end!=199)
	{
	int x;
	float y;
	char z[100];
	cout<<"\nEnter data type i-int f-float s- string";
	cin>>dtype[end+1];
	if(dtype[end+1]=='i')
	{
	cin>>x;
	end++;
	a[end].i=x;
	}
	if(dtype[end+1]=='f')
	{
	cin>>y;
	end++;
	a[end].f=y;
	}
	if(dtype[end+1]=='s')
	{
	cin>>z;
	end++;
	strcpy(a[end].c,z);
	}
	}
	else cout<<"Queue full";
	}	
	
	void dequeue()
	{
	front++;
	}
	
	void print()
	{
	cout<<endl;
	for(int q=front;q<=end;q++)
	{
	if(dtype[q]=='i')
	{
	cout<<a[q].i<<" ";
	}
	if(dtype[q]=='f')
	{
	cout<<a[q].f<<" ";
	}
	if(dtype[q]=='s')
	{
	cout<<a[q].c<<" ";
	}
	}	
	}
};


int main()
{
queue Q;
int choice=0;

while(choice!=4)
{

cout<<"\n1. Enqueue 2. Dequeue 3. Print 4.Exit"<<endl;
cin>>choice;
if(choice==1)
{
Q.enqueue();
}
if(choice==2)
{
Q.dequeue();
}
if(choice==3)
{
Q.print();
}
}
}
