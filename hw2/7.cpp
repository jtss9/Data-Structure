#include<iostream>
#include<list>
using namespace std;

class Graph {
	int vertex;
	list<int>* adj;
public:
	Graph(int vertex) {
		this->vertex = vertex;
		adj = new list<int>[vertex];
	}
	void add(int value, int index) {
		adj[value].push_back(index);
	}
	void bfs(int s) {
		bool* visited = new bool[vertex];
		for (int i = 0; i < vertex; i++) {
			visited[i] = false;
		}

		list<int> queue;
		visited[s] = true;
		queue.push_back(s);
		list<int>::iterator i;
		while (!queue.empty()) {
			s = queue.front();
			cout << s << " ";
			queue.pop_front();
			for (i = adj[s].begin(); i != adj[s].end(); i++) {
				if (!visited[*i]) {
					visited[*i] = true;
					queue.push_back(*i);
				}
			}
		}
	}
};

int main() {
	Graph g(5);
	g.add(0, 1);
	g.add(0, 2);
	g.add(0, 3);
	g.add(1, 2);
	g.add(1, 4);
	g.add(2, 0);
	g.add(3, 2);
	g.add(4, 4);
	cout << "BFS from vertex 2: ";
	g.bfs(2);
}