#include<iostream>
#include<stdio.h>
using namespace std;


class node
{
public:
  int data;
  node * left;
  node * right;
 
  node()
  {
    left=right=NULL;
  }
};

class binarysearchtree
{
public:
 node * root;

  binarysearchtree()
  {
    root=NULL;
  }

  void insert(int n, node * current)
  {
    node * temp;
    temp = new node;
    temp->data=n;
    if(current==NULL)
      {
	root=temp;
	return;
      }
    if((current->left==NULL)&&(n<current->data))
      {
	current->left=temp;
      }
    else  if((current->right==NULL)&&(n>current->data))
      {
	current->right=temp;
      }
    else
      {
	if(n<current->data)
	  {
	    insert(n,current->left);
	  }
	if(n>current->data)
	  {
	    insert(n,current->right);
	  }
      }
  }
  void preorder(node * n)
  {
    if(n==NULL)
      {
	return;
      }
    else
      {
	if(n->data!=0)
	  {
    cout<<n->data<<"  ";
	  }
    preorder(n->left);
    preorder(n->right);
      }

  }
  
  void inorder(node * n)
  {
    if(n==NULL)
      {
	return;
      }
    else
      {
     
    inorder(n->left);
    if(n->data!=0)
      {
    cout<<n->data<<"  ";
      }
    inorder(n->right);
      }
  }

  int deleter(int s, node * n)
  {
    if(n==NULL)
      {
	return 0;
      }
    else if(n->data==s)
      {
	if((n->left==NULL)&&(n->right==NULL))
	  {
	    delete n;
	    return 1;
	  }
	else 
	  {
	    if(n->right==NULL)
	      {
		n->data=n->left->data;
		n->left=NULL;
		n=n->left;
		delete n;
		return 1;
	      }
	    else if(n->left==NULL)
	      {
		n->data=n->right->data;
		n->right=NULL;
		n=n->right;
		delete n;
		return 1;
	      }
	  }
	if((n->left!=NULL)&&(n->right!=NULL))
	  {
	    node * temp=n->right;
	    while(temp->left!=NULL)
	      {
		temp=temp->left;
	      }
	    n->data=temp->data;
	    delete temp;
	    return 1;
	  }
      }
    else
      {
	if(s<n->data)
	  {
	   
	    deleter(s,n->left);
	  }
	else if(s>n->data)
	  {
	    deleter(s,n->right);
	  }
      }
  }
  int search(int s, node * n)
  {
    if(n==NULL)
      {
	return 0;
      }
    else if(n->data==s)
      {
	return 1;
      }
    else
      {
	if(s<n->data)
	  {
	    search(s,n->left);
	  }
	else if(s>n->data)
	  {
	    search(s,n->right);
	  }
      }
    
  }

 
};

int main()
{
  int choice=0;
  binarysearchtree b;
  
  while(choice!=6)
    {
      cout<<"\nEnter 1.Insert 2. Search 3. Delete 4. Inorder 5. Preorder 6. Exit";      cin>>choice;
      if(choice==1)
	{
	  int temp;
	  cout<<endl<<"Enter element to insert";
	  cin>>temp;
	  b.insert(temp,b.root);
	}
      if(choice==2)
	{
	  int temp;
	  cout<<"\n Enter the element to search for";
	  cin>>temp;
	  if(b.search(temp,b.root))
	    {
	      cout<<"\n ELement found!";

	    }
	  else cout<<"\nElement not found";
	}
      if(choice==3)
	{
	  int temp;
	  cout<<"\nEnter element to delete";
	  cin>>temp;
	  if(b.deleter(temp,b.root))
	    {
	      cout<<"\n Element deleted!";
	    }
	    else cout<<"\n Element not found";  
	}
      if(choice==4)
	{
	  b.inorder(b.root);
	}
      if(choice==5)
	{
	  b.preorder(b.root);
	}
    }
}
