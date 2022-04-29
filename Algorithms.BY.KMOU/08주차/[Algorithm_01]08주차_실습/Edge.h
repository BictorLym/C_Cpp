#ifndef EDGE_H
#define EDGE_H
#include<iostream>
#include<string>
#include<vector>


#include<map>
#include<algorithm>
using namespace std;
//using namespace edg;

class Edge {
private:
	string fr;
	string to;
	double wet;
public:
	Edge();
	Edge(string fr, string to, double wet);
	string get_fr() const;
	string get_to() const;
	double get_wet() const;
	void set_fr(string _fr);
	void set_to(string _to);
	void set_wet(double _wet);
};
vector<Edge> get_edges();
vector<Edge> read_edges(const char* fName);
void print_edge(vector<Edge>& F);

#endif
