#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <stdio.h>

#include "Tokenizer.h"
#include "Edge.h"
void floyd(int n, vector< vector<double>>& d);
int main() {
	const char* fName = "edges.txt";
	vector<Edge> edges = read_edges(fName);
	//print_edges(edges);
	map<string, int> nodes = make_node_index(edges);
	//print_nodes(nodes);

	vector<vector<double>> W = makeGraph(edges, nodes);
	floyd(5, W);
	print_matrix(W);

	return 0;
}
void floyd(int n, vector< vector<double>>& d)
{
	//int n = d.size() - 1;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}