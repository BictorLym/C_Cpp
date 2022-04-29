/*
<��������>
1. ����� ���� n�� �ڵ����� ���ϴ� ��
2. ������ ���� m�� �ڵ����� ���ϴ� ��
3. �������� ��ǲ�� �������� ����ü ���� ��츦 ����Ͽ� edge�� ���̿� ���� ����
*/
////////////////////////
#include "Edge.h"
#include"alg_lecture.h"
//////////////////////////
//���� N�� M�� �˾Ƽ� ���ؾ� �ϰ�
//get_index�� �̰� �����Ƿ�(�ֳ��ϸ�, ���ċ���)
//v1 v2 edge ���� ���� ���� ����ä �������� �о���� ����



int main() {
	cout << "<txt�����Է¹��>" << "\n";
	const char* fName = "edges.txt";
	vector<Edge> edges = read_edges(fName);
	print_edge(edges);
	cout << "\n-----------ũ�罺Į�˰��� �Ϸ���-----------" << "\n";
	vector<Edge> krusEdges;
	int x= cnt_node(edges), y= edges.size();
//	cout << x << " " << y;
	kruskal(x, y, edges, krusEdges);
	print_edge(krusEdges);
	cout << "===============================================" << "\n";

	cout << "<�ϵ��ڵ���� or cin�� ���� �Է¹��>" << "\n";
	vector<Edge> E = get_edges();
	vector<Edge> F;
	print_edge(E);
	cout << "------------ũ�罺Į�˰��� �Ϸ���------------" << '\n';
	//node�� ����
	int n = cnt_node(E);
	//edge�� ����(7)
	int m = E.size();
	kruskal(n, m, E, F);
	print_edge(F);
	cout << "===============================================" << "\n";
	return 0;
}

//void kruskal (int n, vector<int>I_arr, vector<int> J_arr)
