#include<iostream>

using namespace std;

int time1;
int isCycle;
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

void dfs_visit(graph g,int u,char colour[],int startTime[],int endTime[])
{
  time1++;
  startTime[u]=time1;
  for(int i=0;i<g.nodeNo;i++)
    {
      if((g.adjMatrix[u][i]>0)&&(colour[i]=='w'))
	{
	  colour[i]='g';
	  dfs_visit(g,i,colour,startTime,endTime);
	}
      if((g.adjMatrix[u][i]>0)&&(colour[i]=='g'))
	{
	  isCycle=1;
	 
	}
    }
    time1++;
    endTime[u]=time1;  
    cout<<endl<<u<<" Time: "<<startTime[u]<<"/"<<endTime[u]; 
    colour[u]='b';
}

void dfs(graph g)
{
  time1=0;
  isCycle=0;
  char colour[g.nodeNo];
  int startTime[g.nodeNo];
  int endTime[g.nodeNo];
  for(int i=0;i<g.nodeNo;i++)
    {
      colour[i]='w';
      startTime[i]=-1;
      endTime[i]=-1;
    }
  for(int i=0;i<g.nodeNo;i++)
    {
      
      if(colour[i]=='w')
	{
	  colour[i]='g';
	  dfs_visit(g,i,colour,startTime,endTime);
	}
    }
  if(isCycle)
    {
      cout<<endl<<"There exists cycle(s) in graph";
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
  //  g.addEdge(4,0);
  // g.printAdjMatrix();
  dfs(g);
}
