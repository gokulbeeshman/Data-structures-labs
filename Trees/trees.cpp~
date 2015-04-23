#include<iostream>

using namespace std;

class node
{
public:
  char data;
  node *left;
  node *right;
  node *parent;

  node()
  {
    left=NULL;
    right=NULL;
    parent=NULL;
  }
};


void preorder(node * n)
{
if(n!=NULL)
{
cout<<n->data<<" ";
preorder(n->left);
preorder(n->right);
}
else {return;}
}

void inorder(node * n)
{
if(n!=NULL)
{
inorder(n->left);
cout<<n->data<<" ";
inorder(n->right);
}
else {return;}
}

void postorder(node * n)
{
if(n!=NULL)
{

postorder(n->left);
postorder(n->right);
cout<<n->data<<" ";
}
else {return;}
}

int main()
{
  node *root=NULL;
  int choice=0;
  node *temp=NULL;
  while(choice!=7)
    {
      if(temp!=NULL){ cout<<endl<<"Currently at: "<<temp->data;}
      if(root==NULL)
	{
	  cout<<"Enter data for root";
	  node * tx;
	  tx=new node;
	  cin>>tx->data;
	  root=tx;
	  temp=root;
	}
      cout<<"\nEnter 1.To Move left 2. To Move right 3. To move up 4.Preorder 5.Postorder 6.Inorder 7.Exit\n";
      cin>>choice;
      if(choice==1)
	{
	  if(temp->left==NULL)
	    {
	       cout<<"Enter data for node";
	       node * t;
	       t=new node;
	       cin>>t->data;
	       temp->left=t;
	       t->parent=temp;
	       temp=t;
	    }
	  else
	    {
	      temp=temp->left;
	    }
	}
      if(choice==2)
	{
	  if(temp->right==NULL)
	    {
	       cout<<"Enter data for node";
	       node * t;
	       t=new node;
	       cin>>t->data;
	       temp->right=t;
	       t->parent=temp;
	       temp=t;
	    }
	  else
	    {
	      temp=temp->right;
	    }
	}
      if(choice==3)
	{
	  if(temp!=root)
	    {
	      temp=temp->parent;
	    }
	}
      if(choice==4)
	{
	preorder(root);
	}
      if(choice==5)
	{
	postorder(root);
	}
      if(choice==6)
	{
	inorder(root);
	}
      
      
      

    }
}
