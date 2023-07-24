#include<iostream>
#include<vector>
#include<list>
#include<utility>
#define MAX 100000

using namespace std;

class Graph {
	int num_vertex;
	vector<list<pair<int, int> > > adj;
	vector<int> distance;
public:
	Graph():num_vertex(0){};
	Graph(int vertex) {
		num_vertex = vertex;
		adj.resize(vertex);
	}
	void add(int from, int to, int length) {
		adj[from].push_back(make_pair(to, length));
	}
	void print_dist(vector<int> distance) {
		for (int i = 0; i < num_vertex; i++) {
			//x for can't arrive
			if (distance[i] == MAX)	cout << "x ";
			else cout << distance[i] << " ";
		}
		cout << "\n\n";
	}
	void bellmanford(int start) {
		//Initialize
		distance.resize(num_vertex);
		for (int i = 0; i < num_vertex; i++) {
			distance[i] = MAX;
		}
		distance[start] = 0;
		//Relax
		for (int i = 0; i < num_vertex - 1; i++) {
			for (int j = 0; j < num_vertex; j++) {
				for (list<pair<int, int> >::iterator it = adj[j].begin(); it != adj[j].end(); it++) {
					//j for from, first for to, second for length
					if (distance[(*it).first] > distance[j] + (*it).second) {
						distance[(*it).first] = distance[j] + (*it).second;
					}
				}
			}
		}
		//Check negative cycle
		for (int i = 0; i < num_vertex; i++) {
			for (list<pair<int, int> >::iterator it = adj[i].begin(); it != adj[i].end(); it++) {
				// i for from, first for to, second for length
				if (distance[(*it).first] > distance[i] + (*it).second) {
					cout << "Negative cycle!\n";
					return;
				}
			}
		}
		//Print
		cout << "distance from vertex " << start << " to vertex 0 ~ " << num_vertex - 1 << ":\n";
		print_dist(distance);
		return;
	}
};

int main() {
	Graph g(4);
	g.add(0, 1, 5);
	g.add(0, 3, -1);
	g.add(2, 0, 2);
	g.add(2, 3, 4);
	//case 1:
	g.bellmanford(2);

	//case 2:
	g.bellmanford(0);

	//case 3:
	Graph g2(4);
	g2.add(0, 1, 5);
	g2.add(0, 3, -6);
	g2.add(2, 0, 2);
	g2.add(3, 2, 3);
	g2.bellmanford(0);
	
}
