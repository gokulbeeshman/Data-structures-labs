#include<iostream>

using namespace std;

class graph
{
public:
  int isDirected;
  int nodeNo;
  int edgeNo;
  int adjMatrix[100][100];

  graph()
  {
    isDirected=0;
    nodeNo=0;
    edgeNo=0;
    for(int i=0;i<100;i++)
      {
	for(int j=0;j<100;j++)
	  {
	    adjMatrix[i][j]=0;
	  }
      }
  }

  void addEdge(int node1,int node2, int w=1)
  {
    if(isDirected)
      {
	if((node1<nodeNo)&&(node2<nodeNo))
	  {
	    adjMatrix[node1][node2]=w;
	  }
      }
    else
      {
	if((node1<nodeNo)&&(node2<nodeNo))
	  {
	    adjMatrix[node1][node2]=w;
	    adjMatrix[node2][node1]=w;
	  }
      }
  }

  void addNode()
  {
    adjMatrix[nodeNo][nodeNo]=-1;
    nodeNo++;
  }

  void printAdjMatrix()
  {
    cout<<"  ";
    for(int i=0;i<nodeNo;i++)
      {cout<<i<<"  ";}
    cout<<endl;
    for(int i=0;i<nodeNo;i++)
      {
	cout<<i<<"  ";
	for(int j=0;j<nodeNo;j++)
	  {
	    if(adjMatrix[i][j+1]!=-1)
	    cout<<adjMatrix[i][j]<<"  ";
	    else cout<<adjMatrix[i][j]<<" ";
	  }
	cout<<endl;
      }
  }
};

void sort(int a[],int size)
{
  int temp;
  for(int i=0;i<size;i++)
    {
      for(int j=i;i<size;j++)
	{
	  if(a[j]<a[i])
	    {
	      temp=a[j];
	      a[j]=a[i];
	      a[i]=temp;
	    }
	}
    }
}

void kruskal(graph g)
{
  char colour[g.nodeNo];
  for(int i=0;i<g.nodeNo;i++)
    {
      colour[i]='w';
    }
 
  
  int edgesadded=0;
  int icoordinate=0;
  int jcoordinate=0;
  while(1)
    {
      int mineedge=30000;
      if(edgesadded==g.nodeNo-1)
	break;
      for(int i=0;i<g.nodeNo;i++)
	{
      for(int j=0;j<g.nodeNo;j++)
	{
	  if((g.adjMatrix[i][j]>0)&&(g.adjMatrix[i][j]<mineedge))
	    {
	      mineedge=g.adjMatrix[i][j];
	      icoordinate=i;
	      jcoordinate=j;
	    }
	}
	}
  if((colour[icoordinate]=='w')||(colour[jcoordinate]=='w'))
    {
      cout<<endl<<icoordinate<<"--"<<mineedge<<"-->"<<jcoordinate;
      g.adjMatrix[icoordinate][jcoordinate]=-1;
      edgesadded++;
      //cout<<"yo";
      colour[icoordinate]='b';
      colour[jcoordinate]='b';
     
    }
  else
    {
      g.adjMatrix[icoordinate][jcoordinate]=-1;
    }
    } 
}

int main()
{
  graph g;
  cout<<"hellO";
  g.addNode();
  g.addNode();
  g.addNode();
  g.addNode();
  g.addNode();
  g.addEdge(0,1,1);
  g.addEdge(1,3,4);
  g.addEdge(1,2,2);
  g.addEdge(2,4,5);
  g.addEdge(4,0,2);
  //g.printAdjMatrix();
  kruskal(g);
 
}
