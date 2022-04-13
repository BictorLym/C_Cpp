#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <stdio.h>

#include "Tokenizer.h"
#include "Minfo.h"
#include "trim.h"
using namespace std;
vector<MInfo> read_matrix_info(string fName);
void print_matrix_info(vector<MInfo>& A);
vector<int> make_dinmensions(vector<MInfo>& M);
vector<vector<int>> make_matrix(vector<MInfo>& mats);
/*苞力*/
//vector<vector<int>> minmulti(int d, vector<vector<int>> M, vector<vector<int>> P);
vector<vector<int>> minmulti(vector<int>& d, vector<vector<int>>& M, vector<vector<int>>& P);
void order(int i, int j, vector<vector<int>> P, vector<MInfo>mats);
int mininmum(vector<vector<int>>&M, vector<int>& d, int i, int j, int& k);
void print_matrix(vector<vector<int>> M);
/*苞力*/
int main() {
	const string fName = "matrix.txt";
	vector<MInfo> mats = read_matrix_info(fName);
    print_matrix_info(mats);
    
    vector<int> d = make_dinmensions(mats);

    vector<vector<int>> M = make_matrix(mats);
    vector<vector<int>> P = make_matrix(mats);
    print_matrix(M);

    minmulti(d, M, P);
    print_matrix(M);
    print_matrix(P);
    order(1, d.size() - 1, P, mats);
    cout << endl;

	return 0;
}

/*苞力*/
void order(int i, int j, vector<vector<int>> P, vector<MInfo>mats)
{
    
    if (i == j) {
        cout << "A" << i;
    }
    else {
        int k = P[i][j];
        cout << "(";
        order(i, k-1, P, mats);
        order(k, j, P, mats);
        cout << ")";
    }
}
vector<vector<int>> minmulti(vector<int>& d, vector<vector<int>>& M, vector<vector<int>>& P)
{
    int n = d.size()-1;
    int i, j, k, diagonal;
    
    for (i = 1; i <= n; i++) {
        M[i][i] = 0;
    }
    for (diagonal = 1; diagonal <= n - 1; diagonal++)
    {
        for (i = 1; i <= n - diagonal; i++)
        {
            j = i + diagonal;
            //minimum( M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j] );
            M[i][j] = mininmum(M, d, i, j, k);
            P[i][j] = k;
        }
    }
    return M;
}

void print_matrix(vector<vector<int>> M)
{
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M.size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
int mininmum(vector<vector<int>>&M, vector<int> &d, int i, int j, int& k)
{
    //minimum( M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j] );
    int min = M[i][i] + M[i+1][j] + d[i-1]*d[i]*d[j];
    for (k = i; k <= j - 1; k++)
    {
        int tmp = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
        if (min > tmp) {
            min = tmp;
        }
    }
    return min;
}
/*苞力*/

vector<vector<int>> make_matrix(vector<MInfo>& mats) {
    vector<vector<int>> M;
    int i, j;
    for (i = 0; i <= mats.size(); i++) {
        vector<int> row(mats.size() + 1, 0);
        M.push_back(row);
    }
    return M;
}
vector<int> make_dinmensions(vector<MInfo>& M)
{
    vector<int> d;
    int i;

    d.push_back(M[0].get_row());
    for (i = 0; i < M.size(); i++) {
        d.push_back(M[i].get_col());
    }
    return d;
}
void print_matrix_info(vector<MInfo>& A) {
    vector<MInfo>::iterator it;
    for (it = A.begin(); it != A.end(); ++it) {
        cout << it->get_name() << " : "
            << it->get_row() << " : "
            << it->get_col() << endl;
    }
}
vector<MInfo> read_matrix_info(string fName) {
    vector<MInfo> mats;
    //string line;
    ifstream fin(fName);

    //if (!input_file.is_open()) {
    //    cerr << "Could not open the file - '"
    //        << fname << "'" << endl;
    //    exit(EXIT_FAILURE);
    //}
    //if (!fin.fail()) {
    //    cerr << "Could not open the file - '"
    //        << fName << "'" << endl;
    //    exit(EXIT_FAILURE);
    //}
    //Tokenizer str;
    //string token;
    string name;
    string line;
    int row, col;
    while (getline(fin, line)) {
        Tokenizer tokens(line, " ");
        string tmp = tokens.next(); name = trim(tmp);
        tmp = tokens.next(); row = atoi(tmp.c_str());
        tmp = tokens.next(); col = atoi(tmp.c_str());
        mats.push_back(MInfo(name, row, col));
    }
    return mats;
}