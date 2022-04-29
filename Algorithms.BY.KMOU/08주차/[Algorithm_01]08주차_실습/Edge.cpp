#include<fstream>
#include "Edge.h"
#include "alg_lecture.h"
#include "Tokenizer.h"
#include "trim.h"
Edge::Edge() {}
Edge::Edge(string _fr, string _to, double _wet) {
	this->fr = _fr;
	this->to = _to;
	this->wet = _wet;
}
string Edge:: get_fr() const {
	return this->fr;
}
string Edge::get_to() const {
	return this->to;
}
double Edge::get_wet() const {
	return this->wet;
}
void Edge::set_fr(string _fr) {
	this->fr = _fr;
}
void Edge::set_to(string _to) {
	this->to = _to;
}
void Edge::set_wet(double _wet) {
	this->wet = _wet;
}
vector<Edge> get_edges() {
	//vector<Edge> E;
	//cout << "입력할 간선의 갯수를 정해주세요: ";	cin >> n;
	//string v1, v2;
	//double weight;
	//for (int i = 0; i < n; i++) {
	//	cout << "첫번째 마디의 이름을 정해주세요: ";	cin >> v1;
	//	cout << "두번째 마디의 이름을 정해주세요: ";	cin >> v2;
	//	cout << "간선의 길이를 정해주세요: ";	cin >> weight;
	//	E.push_back(Edge(v1, v2, weight));
	//}
	
	vector<Edge> E;
	E.push_back(Edge("1", "2", 1.0));
	E.push_back(Edge("3", "5", 2.0));
	E.push_back(Edge("1", "3", 3.0));
	E.push_back(Edge("2", "3", 3.0));
	E.push_back(Edge("2", "4", 6.0));
	E.push_back(Edge("3", "4", 4.0));
	E.push_back(Edge("4", "5", 5.0));
	
	//sort(E.begin(), E.end(), compareWeight);


	return E;
}
vector<Edge> read_edges(const char* fname) {
    vector<Edge> edges;
    string line;
    ifstream input_file(fname);

    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << fname << "'" << endl;
        exit(EXIT_FAILURE);
    }
    Tokenizer str;
    string token;
    while (getline(input_file, line)) {
        str.set(line, "#");
        string fr = str.next(); fr = trim(fr);
        string to = str.next(); to = trim(to);
        string _wet_ = str.next(); _wet_ = trim(_wet_);
        double wet = atof(_wet_.c_str());
        edges.push_back(Edge(fr, to, wet));
    }
	
    return edges;
}
void print_edge(vector<Edge>& F) {
	int n = F.size();
	for (int i = 0; i < n; i++) {
		cout << "  fr:" << F[i].get_fr()
			 << "->  to:" << F[i].get_to()
			 << " weight="<< F[i].get_wet() << "\n";
	}
}