#include<iostream>

using namespace std;

void binarysearch(int a[100],int beg,int end,int x)
{
int med=(beg+end)/2;
if(beg==end){
return ;}
if(x>a[end-1])
{
return;
}
if(a[med]==x)
{
cout<<x<<" found at "<<med+1; return;
}
if(a[med]<x)
{
binarysearch(a,med,end,x);
}
if(a[med]>x)
{
binarysearch(a,beg,med,x);
}
}

int main()
{
cout<<"Enter no of elements";
int n;
int a[100];
cin>>n;
cout<<"\nEnter sorted array of n elements";
for(int i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"\nEnter element to search for";
int s;
cin>>s;
binarysearch(a,0,n,s);
}
