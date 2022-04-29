/*
<과제조건>
1. 노드의 갯수 n을 자동으로 구하는 것
2. 엣지의 갯수 m을 자동으로 구하는 것
3. 무작위로 인풋을 정렬하지 않은체 넣을 경우를 대비하여 edge의 길이에 따른 정렬
*/
////////////////////////
#include "Edge.h"
#include"alg_lecture.h"
//////////////////////////
//과제 N과 M은 알아서 구해야 하고
//get_index를 이걸 못쓰므로(왜나하면, 정렬떄문)
//v1 v2 edge 등을 정렬 되지 않은채 무작위로 밀어넣을 예정



int main() {
	cout << "<txt파일입력방식>" << "\n";
	const char* fName = "edges.txt";
	vector<Edge> edges = read_edges(fName);
	print_edge(edges);
	cout << "\n-----------크루스칼알고리즘 완료후-----------" << "\n";
	vector<Edge> krusEdges;
	int x= cnt_node(edges), y= edges.size();
//	cout << x << " " << y;
	kruskal(x, y, edges, krusEdges);
	print_edge(krusEdges);
	cout << "===============================================" << "\n";

	cout << "<하드코딩방식 or cin을 통한 입력방식>" << "\n";
	vector<Edge> E = get_edges();
	vector<Edge> F;
	print_edge(E);
	cout << "------------크루스칼알고리즘 완료후------------" << '\n';
	//node의 개수
	int n = cnt_node(E);
	//edge의 개수(7)
	int m = E.size();
	kruskal(n, m, E, F);
	print_edge(F);
	cout << "===============================================" << "\n";
	return 0;
}

//void kruskal (int n, vector<int>I_arr, vector<int> J_arr)
