#include<iostream>

using namespace std;

class stack
{
public:
  int a[100];
  int top;
  
  stack()
  {
    top=-1;
  }

  bool isEmpty()
  {
    if(top<0)
      return true;
    else return false;
  }
  
  int pop()
  {
    top--;
    return a[top+1];
  }
  
  void push(int n)
  {
    a[++top]=n;
  }

  int topelem()
  {
    return a[top];
  }


};

class queue2stack
{
public:
  stack s1;
  stack s2;

  void enqueue(int n)
  {
  	
    while(!s1.isEmpty())
      {
	s2.push(s1.pop());
      }
    s1.push(n);
    while(!s2.isEmpty())
      {
	s1.push(s2.pop());
      }
    
  }

  int dequeue()
  {
    return s1.pop();
  }
  
  void print()
  {
    while(!s1.isEmpty())
      {
	cout<<s1.topelem();
	s2.push(s1.pop());
	
      }
    while(!s2.isEmpty())
      {
	s1.push(s2.pop());
      }
  }

};

int main()
{
  queue2stack q;
  int choice=0;
  int temp;
  while(choice!=4)
    {
      cout<<"\nEnter 1.Enqueue 2.Dequeue 3.Print 4.Exit\n";
      cin>>choice;
      if(choice==1)
	{
	  cout<<"Enter element to enqueue\n";
	  cin>>temp;
	  q.enqueue(temp);
	}
      if(choice==2)
	{
	  
	  cout<<q.dequeue()<< "was dequeued\n";
	}
	if(choice==3)
	{
		q.print();
	}
    }
}

