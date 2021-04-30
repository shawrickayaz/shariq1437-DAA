#include<iostream>
#include<cstdlib>
#include <list>

using namespace std;

int cost[10][10],i,j,k,n,qu[10],front,rare,v,visit[10],visited[10];

int main()
class Graph
{
	int V; // No. of vertices


	list<int> *adj;
public:
	Graph(int V); 
	void addEdge(int v, int w);

	void BFS(int s,int strt);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s,int strt)  // s represents the vertice you want to start search with
{
    int m;
    cout <<"\nEnter the no of vertices  ";
    cin >> n;
    cout <<"\nEnter the no of edges  ";
    cin >> m;
    cout <<"\nEDGES \n";
    for(k=1;k<=m;k++)
    {
        cin >>i>>j;
        cost[i][j]=1;
    }

    cout <<"\nEnter the initial vertex\n";
    cin >>v;
    cout <<"\nVisitied vertices\n";
    cout << v;
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                qu[rare++]=j;
            }
        }
        v=qu[front++];
        cout<<v << " ";
        k++;
        visit[v]=0; visited[v]=1;
    }
    return 0;
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;

	while(!queue.empty())
	{
		s = queue.front();
		cout << s + strt << " ";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}


int main()
{
	int nv,ne,start,dir,help,ep,stf,ext;
	begin:
	cout<<"Enter the no. of vertices : ";
	cin>>nv;

	cout<<"Enter the no. of edges : ";
	cin>>ne; 

	if(nv<0||ne<0){
		cout<<"\n\nError : no. of vertices or edges cannot be zero.\n\n";
		goto begin;
	}
	cout<<"Enter the no. from which graph starts : ";
	cin>>start;
	cout<<"Is the graph directional (0 = no/other number for yes) : ";
	cin>>dir;
	Graph g(nv);
	cout<<"Press 0 to enter edges manually or Press 1 to enter edges with help : ";
	cin>>help;
	cout<<endl;
	if(help==1){
    if(dir==0){
    	for(int i = 0;i<nv;i++){
    		for(int j = i;j<nv;j++){
    			cout<<"Is there a edge between "<<i+start<<" and "<<j+start<<" vertices :(0=n/1=y) : ";
    			cin>>ep;
    			if(ep==1){
    			g.addEdge(i,j);
				g.addEdge(j,i);	
				}
			}
		}
	}
	else{
		for(int i = 0;i<nv;i++){
    		for(int j = 0;j<nv;j++){
    			cout<<"Is there a edge between "<<i+start<<" and "<<j+start<<" vertices :(0=n/1=y) : ";
    			cin>>ep;
    			if(ep==1){
    			g.addEdge(i,j);	
				}
			}
		}
	}
   } 
   else if(help ==0){
	if(dir==0){
		while(ne!=0){
			int i,j;
			cout<<"Enter both vertices of an edge with a space between them : ";
			cin>>i>>j;
			g.addEdge(i-start,j-start);
			g.addEdge(j-start,i-start);
			ne--;
		}
	}
	else{
		while(ne!=0){
			int i,j;
			cout<<"Enter starting and ending vertices of an edge with a space between them : ";
			cin>>i>>j;
			g.addEdge(i-start,j-start);
			ne--;
		}
	}
   }  

    cout<<"\n\nEnter the vertex from which you want to start the traversal : ";
    cin>>stf;
	cout << "\n\nFollowing is Breadth First Traversal "
		<< "(starting from vertex "<<stf<<") :   ";
	g.BFS(stf-start,start);
  cout<<"\n\nPress 1 to search again / any other key to exit : ";
  cin>>ext;
  if(ext == 1)
     goto begin;
	return 0;
}
