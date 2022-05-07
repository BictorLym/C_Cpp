#include"schedule.h"
#include<fstream>
#include "schedule.h"

#include "Tokenizer.h"
#include "trim.h"
Job::Job() {}
Job::Job(string _index_, string _deadline_, string _profit_) {
	this->index = _index_;
	this->deadline = _deadline_;
	this->profit = _profit_;
}
string Job::get_index() const {
	return this->index;
}
string Job::get_deadline() const {
	return this->deadline;
}
string Job::get_profit() const {
	return this->profit;
}
void Job::set_index(string _index_) {
	this->index = _index_;
}
void Job::set_deadline(string _deadline_) {
	this->deadline = _deadline_;
}
void Job::set_profit(string _profit_) {
	this->profit = _profit_;
}

vector<Job> get_edges() {

	vector<Job> E;
	E.push_back(Job("1", "3", "40"));
	E.push_back(Job("2", "1", "35"));
	E.push_back(Job("3", "1", "30"));
	E.push_back(Job("4", "3", "25"));
	E.push_back(Job("5", "1", "20"));
	E.push_back(Job("6", "3", "15"));
	E.push_back(Job("7", "2", "10"));

	return E;
}
bool cmp(const Job& n1, const Job& n2) {
	return n1.get_profit() > n2.get_profit();
}
vector<Job> read_edges(const char* fname) {
	vector<Job> jobs;
	string line;
	ifstream input_file(fname);

	if (!input_file.is_open()) {
		cerr << "Could not open the file - '"
			<< fname << "'" << endl;
		exit(EXIT_FAILURE);
	}
	int cnt = 0;
	Tokenizer str;
	string token;
	while (getline(input_file, line)) {
		str.set(line, "#");
		//string index = str.next(); index = trim(index);
		string index = to_string(cnt);
		string daedline = str.next(); daedline = trim(daedline);
		string profit = str.next(); profit = trim(profit);
		//string _wet_ = str.next(); _wet_ = trim(_wet_);
		//double wet = atof(_wet_.c_str());
		jobs.push_back(Job(index, daedline, profit));
		cnt++;
	}
	//sort(jobs.begin(), jobs.end(), cmp);
	return jobs;
}
void print_job(vector<Job>& F) {
	int n = F.size();
	for (int i = 0; i < n; i++) {
		cout /* << "index:" << F[i].get_index() << "  "*/
			<< "deadline:" << F[i].get_deadline() << "  "
			<< "profit:" << F[i].get_profit() << "\n";
	}
}
void print_job1(vector<Job>& F) {
	int n = F.size();
	for (int i = 0; i < n; i++) {
		cout  << "index:" << i << "  "
			<< "deadline:" << F[i].get_deadline() << "  "
			<< "profit:" << F[i].get_profit() << "\n";
	}
}
//map<string, int> make_node_index(vector<Job>& edges) {
//	map<string, int> n2i;
//	int i;
//	int index = 0;
//	for (int i = 0; i < edges.size(); i++) {
//		string fr = edges[i].get_fr();
//		string to = edges[i].get_to();
//		if (n2i.find(fr) == n2i.end()) {
//			n2i.insert(pair<string, int>(fr, index));
//			index++;
//		}
//		if (n2i.find(to) == n2i.end()) {
//			n2i.insert(pair<string, int>(to, index));
//			index++;
//		}
//	}
//	return n2i;
//}