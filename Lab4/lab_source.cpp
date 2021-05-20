#include <iostream>
#include <algorithm>
using namespace std;

class disjoint_set
{
private:
	int* link;
	int* size;
	int n;
public:
	disjoint_set(int len)
	{
		n = len;
		link = new int[n];
		size = new int[n];
		for(int i = 0; i < n; ++i)
		{
			link[i] = i;
			size[i] = 1;
		}
	}

	~disjoint_set()
	{
		delete[] link;
		delete[] size;
	}

	int find(int x)
	{
		while(x != link[x]) x = link[x];
		return x;
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}

	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if(size[a] < size[b]) swap(a, b);
		size[a] += size[b];
		link[b] = a;

	}
	
};

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

	GraphWeighted(int vertices, int edges)
	{
		v = vertices;
		m = edges;
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
	void setEdge(int i, pair<int, pair<int, int>> e)
	{
		graph[i] = e;
	}

	GraphWeighted Kruskal()
	{
		if(m < v - 1)
			cout << "Graph is not connected!\n";
		sort(graph, graph + m);
		disjoint_set ds(v - 1);
		GraphWeighted res();

	}
	GraphWeighted Dijkstra();
};

int main()
{
	
}