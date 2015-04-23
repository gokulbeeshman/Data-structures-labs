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
  void isComplete()
  {
    int flag=1;
    for(int i=0;i<nodeNo;i++)
      {
	for(int j=0;j<nodeNo;j++)
	  {
	    if(i==j)
	      {
		continue;
	      }
	    else
	      {
		if(adjMatrix[i][j]<1)
		  {
		    flag=0;
		    break;
		  }
	      }
	  }
      }
    if(flag)
      {cout<<"Graph is complete";}
    else
      cout<<"Graph is incomplete";
  }
  void degree(int n)
  {
    if(isDirected)
      {
	int count=0;
	for(int i=0;i<nodeNo;i++)
	  {
	    if(i==n)
	      {continue;}
	    if(adjMatrix[n][i]>0)
	      {
		count++;
	      }
	  }
	cout<<endl<<"Out degree is "<<count;
	count=0;
	for(int i=0;i<nodeNo;i++)
	  {
	    if(i==n)
	      {continue;}
	    if(adjMatrix[i][n]>0)
	      {
		count++;
	      }
	  }
	cout<<endl<<"In degree is "<<count;
      }
    else
      {
	int count=0;
	for(int i=0;i<nodeNo;i++)
	  {
	    if(i==n)
	      {continue;}
	    if(adjMatrix[n][i]>0)
	      {
		count++;
	      }
	  }
	cout<<endl<<"Degree is "<<count;
      }
  }
  int connection(int a,int b)
  {
    
    if(adjMatrix[a][b]>0)
      {
	cout<<"Connection exists";
	return 1;
      }
    else
      {
	for(int i=0;i<nodeNo;i++)
	  {
	    if(adjMatrix[a][i]>0)
	      {
		//colour[i]='g';
		if(connection(i,b))
		  return 1;
		
	      }
	  }
      }
    cout<<"Connection does not exist";
    return 0;
  }
};

int main()
{
  graph g;
  //cout<<"hellO";
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
  g.isComplete();
  g.degree(1);
  
  int x=g.connection(0,3);
 
}
