/******************************************************************************************
<백준 1976> 여행 가자


문제
동혁이는 친구들과 함께 여행을 가려고 한다. 
한국에는 도시가 N개 있고 임의의 두 도시 사이에 길이 있을 수도, 없을 수도 있다. 
동혁이의 여행 일정이 주어졌을 때, 이 여행 경로가 가능한 것인지 알아보자. 
물론 중간에 다른 도시를 경유해서 여행을 할 수도 있다. 
예를 들어 도시가 5개 있고, A-B, B-C, A-D, B-D, E-A의 길이 있고, 
동혁이의 여행 계획이 E C B C D 라면 E-A-B-C-B-C-B-D라는 여행경로를 통해 목적을 달성할 수 있다.

도시들의 개수와 도시들 간의 연결 여부가 주어져 있고, 
동혁이의 여행 계획에 속한 도시들이 순서대로 주어졌을 때 가능한지 여부를 판별하는 프로그램을 작성하시오.
 같은 도시를 여러 번 방문하는 것도 가능하다.

입력
첫 줄에 도시의 수 N이 주어진다. N은 200이하이다. 
둘째 줄에 여행 계획에 속한 도시들의 수 M이 주어진다. M은 1000이하이다. 
다음 N개의 줄에는 N개의 정수가 주어진다. 
i번째 줄의 j번째 수는 i번 도시와 j번 도시의 연결 정보를 의미한다. 
1이면 연결된 것이고 0이면 연결이 되지 않은 것이다. A와 B가 연결되었으면 B와 A도 연결되어 있다. 
마지막 줄에는 여행 계획이 주어진다. 도시의 번호는 1부터 N까지 차례대로 매겨져 있다.

출력
첫 줄에 가능하면 YES 불가능하면 NO를 출력한다.

예제 입력 1 
3
3
0 1 0
1 0 1
0 1 0
1 2 3
예제 출력 1 
YES
******************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

void init(vector<int>& parent){
    for(int i = 0; i < parent.size(); i++){
        parent[i] = i;
    }
}
int getParent(vector<int>& parent, int x){
    if(parent[x]==x)    return x;
    return getParent(parent, parent[x]);
}
void unionParent(vector<int>& parent, int i, int j){
    i = getParent(parent, i);
    j = getParent(parent, j);
    if(i < j)   parent[j] = i;
    else        parent[i] = j;
}
bool findParent(vector<int>& parent, int i, int j){
    i = getParent(parent, i);
    j = getParent(parent, j);
    if(i == j)      return true;
    else            return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //도시들의 수, 여행계획에 속한 도시의 수
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            cin >> matrix[i][j];
        }
    }
    vector<int> parent(n+1);
    init(parent);
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            if(matrix[i][j]==1){
                unionParent(parent, i, j);
            }
        }
    }

    vector<int> plan(m+1);
    for(int i = 1; i < m+1; i++){
        cin >> plan[i];
    }
    bool check;
    for(int i = 1; i < m; i++){
        //같은노드 집합에 있지 않으면
        if(!findParent(parent, plan[i], plan[i+1])){
            check = 0;
            break;
        }
        check = 1;
    }
    if(check){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}