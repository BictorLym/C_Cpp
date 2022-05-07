#ifndef JOB_H
#define JOB_H
#include<iostream>
#include<string>
#include<vector>

#include<map>
#include<algorithm>
using namespace std;
//using namespace edg;

class Job {
private:
	string index;
	string deadline;
	string profit;
public:
	Job();
	Job(string _index_, string _deadline_, string _profit_);
	string get_index() const;
	string get_deadline() const;
	string get_profit() const;
	void set_index(string _index_);
	void set_deadline(string _deadline_);
	void set_profit(string _profit_);
};
//vector<Job> get_edges();
vector<Job> read_edges(const char* fName);
bool cmp(const Job& n1, const Job& n2);
void print_job(vector<Job>& F);
void print_job1(vector<Job>& F);
map<string, int> make_node_index(vector<Job>& edges);
#endif