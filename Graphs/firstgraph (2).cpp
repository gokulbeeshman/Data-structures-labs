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

void findifcomplete(graph g)
{
}

void degreecheck(graph g, int n)
{
}

void checkpath(graph g,int n1,int n2)
{
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
   findifcomplete(g);
   int nodeno,int nodeno2;
   cout<<"Enter node to check degree";
   cin>>nodeno;
   degreecheck(g,nodeno);
   cout<<"Enter two vertices";
   cin>>nodeno>>nodeno2;
   checkpath(g,nodeno,nodeno2);
}
