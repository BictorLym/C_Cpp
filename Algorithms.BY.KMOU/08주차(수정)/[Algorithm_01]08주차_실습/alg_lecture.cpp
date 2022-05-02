#include"alg_lecture.h"

void initial(int U[], int n) {
	for (int i = 0; i <= n; i++) {
		U[i] = i;
	}
}
void merge(int U[], int p, int q) {
	if (p < q) {
		U[q] = p;
	}
	else {
		U[p] = q;
	}
}
bool equal(int p, int q) {
	return p == q;
}
int find(int U[], int i) {
	int j = i;
	while (U[j] != j) {
		j = U[j];
	}
	return j;
}
bool compareWeight(const Edge& n1, const Edge& n2) {
	return n1.get_wet() < n2.get_wet();
}
bool isIn(vector<string>tmp, string str) {
	vector<string>::iterator it;
	for (it = tmp.begin(); it != tmp.end(); it++) {
		if (*(it) == str) {
			return 1;
		}
	}
	return 0;
}
int cnt_node(vector<Edge>& E) {
	vector<string> tmp;
	vector<Edge>::iterator it;

	for (it = E.begin(); it != E.end(); it++) {
		string str = it->get_fr();
		if (!isIn(tmp, str)) {
			tmp.push_back(it->get_fr());
		}
		str = it->get_to();
		if (!isIn(tmp, str)) {
			tmp.push_back(it->get_to());
		}
	}
	int cnt = tmp.size();
	return cnt;
}
int get_index(string s) {
	return atoi(s.c_str());
}
void kruskal(int n, int m, vector<Edge>& E, vector<Edge>& F) {
	//node의 개수
	n = cnt_node(E);
	//edge의 개수(7)
	m = E.size();
	sort(E.begin(), E.end(), compareWeight);
	//인덱스
	int i, j;
	//포인터
	int p, q;
	//int U[6];
	int* U = (int*)malloc(sizeof(int)*(n+1));
	initial(U, n);
	int count = 0;
	for (int k = 0; k <= E.size(); k++) {
		Edge e = E[k];
		i = get_index(e.get_fr());
		//i = stoi(e.get_fr());
		j = get_index(e.get_to());
		//j = stoi(e.get_to());

		p = find(U, i);
		q = find(U, j);
		if (!equal(p, q)) {
			merge(U, p, q);
			F.push_back(e);
			count++;
		}
		if (count == n - 1)	break;
	}
}
void kruskal2(int n, int m, vector<Edge>& E, vector<Edge>& F)
{
	map<string, int> nodes = make_node_index(E);
	//node의 개수
	n = nodes.size();
	//edge의 개수(7)
	m = E.size();
	sort(E.begin(), E.end(), compareWeight);
	//인덱스
	int i, j;
	//포인터
	int p, q;
	//int U[6];
	int* U = (int*)malloc(sizeof(int) * (n + 1));
	initial(U, n);
	int count = 0;
	for (int k = 0; k <= m; k++) {
		Edge e = E[k];
		
		i = nodes[e.get_fr()];
		j = nodes[e.get_to()];
		
		p = find(U, i);
		q = find(U, j);
		if (!equal(p, q)) {
			merge(U, p, q);
			F.push_back(e);
			count++;
		}
		if (count == n - 1)	break;
	}
	
}