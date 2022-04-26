#include <string>
#include <vector>

#include <fstream>
#include <iostream>
#include <map>

#include "Edge.h"

#include "Tokenizer.h"
#include "trim.h"
using namespace std;


Edge::Edge() {}

Edge::Edge(string _fr_, string _to_, double _wet_) {
	fr = _fr_;
	to = _to_;
	wet = _wet_;
}

string Edge::get_fr() const {
	return fr;
}

string Edge::get_to() const {
	return to;
}

double Edge::get_wet() const {
	return wet;
}

void Edge::set_fr(string _fr_) {
	fr = _fr_;
}

void Edge::set_to(string _to_) {
	to = _to_;
}

void Edge::set_wet(double _wet_) {
	wet = _wet_;
}


vector<Edge> read_edges(const char* fName)
{
	vector<Edge> edges;
	string line;
	ifstream inputFile(fName);

	if (!inputFile.is_open()) {
		cerr << "파일을 열 수 없습니다."
			<< fName << " " << '\n';
		exit(EXIT_FAILURE);
	}
	else {
		Tokenizer str;
		string token;
		edges.push_back(Edge("v0", "v1", 0));
		edges.push_back(Edge("v0", "v2", 0));
		edges.push_back(Edge("v0", "v3", 0));
		edges.push_back(Edge("v0", "v4", 0));
		edges.push_back(Edge("v0", "v5", 0));
		edges.push_back(Edge("v1", "v0", 0));
		edges.push_back(Edge("v2", "v0", 0));
		edges.push_back(Edge("v3", "v0", 0));
		edges.push_back(Edge("v4", "v0", 0));
		edges.push_back(Edge("v5", "v0", 0));
		while (getline(inputFile, line)) {
			str.set(line, "#");
			string fr = str.next(); fr = trim(fr);
			string to = str.next(); to = trim(to);
			string _wet = str.next(); _wet = trim(_wet);
			double wet = atof(_wet.c_str());
			edges.push_back(Edge(fr, to, wet));
		}
	}
	return edges;
}

void print_edges(vector<Edge>& edges) {
	vector<Edge>::iterator it;
	for (it = edges.begin(); it != edges.end(); ++it) {
		cout << "fr:" << it->get_fr() << "  "
			 << "to:" << it->get_to() << "  "
			 << "wet:" << it->get_wet() << "\n";
	}
}
map<string, int> make_node_index(vector<Edge>& edges) {
	map<string, int> n2i;
	int i;
	int index = 0;
	for (int i = 0; i < edges.size(); i++) {
		string fr = edges[i].get_fr();
		string to = edges[i].get_to();
		if (n2i.find(fr) == n2i.end()) {
			n2i.insert(pair<string, int>(fr, index));
			index++;
		}
		if (n2i.find(to) == n2i.end()) {
			n2i.insert(pair<string, int>(to, index));
			index++;
		}
	}
	return n2i;
}
void print_nodes(map<string, int> nodes) {
	map<string, int>::iterator it;
	for (it = nodes.begin(); it != nodes.end(); ++it)
		cout << it->first << " => "
		<< it->second << endl;
}

vector<vector<double>> makeGraph(vector<Edge>& edges, map<string, int>& nodes)
{
	int n = nodes.size();
	int m = edges.size();
	//cout << m << endl;
	vector<vector<double>> W;
	int i, j;
	for (i = 0; i < n; i++){
		vector<double> row(nodes.size(), DBL_MAX);
		W.push_back(row);
	}
	for (i = 0; i < n; i++){
		W[i][i] = 0;
	}

	for (i = 0; i < edges.size(); i++) {
		string fr = edges[i].get_fr();
		string to = edges[i].get_to();
		double wet = edges[i].get_wet();
		W[nodes[fr]][nodes[to]] = wet;
	}
	return W;
}

