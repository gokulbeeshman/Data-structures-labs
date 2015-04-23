#include<iostream>

using namespace std;

void towers(int num, char peg1, char peg2, char peg3)
{
if(num==1)
{
cout<<endl<<"Move disk 1 from "<<peg1<<" to "<<peg2;
}
else
{
towers(num-1,peg1,peg3,peg2);
cout<<endl<<"Move disk "<<num<<" from "<<peg1<<" to "<<peg2;
towers(num-1,peg3,peg2,peg1);
}
}

int main()
{
cout<<"Enter the no of disks";
int n;
cin>>n;
towers(n,'A','B','C');
}
