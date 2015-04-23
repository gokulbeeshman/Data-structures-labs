#include<iostream>

using namespace std;

class stack
{
public:
  int top1;
  int a[100];
  stack()
  {
    top1=-1;
  }
  void push(int n)
  {
    top1++;
    a[top1]=n;
  }
  int top()
  {
    if(top1!=-1)
      {
	return a[top1];
      }
  }
  int pop()
  {
    top1--;
    return a[top1+1];
  }
  int isEmpty()
  {
    if(top1==-1)
      return 1;
    else 
      return 0;
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
    isDirected=1;
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

void bfs(graph g,int start=0)
{
  char colour[g.nodeNo];
  int distance[g.nodeNo];
  for(int i=0;i<g.nodeNo;i++)
    {
  colour[i]='w';
  distance[i]=-1;
    }
  colour[start]='g';
  stack  s;
 s.push(start);
 distance[start]=0;
 //cout<<s.isEmpty();
 //int x=s.pop();
 //cout<<endl<<x<<endl<<s.isEmpty();
 //cout<<endl<<"yolo "<<distance[0]<<endl;
 while(!s.isEmpty())
   {
     int x=s.pop();
     cout<<endl<<x<<" Dist: "<<distance[x];
     for(int i=0;i<g.nodeNo;i++)
       {
	 if((g.adjMatrix[x][i]>0)&&(colour[i]=='w'))
	   {
	     s.push(i);
	     colour[i]='g';
	     distance[i]=distance[x]+1;
	   }
       }
     colour[x]='b';
   }
}

int main()
{
  graph g;
  // cout<<"hellO";
  g.addNode();
  g.addNode();
  g.addNode();
  g.addNode();
  g.addNode();
  g.addEdge(0,1);
  g.addEdge(1,3);
  g.addEdge(1,2);
  g.addEdge(2,4);
  g.addEdge(4,0);
  // g.printAdjMatrix();
   bfs(g);
}
