#include<iostream>

using namespace std;


class person
{
public:
int no;
int isdead;

person()
{
isdead=0;
}
};

int leaderfound(person a[100],int n)
{
int count=0;
for(int i=0;i<n;i++)
{
if(!a[i].isdead)
{
count++;
}
if(count>1)
break;
}

if(count==1){ return 1; }
else {return 0; }
}

int getnewtarget(person a[100], int n, int x, int target)
{
while(x>0)
{
target++;
 target%=n;
if(!a[target].isdead)
{
x--;
}
}
return target;
}
int findleader(person a[100], int n, int x)
{
int target=0;
target+=x;
target--;
a[target].isdead=1;
cout<<endl<<a[target].no<<" is dead";
while(1)
{

target=getnewtarget(a,n,x,target);
a[target].isdead=1;
cout<<endl<<a[target].no<<" is dead";
if(leaderfound(a,n))
{
for(int i=0;i<n;i++)
{
if(a[i].isdead==0)
return a[i].no;
}
}
}
}

int main()
{
cout<<"Enter the number of people";
int n;
cin>>n;
person a[100];
cout<<endl<<"Enter the numbers of n people";
for(int i=0;i<n;i++)
{
cin>>a[i].no;
}

cout<<endl<<"Enter the periodicity of removal";
int x;
cin>>x;
int leaderno=findleader(a,n,x);


cout<<"\nThe leader's no is"<<leaderno;
}
