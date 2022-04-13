#ifndef EDGE_H
#define EDGE_H
#include <string>
#include <vector>

using namespace std;

class Edge {
public:
	Edge();									// default constructor 
	Edge(string fr, string to, double wet); // constructor
	string get_fr() const;
	string get_to() const;
	double get_wet() const;
	void set_fr(string fr);
	void set_to(string to);
	void set_wet(double wet);
private:
	string fr;		// source node
	string to;		// destination node
	double wet;		// weight
};

vector<Edge> read_edges(const char *fName);
void print_edges(vector<Edge> &edges);
map<string, int> make_node_index(vector<Edge> &edges);
void print_nodes(map<string, int> nodes);
vector<vector<double>> makeGraph(
	vector<Edge> &edges,
	map<string, int> &nodes);

void print_matrix(vector<vector<double>> &W);
#endif

