#include<iostream>

using namespace std;

class edge
{
public:
  int weight;
  int to;
  int fro;
  edge()
  {
    weight=to=fro=0;
  }
};
class priorityqueue
{
public:
  edge a[100];
  int size;

  priorityqueue()
  {
    size=-1;
  }
  void insert(edge n)
  {
    size++;
     a[size]=n;
  }
  
  edge extractmin()
  {
    edge min;
    min.weight=-1;
    if(size==-1)
      {
	return min;
      }
    min.weight=a[0].weight;
    int minindex=0;
    for(int i=0;i<=size;i++)
      {
	if(a[i].weight<min.weight)
	  {min=a[i];
	    minindex=i;}
      }
    for(int i=minindex;i<size;i++)
      {
	a[i]=a[i+1];
       
      }
    size--;
    return min;
  }
};

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

void prim(graph g,int n)
{
  int colour[g.nodeNo];
  for(int i=0;i<g.nodeNo;i++)
    {
      colour[i]='w';
    }
  int edgesadded=0;
  int current=n;
  priorityqueue q;
  while(1)
    {
      if(edgesadded==g.nodeNo-1)
	{
	  break;
	}
      edge temp;
      for(int i=0;i<g.nodeNo;i++)
	{
	  
	  if(g.adjMatrix[current][i]>0)
	    {
	      cout<<endl<<current<<" "<<i;
	      temp.to=current;
	      temp.fro=i;
	      temp.weight=g.adjMatrix[current][i];
	      q.insert(temp);
	    }
	  while(1)
	    {
	      temp=q.extractmin();
	      if((colour[temp.to]=='w')||(colour[temp.fro]=='w'))
		{
		  cout<<endl<<temp.to<<"--"<<temp.weight<<"-->"<<temp.fro;
		  return;
		  if(colour[temp.fro]=='w')
		    {
		      current=temp.fro;
		    }
		  else
		    {current=temp.to;}
		  colour[temp.to]='b';
		  colour[temp.fro]='b';
		  edgesadded++;
		  break;
		}
	    }
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
  prim(g,0);
}
