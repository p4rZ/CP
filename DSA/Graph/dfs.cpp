#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        map<int, bool> visited;
        map<int, list<int>> g;

        void addEdge(int v, int w)
        {
	        g[v].push_back(w); 
        }

        void DFS(int v)
        {
            visited[v] = true;
            cout<<v<<" ";
            list<int>::iterator i;
            for (i = g[v].begin(); i != g[v].end(); ++i)
                if (!visited[*i])
                    DFS(*i);
        }
};

int main()
{
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 9);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(9, 3);
	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";
	g.DFS(2);

	return 0;
}

