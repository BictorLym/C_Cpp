#include"knapsac.h"
int main() {
	const char* fName1 = "items.txt";
	int W1 = 0;
	vector<Item> items1 = read_items(W1, fName1);
	//print_items(items);
	
	int n1 = items1.size();
	//cout << "\n" << "W:" << W << "\n";
	//cout <<"n:" << n <<"\n";
	clock_t begin1_dp1 = clock();
	int ans_dp1 = knapsac_dp(items1, W1, n1);
	clock_t end1_dp1 = clock();
	double elapsed_secs1_dp1 = double(end1_dp1 - begin1_dp1) / CLOCKS_PER_SEC;
	
	clock_t begin1_greedy1 = clock();
	int ans_greedy1 = knapsac_greedy(items1, W1);
	clock_t end1_greedy1 = clock();
	double elapsed_secs1_greedy1 = double(end1_greedy1 - begin1_greedy1) / CLOCKS_PER_SEC;



	const char* fName2 = "items_changed.txt";
	int W2 = 0;
	vector<Item> items2 = read_items(W2, fName2);
	//print_items(items);

	int n2 = items2.size();
	//cout << "\n" << "W:" << W << "\n";
	//cout <<"n:" << n <<"\n";

	int ans_dp2 = knapsac_dp(items2, W2, n2);
	int ans_greedy2 = knapsac_greedy(items2, W2);
	cout << "===========================================" << "\n";
	cout << "greedy algorithm : " << elapsed_secs1_greedy1 << "msec" << "\n";
	cout << "dynamic algorithm : " << elapsed_secs1_dp1 << "msec" << "\n";
	cout << "===========================================" << "\n";
	cout << "Solutions" << "\n";
	cout << "---------------------------" << "\n";
	cout << "greedy" << "\n";
	cout << "교수님이 주신 txt파일로 만든 그리디의 해:" << ans_greedy1 << "\n";
	cout << "---------------------------" << "\n";
	cout << "dynamic programming" << "\n";
	cout << "교수님이 주신 txt파일로 만든 동적계획법의 해:" << ans_dp1 << "\n";


	cout << "===========================================" << "\n";

	cout << "Solutions" << "\n";
	cout << "---------------------------" << "\n";
	cout << "greedy" << "\n";
	cout << "해가 서로 다르게 수정한 txt파일로 만든 그리디의 해:" << ans_greedy2 << "\n";
	cout << "---------------------------" << "\n";
	cout << "dynamic programming" << "\n";
	cout << "해가 서로 다르게 수정한 txt파일로 만든 동적계획법의 해:" << ans_dp2 << "\n";
	cout << "===========================================" << "\n";

	return 0;
}