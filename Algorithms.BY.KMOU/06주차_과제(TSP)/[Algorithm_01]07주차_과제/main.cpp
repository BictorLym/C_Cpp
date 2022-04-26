#include<iostream>

#include"Edge.h"

using namespace std;

int main() {
	const char* fName = "edges.txt";
	vector<Edge> edges = read_edges(fName);
	print_edges(edges);
	cout << "\n";

	map<string, int> nodes = make_node_index(edges);
	print_nodes(nodes);
	cout << "\n";

	vector<vector<double>> W = makeGraph(edges, nodes);
	print_matrix(W);
	cout << "\n";
	
	int n = nodes.size()-1;
	int minlength = INT_MAX;
	vector<vector<double>> P;
	//cout << "Pmatrix \n"; print_matrix(P);
	travel(n, W, P, minlength);
	cout <<"\n최단거리:" << minlength;
	cout << "\n최단경로"; path(P);
	return 0;
}