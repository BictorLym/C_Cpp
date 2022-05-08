#ifndef ALG_lecture_H
#define ALG_lecture_H

#include"Edge.h"
void initial(int U[], int n);
void merge(int U[], int p, int q);
bool equal(int p, int q);
int find(int U[], int i);
bool compareWeight(const Edge& n1, const Edge& n2);
bool isIn(vector<string>tmp, string str);
int cnt_node(vector<Edge>& E);


int get_index(string s);
void kruskal(int n, int m, vector<Edge>& E, vector<Edge>& F);
void kruskal2(int n, int m, vector<Edge>& E, vector<Edge>& F);

int find_parent(int parent[], int x);
void union_parent(int parent[], int a, int b);
#endif
