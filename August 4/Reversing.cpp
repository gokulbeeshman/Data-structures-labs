#include<iostream>

using namespace std;

class node
{
public:
int data;
node * next;

node()
{
next=NULL;
}
};

class circularlinkedlist
{
public:

node * head;

void insert(int n)
{
if(head==NULL)
{
node * temp;
temp= new node;
head=temp;
temp->data=n;
temp->next=temp;
}
else
{
node *temp=head;
while(temp->next!=head)
{
temp=temp->next;
}
node * temp2;
temp2=new node;
temp->next=temp2;
temp2->data=n;
temp2->next=head;
}

}

void print()
{
if(head!=NULL)
{
node * temp=head;
cout<<endl;
while(1)
{
cout<<temp->data<<"  ";
if(temp->next==head)
{
break;
}
temp=temp->next;
}
}
}
void reverse(node *n2=NULL,node *n3=NULL,node *n1=NULL, int tries=0)
{
if(tries==0)
{
n1=head;
n2=n1->next;
n3=n2->next;
}
if(n3==head)
{
n2->next=n1;
head->next=n2;
head=n2;
return;
}


//cout<<n2;
n2->next=n1;

reverse(n3,n3->next,n2,1);

}


circularlinkedlist()
{
head=NULL;
}

};

int main()
{
circularlinkedlist a;
int choice=0; int n;
while(choice!=4)
{
cout<<endl<<"1.Insert 2.Print 3.Reverse Recursively 4.Exit";
cin>>choice;
if(choice==1)
{
cout<<endl<<"Enter data";
cin>>n;
a.insert(n);
}

if(choice==2)
{
a.print();
}

if(choice==3)
{
a.reverse();
}

} //endloop

}
