#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
#include<fstream>
#include<iostream>
using namespace std;
class Item {
private:
	string name;
	int weight;
	int value;
	float VperW;
public:
	Item();
	Item(string _name_, int _wet_, int _val_);
	string get_name() const;
	int get_weight() const;
	int get_value() const;
	float get_VperW() const;
};


vector<Item> read_items(int& n, const char* fName);
void print_items(vector<Item>& items);

#endif

