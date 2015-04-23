#include<iostream>
#include<ctype.h>
#include<string.h>


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


class tree
{
public:

  node * root;
  
  tree()
  {
    root=NULL;
  }
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
	if(!isalpha(n->data))
	  {
	    cout<<"(";
	  }
	inorder(n->left);
	cout<<n->data<<" ";
	inorder(n->right);
	if(!isalpha(n->data))
	  {
	    cout<<")";
	  }
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
};


class stack
{
public:
  tree * a[100];
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
  
  tree * pop()
  {
    top--;
    return a[top+1];
  }
  
  void push(tree * n)
  {
    a[++top]=n;
  }

  tree * topelem()
  {
    return a[top];
  }


};

tree * mergetree(tree * newroot, tree * leftsubtree, tree * rightsubtree)
{
  newroot->root->left=leftsubtree->root;
  newroot->root->right=rightsubtree->root;
  leftsubtree->root->parent=newroot->root;
  rightsubtree->root->parent=newroot->root;
  return newroot;
}

int main()
{
  stack s;
  char a[100];
  cout<<"Enter the postfix expression\n";
  cin>>a;
  for(int i=0;i<strlen(a);i++)
    {
      if(isalpha(a[i]))
	{
	  tree * temp;
	  temp= new tree;
	  node * temproot;
	  temproot= new node;
	  temproot->data=a[i];
	  temp->root=temproot;
	  s.push(temp);
	}
	else
	  {
	    tree *newroot=new tree;
	    tree *leftsubtree;
	    tree *rightsubtree;
	    node *temproot=new node;
	    temproot->data=a[i];
	    newroot->root=temproot;
	    rightsubtree=s.pop();
	    leftsubtree=s.pop();
	    newroot=mergetree(newroot,leftsubtree,rightsubtree);
	    s.push(newroot);
	  }
    }

      tree * exptree=s.pop();
      cout<<"Prefix :\n";
      exptree->preorder(exptree->root); cout<<endl;
      cout<<"Infix :\n ";
      exptree->inorder(exptree->root); cout<<endl;
      cout<<"Postfix : \n"; 
      exptree->postorder(exptree->root);

}
