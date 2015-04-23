#include<iostream>

using namespace std;

int product(int a[],int size,int index=0)
{
if(index+1==size)
{
return a[index];
}
else

return (a[index]*product(a,size,index+1));
}

int main()
{
int a[100];
cout<<"Enter the no of elements";
int n;
cin>>n;

cout<<"\nEnter the elements";

for(int i=0;i<n;i++)
{
cin>>a[i];
}

cout<<endl<<"Product of the elements is: "<<product(a,n);
}
