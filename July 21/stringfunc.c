#include<stdio.h>
#include<string.h>


int main()
{
char a[100],b[100];
gets(a);
gets(b);
int choice;
printf("1. Concatenate 2. Compare 3. Length");
scanf("%d",&choice);


puts(a);
puts(b);
int length;
if(choice==1)
{
int length1,length2;
for(int i=0;a[i]!='\0';i++)
{
length1=i+1;
}
for(int i=0;b[i]!='\0';i++)
{
length2=i+1;
}
char c[200];
for(int i=0;i<length1;i++)
{
c[i]=a[i];
}
for(int i=0;i<length2;i++)
{
c[length1+i]=b[i];
}
c[length1+length2]='\0';
puts(c);
} 
if(choice==2)
{
int length1,length2;
for(int i=0;a[i]!='\0';i++)
{
length1=i+1;
}
for(int i=0;b[i]!='\0';i++)
{
length2=i+1;
}
if(length1!=length2)
printf("-1");
else
{
int diff=0;
for(int i=0;i<length1;i++)
{
diff+=a[i]-b[i];
}
printf("%d",diff);
}
}
if(choice==3)
{
for(int i=0;b[i]!='\0';i++)
{
length=i+1;
}
printf("%d",length);
}


}
