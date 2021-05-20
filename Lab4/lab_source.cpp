#include <iostream>
using namespace std;

class GraphWeighted
{
private:
	pair<int, pair<int, int>>* graph;
public:
	GraphWeighted();
	~GraphWeighted();
	void printGraph();
	GraphWeighted Kruskal(); 
	GraphWeighted Dijkstra();
};

int main()
{
	
}