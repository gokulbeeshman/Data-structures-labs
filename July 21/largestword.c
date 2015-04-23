#include<stdio.h>
#include<string.h>

int main()
{
char a[200];
printf("Enter the sentence");
gets(a);
char x[50][100];
int largest=0; int index;
int j=0,word=0;
for(int i=0;i<strlen(a);i++)
{
if(a[i]==' ')
{
j=0;
word++;
x[word][j]=a[i];
}
else
{
x[word][j]=a[i];
j++;

}
}
for(int i=0;i<=word;i++)
{
j=strlen(x[i]);
if(j>largest)
{
index=i;
largest=j;
}
}
printf("\n Largest word\n");
puts(x[index]);
}