void print_matrix(vector<vector<double>>& W)
{
	for (int i = 0; i < W.size(); i++) {
		for (int j = 0; j < W[i].size(); j++) {
			cout << W[i][j] << " ";
		}
		cout << endl;
	}
}
void print_matrix1(vector<vector<double>>& W)
{
	for (int i = 1; i < W.size(); i++) {
		for (int j = 0; j < W[i].size(); j++) {
			cout << W[i][j] << " ";
		}
		cout << endl;
	}
}
void travel(int n, const vector<vector<double>>& W, vector<vector<double>>& P, int& minlength)
{
	int i, j, k;
	//부분집합의 갯수
	int cntSubset = pow(2, n - 1);
	//D[1, 2, ... , n][subset of V - {v1}];
	vector<vector<double>> D(n+1, vector<double>(cntSubset,0));
	P = D;
	//D[1,2,3,4,5][0,1,2,3,....14,15]
	for (i = 2; i <= n; i++){
		D[i][0] = W[i][1];
	}
	print_matrix1(D);
	int A = 0, minJ = -1;
	// V- {v_1, v_j}, k는 V의 v1과 vj를 뺀 최대 원소의 갯수
	for (k = 1; k <= n-2; k++) {
		//V-{v1}을 만족하며 마디가 k개인 모든 부분집합 A
		for (A = 0; A < cntSubset; A++) {
			if (count1(A) == k) {
				//i는 1이 아니고, v_i를 포함하지는 않는 A를 만족하는 i
				for (i = 2; i <= n; i++) {
					if (!contain(i, A)) {
						//D[i][V-{v1}] = minimum(W[i][j] + D[j][ V-{vj} ])
						D[i][A] = minimum(n, i, minJ, A, W, D);
						//cout << "k:" << k << "  A:" << A << "  i:" << i << "  D[i][A]:" << D[1][A] << endl;
						P[i][A] = minJ;
						//cout << "matrixD\n"; print_matrix1(D)
					}
;
				}
			}

		}
	}
	cout << "\nDmatrix\n";print_matrix1(D);
	cout << "\nPmatrix\n"; print_matrix1(P);
	//D[1][V-{v1}] = minimum(W[1][j] + D[j][V-{v1, vj}])	(2<=j<=n)
	D[1][cntSubset - 1] = minimum(n, 1, minJ, 15, W, D);
	P[1][cntSubset - 1] = minJ;

	minlength = D[1][cntSubset-1];
	cout << "\nDmatrix\n"; print_matrix1(D);
	cout << "\nPmatrix\n"; print_matrix1(P);
}


void path(vector<vector<double>>& P)
{
	int n = P[1].size() - 1;
	static int staticN = n;
//	cout << n; //n==A==15
	int A = n;
	int k = 0;
	do {
		n >>= 1;
		k++;
	} while (n != 0);
	static int staticK = k;
//	cout << k;	//k==4(비트수)
	int tmp = P[1][A];
	int i = 1, j = A;
//	cout << " " << tmp;	//tmp==4
	vector<int> ans(k+1,0);
	do{
		tmp = P[i][j];
		i = tmp;
		j = diff(j, tmp);
		ans[k] = tmp;
		tmp = P[i][diff(j, tmp)];
	} while (--k);
	cout << "v1->";
	for (int k = staticK; k > 0; k--) {
		cout << "v" << ans[k] << "->";
	}
	cout << "v1";
}
int minimum(int n, int i, int& minJ, int A, const vector<vector<double>>& W, vector<vector<double>>& D)
{
	int minValue = INT_MAX;
	minJ = 1;
	for (int j = 2; j <= n; j++) {
		if (contain(j, A)) {
			int value = W[i][j] + D[j][diff(A, j)];
			//cout << value << " ";
			if (minValue > value) {
				minValue = value;
				minJ = j;
			}
		}

		//cout << minV << endl;
	}
	return minValue;
}
//A에서 j의 비트를 뺀값
int diff(int A, int j){
	return(A & ~(1 << (j - 2)));
}
//i의 비트가 포함되어 있는지
bool contain(int i, int A){
	return(A & (1 << (i - 2))) != 0;
}
//비트수 확인
int count1(int A)
{
	int cnt = 0;
	while (A != 0) {
		if (A & 1)	cnt++;
		A >>= 1;
	}

	return cnt;
}

