#include<iostream>

using namespace std;

struct node
{
int data;
node * next;
};

class linkedlist
{
public:
node * head;

linkedlist()
{
head=NULL;
}
void insert(int n)
{
if(head==NULL)
{
node * temp;
temp= new node;
temp->data=n;
temp->next=NULL;
head=temp;
}

else
{
node * temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
node * temp2;
temp2=new node;
temp2->data=n;
temp->next=temp2;
temp2->next=NULL;
}
}

void print()
{
node * temp=head;
cout<<endl<<temp->data<<"-->";
temp=temp->next;
while(temp->next!=NULL)
{
cout<<temp->data<<"-->";
 temp=temp->next;
}
cout<<temp->data;
}


};


int main()
{
int choice=0;
linkedlist l;
int count=0;
while(choice!=4)
{
cout<<"\n Enter 1. New node 2. Print 3. Count nodes 4. Exit";
cin>>choice;

if(choice==1)
{
cout<<"Enter new element data";
int n;
cin>>n;
l.insert(n);
count++;
}
if(choice==2)
{
l.print();
}
if(choice==3)
{
cout<<endl<<count;
}
}
}
