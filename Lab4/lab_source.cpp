#include <iostream>
using namespace std;

class GraphWeighted
{
private:
	pair<int, pair<int, int>>* graph;
	int v, m;
public:
	GraphWeighted()
	{
		cout << "Input number of vertices and number of edges:\n";
		cin >> v >> m;
		graph = new pair<int, pair<int, int>>[m];
		cout << "Now input all " << m << "edges in format: weight vertice1 vertice2,\n";
		for(int i = 0; i < m; ++i)
		{
			int w, u, v;
			cin >> w >> u >> v;
			graph[i] = {w, {u, v}};
		}
	}
	~GraphWeighted()
	{
		delete[] graph;
	}
	void printGraph()
	{
		for(int i = 0; i < m; ++i)
		{
			cout << graph[i].first << ": "
			<< graph[i].second.first << ' '
			<< graph[i].second.second << '\n'; 
		}
	}
	GraphWeighted Kruskal(); 
	GraphWeighted Dijkstra();
};

int main()
{
	
}