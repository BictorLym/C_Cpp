#include "Edge.h"

Edge::Edge() {}
Edge::Edge(string _fr, string _to, double _wet) {
	this->fr = _fr;
	this->to = _to;
	this->wet = _wet;
}
string Edge::get_fr() const {
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
	E.push_back(Edge("1", "2", 40.0));
	E.push_back(Edge("2", "1", 35.0));
	E.push_back(Edge("3", "1", 30.0));
	E.push_back(Edge("4", "3", 25.0));
	E.push_back(Edge("5", "1", 20.0));
	E.push_back(Edge("6", "3", 15.0));
	E.push_back(Edge("7", "2", 10.0));

	//sort(E.begin(), E.end(), compareWeight);


	return E;
}
void print_edge(vector<Edge>& F) {
	int n = F.size();
	for (int i = 0; i < n; i++) {
		cout << "  작업:" << F[i].get_fr()
			<< "  마감시간:" << F[i].get_to()
			<< " 보상=" << F[i].get_wet() << "\n";
	}
}