#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class Compare
{	
public:
	bool operator () (pair<int, int> a, pair<int, int> b)
	{
		if (a.second > b.second)
			return true;
		else
			return false;
	}
};

int main()
{
	int max_val = 99999999;
	vector< vector < pair<int, int> > > graph;
	priority_queue<pair<int, int>, vector< pair<int, int> >, Compare > queue;

	int vertex_num , edge_num, start_vertex;
	cin >> vertex_num >> edge_num>> start_vertex;
	graph.resize(vertex_num + 1);

	int dijkstra_arr[20001] = { 0, };
	fill(dijkstra_arr,dijkstra_arr+ vertex_num+1,max_val);
	dijkstra_arr[start_vertex] = 0;

	for (int i = 0; i < edge_num; i++)
	{
		int start_node, end_node, weight;
		cin >> start_node >> end_node >> weight;
		graph[start_node].push_back(pair<int,int>(end_node, weight));
	}

	for (int i = 1; i <= vertex_num; i++)
	{
		if (i == start_vertex)
			queue.push(pair<int, int>(i,0));
		else
			queue.push(pair<int, int>(i, max_val));
	}

	while (!queue.empty())
	{
		int top_vertex = queue.top().first;
		int top_distance = queue.top().second;
		queue.pop();

		if (top_distance <= dijkstra_arr[top_vertex])
		{
			for (int i = 0; i < graph[top_vertex].size(); i++)
			{
				int adjacent_vertex = graph[top_vertex][i].first;
				int adjacent_weight = graph[top_vertex][i].second;
				if (dijkstra_arr[adjacent_vertex] > dijkstra_arr[top_vertex] + adjacent_weight)
				{
					dijkstra_arr[adjacent_vertex] = dijkstra_arr[top_vertex] + adjacent_weight;
					queue.push(pair<int, int>(adjacent_vertex, dijkstra_arr[adjacent_vertex]));
				}
			}
		}
	}

	for (int i = 1; i <= vertex_num; i++)
	{
		if (dijkstra_arr[i] == max_val)
			cout << "INF" << endl;
		else
			cout << dijkstra_arr[i] << endl;
	}
	return 0;
}
