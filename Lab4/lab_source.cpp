#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define INF 1000000000000000000

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
		cout << "Now input all " << m << " edges in format: weight vertice1 vertice2,\n";
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
		graph = new pair<int, pair<int, int>>[m];
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
		if(i < v)
		{
			graph[i] = e;
		}else cout << "Edge out of graph!\n";
		
	}

	GraphWeighted Kruskal()
	{
		if(m < v - 1)
			cout << "Graph is not connected!\n";
		sort(graph, graph + m);
		disjoint_set ds(v);
		GraphWeighted res(v, v - 1);


		for(int i = 0, j = 0; i < m && j < v - 1; ++i)
		{
			if(!ds.same(graph[i].second.first, 
				graph[i].second.second))
			{
				ds.unite(graph[i].second.first, 
				graph[i].second.second);
				res.setEdge(j++, graph[i]);
			}
		}

		res.printGraph();
		return res;
	}
	vector<int> Dijkstra(int start)
	{
		vector<vector<pair<int, int>>> g(v);
		for(int i = 0; i < m; ++i)
		{
			int w, u, v;
			w = graph[i].first;
			u = graph[i].second.first;
			v = graph[i].second.second;
			g[u].push_back({w, v});
			g[v].push_back({w, u});
		}

		priority_queue<pair<long long, int>> q;
		vector<long long> d(v, INF);
		q.push({0, start});
		d[start] = 0;
		vector<int> previous(v);
		previous[start] = start;

		while(!q.empty())
		{
			auto p = q.top();
			q.pop();
			if(-p.first > d[p.second]) continue;
			
			for(auto to : g[p.second])
			{
				if(d[p.second] + to.first < d[to.second])
				{
					d[to.second] = d[p.second] + to.first;
					q.push({-d[to.second], to.second});
					previous[to.second] = p.second;
				}
			}

		}

		for(auto el : d)
			cout << el << ' ';
		cout << '\n';

		

		return previous;
	}
};

int main()
{
	GraphWeighted a;
	a.Kruskal();
	a.Dijkstra(0);
}