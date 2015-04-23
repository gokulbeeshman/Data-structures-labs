#include<iostream>

using namespace std;


class queue
{
	public:
	int a[200];
	
	int front,end;
	
	queue()
	{
	front=0;
	end=-1;
	}
	
	void enqueue(int x)
	{
	if(end!=199)
	{
	end++;
	a[end]=x;
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
	for(int i=front;i<=end;i++)
	{
	cout<<a[i]<<" ";
	}	
	}
};


int main()
{
queue Q;
int choice=0;
int temp=0;
while(choice!=4)
{

cout<<"\n1. Enqueue 2. Dequeue 3. Print 4.Exit"<<endl;
cin>>choice;
if(choice==1)
{
cout<<"Enter the element";
cin>>temp;
Q.enqueue(temp);
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
