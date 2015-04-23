#include<iostream>

using namespace std;

struct node
{
int data;
node * next;
};

class stack
{
public:
node * head;
node * top;

stack()
{
head=NULL;
top=NULL;
}

void push(int n)
{
if(head==NULL)
{
node * temp;
temp = new node;
head=temp;
temp->data=n;
temp->next=NULL;
top=temp;
}

else
{
node * temp;
temp=new node;
temp->data = n;
temp->next=NULL;
top->next=temp;
top=temp;
}

}

void pop()
{
node * temp=head;
while(temp->next!=top)
{
temp=temp->next;
}
temp->next=NULL;
node * todel=top;
cout<<"\n Popping :"<<todel->data;
delete todel;
top=temp;
}

void print()
{
node * temp=head;
cout<<endl;
while(temp->next!=NULL)
{
cout<<temp->data<<" ";
 temp=temp->next;
}
cout<<temp->data;
}

} ;


int main()
{
int choice=0;
stack s;
while(choice!=4)
{
cout<<"\n Enter 1.Push 2.Pop 3.Print 4.Exit";
cin>>choice;
if(choice==1)
{
cout<<"\n Enter element to push";
int n;
cin>>n;
s.push(n);
}

if(choice==2)
{
s.pop();
}
if(choice==3)
{
s.print();
}
}
}
