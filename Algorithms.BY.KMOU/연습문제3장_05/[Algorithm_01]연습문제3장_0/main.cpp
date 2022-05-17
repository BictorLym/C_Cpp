#include <stdio.h> 
#include <limits.h> 
#include<iostream>
using namespace std;
#define TRUE    1 
#define FALSE    0 
#define VERTICES    7        /* 정점의 수 */ 
#define INF    10000    /* 무한대 (연결이 없는 경우) */ 

/* 네트워크의 인접행렬 */
int weight[VERTICES][VERTICES] = {
    {   0,  4,  INF, INF, INF,  10, INF },
    {   3,  0,  INF,  18, INF, INF, INF },
    { INF,  6,    0, INF, INF, INF, INF },
    { INF,  5,   15,   0,   2,  19,   5 },
    { INF,INF,   12,   1,   0, INF, INF },
    { INF,INF,  INF, INF, INF,   0, 10 },
    { INF, INF, INF,   8, INF, INF,   0 } };
int P[VERTICES][VERTICES] = {
    {   0,  4,  INF, INF, INF,  10, INF },
    {   3,  0,  INF,  18, INF, INF, INF },
    { INF,  6,    0, INF, INF, INF, INF },
    { INF,  5,   15,   0,   2,  19,   5 },
    { INF,INF,   12,   1,   0, INF, INF },
    { INF,INF,  INF, INF, INF,   0, 10 },
    { INF, INF, INF,   8, INF, INF,   0 } };
int A[VERTICES][VERTICES];

void printA(int n)
{
    int i, j, k;
    printf("===============================\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] == INF)
                printf("INF ");
            else printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("===============================\n");

    printf("P===============================\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (P[i][j] == INF)
                printf("INF ");
            else printf("%3d ", P[i][j]);
        }
        printf("\n");
    }
    printf("P===============================\n");
}
void floyd(int n)
{

    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            A[i][j] = weight[i][j];
            P[i][j] = 0;
        }
            

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k;
                }
                    
        printA(n);
    }
}
void path(int q, int r) {
    if (P[q][r] != 0) {
        path(q, P[q][r]);
        cout << "v" << P[q][r];
        path(P[q][r], r);
    }
}
int main()
{
    floyd(VERTICES);
    path(6,2);
    return 0;
}


//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//#include <fstream>
//#include <time.h>
//#include <stdio.h>
//
//#include "Tokenizer.h"
//#include "Edge.h"
//void floyd(int n, const vector< vector<double>> w, vector<vector<double>>& d);
//void floyd2(int n, const vector< vector<double>> w, vector<vector<double>>& d, vector<vector<double>> p);
//int main() {
//	const char* fName = "edges.txt";
//	vector<Edge> edges = read_edges(fName);
//	print_edges(edges);
//	cout << "\n";
//
//	map<string, int> nodes = make_node_index(edges);
//	print_nodes(nodes);
//	cout << "\n";
//
//
//	vector<vector<double>> W = makeGraph(edges, nodes);
//	print_matrix(W);
//	cout << "\n";
//	/*과제*/
//	vector<vector<double>> D;
//	floyd(5, W, D);
//	print_matrix(D);
//
//	vector<vector<double>> D2;
//	vector<vector<double>> P;
//	floyd2(5, W, D, P);
//	//print_matrix;
//	/*과제*/
//
//	return 0;
//}
///*과제*/
//void floyd(int n, const vector< vector<double>> w, vector<vector<double>>& d)
//{
//	//int n = d.size() - 1;
//	d = w;
//	for (int k = 0; k < n; k++)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//			}
//		}
//	}
//}
//void floyd2(int n, const vector< vector<double>> w, vector<vector<double>>& d, vector<vector<double>> p)
//{
//	int i, j, k;
//	p = w;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			p[i][j] = 0;
//		}
//	}
//	d = w;
//	for(k=0; k <n; k++)
//		for(i=0; i<n; i++)
//			for (j = 0; j < n; j++)
//			{
//				if (d[i][k] + d[k][j] < d[i][j])
//				{
//					p[i][j] = k;
//					d[i][j] = d[i][k] + d[k][j];
//				}
//			}
//}
//
//
//
///*과제*/
//
////void quickSort(vector<Edge>& lst)
////{
////    //sort(lst.begin(), lst.end());
////
////    int left = 0;
////    int right = lst.size() - 1;
////    /*string start = lst[0].get_name();
////    string end = lst[lst.size() - 1].get_name();*/
////    quickSort(lst, left, right);
////}
////void quickSort(vector<Edge>& lst, int left, int right)
////{
////    if (left < right) {
////        int q = partition(lst, left, right);
////        quickSort(lst, left, q - 1);
////        quickSort(lst, q + 1, right);
////    }
////}
////int partition(vector<Edge>& lst, int left, int right)
////{
////    Edge pivot, temp;
////    int low, high;
////
////    low = left;
////    high = right + 1;
////    pivot = lst[left];
////    do {
////        do
////            low++;
////        while (lst[low] < pivot);
////        do
////            high--;
////        while (lst[high] > pivot);
////        if (low < high)
////            swap(lst[low], lst[high]);
////    } while (low < high);
////
////    swap(lst[left], lst[high]);
////    return high;
////}
////void swap(Edge& x, Edge& y)
////{
////    Edge temp;
////    temp.set_name(x.get_name());
////    temp.set_telno(x.get_telno());
////
////    x.set_name(y.get_name());
////    x.set_telno(y.get_telno());
////
////    y.set_name(temp.get_name());
////    y.set_telno(temp.get_telno());
////}