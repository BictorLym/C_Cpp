#ifndef KNAPSAC_H
#define KNAPSAC_H
#include"trim.h"
#include"Tokenizer.h"
#include"Item.h"
#include<algorithm>
#include<ctime>
int max(int a, int b);
int knapsac_dp(vector<Item>& arr, int W, int n);
bool cmpVperW(Item n1, Item n2);
int knapsac_greedy(vector<Item> items, int W);
#endif