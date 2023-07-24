#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adj_list[105];	//input the graph with adjancy list
int in_degree[105];	// calculate the indegree in advance
int n;	// n nodes in the DAG

class TopoIterator {
public:
	void topo_sort() {
		queue<int> q;
		vector<int> order;
		for (int i = 0; i < n; i++) {
			if (in_degree[i] == 0)	q.push(i);
		}
		while (q.size()) {
			int tmp = q.front();
			q.pop();
			order.push_back(tmp);
			for (int i = 0; i < adj_list[tmp].size(); i++) {
				int next = adj_list[tmp][i];
				in_degree[next]--;
				if (in_degree[next] == 0) {
					q.push(next);
				}
			}
		}
		for (int i = 0; i < order.size(); i++) {
			cout << order[i] << " ";
		}
		cout << "\n";
	}
};