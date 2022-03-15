#include<iostream>
#include<fstream>
#include<sstream>	//��Ʈ����Ʈ��
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<ctime>
#include<string>
#include<map>

using namespace std;
string read_from_file(const char *fname);
vector<string> split_string(string text);
map<string, int> count_words(vector<string> words);
int linear_search(vector<string> words, string key);
int binary_search(vector<string> words, string key);
void print_time(vector<string> arr, string key, const char* name, int(*func)(vector<string>, string));
#define N_FUNC 2
int main()
{
	string text = read_from_file("news.txt");
	vector<string> words = split_string(text);
	//cout << text << endl;
	//
	sort(words.begin(), words.end());
	struct {
		const char* name;
		int(*func)(vector<string>, string);
	}search[] = {
		{"linear_search", linear_search},
		{"binary_search", binary_search}
	};
	
	/*string key = "�ѹݵ�";
	linear_search(words, key);
	binary_search(words, key);*/
	vector<string> arr = words;
	string key = "�ѹݵ�";
	for (int i = 0; i < N_FUNC; i++)
	{
		print_time(arr, key, search[i].name, search[i].func);
	}
	//
	


	map<string, int> freq = count_words(words);
	map<string, int> ::iterator it;
	for (it = freq.begin(); it != freq.end(); ++it)
	{
		cout << it->first << "=>" << it->second << endl;
	}


	return 1;
}
void print_time(vector<string> arr, string key, const char* name, int(*func)(vector<string>, string))
{
	clock_t begin = clock();
	int fvalue1 = func(arr, key);
	for (int i = 0; i < 1000; i++) {
		fvalue1 = func(arr, key);
	}
	
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	printf("%s: ����ð��� %f(��)\n", name, elapsed_secs);
}
int binary_search(vector<string> words, string key)
{
	int low = 0, high = words.size();
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key == words[mid]) {
			return mid;
		}
		else if (key > words[mid]) {
			low = mid + 1;
		}
		else if (key < words[mid]) {
			high = mid - 1;
		}
	}
	return 0;
}
int linear_search(vector<string> words, string key)
{
	int low = 0, high = words.size();
	for (int i = low; i <= high; i++)
	{
		if (words[i] == key)	return i;
	}
	return 0;
}
map<string, int> count_words(vector<string> words)
{
	map<string, int> freq;
	for (int i = 0; i < words.size(); i++)
	{
		freq[words[i]]++;
	}
	return freq;
}
vector<string> split_string(string text)
{

	vector<string> words;
	stringstream ss(text);
	string word;
	while (ss >> word)
	{
		words.push_back(word);	//?? �³�
		//cout << word << endl;
	}
	return words;
}
string read_from_file(const char* fname)
{
	ifstream inFile(fname);
	stringstream strStream;
	strStream << inFile.rdbuf();
	return strStream.str();
}



/*
#include<iostream>
#include<fstream>
#include<sstream>	//��Ʈ����Ʈ��
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<ctime>
#include<string>

using namespace std;
string read_from_file(const char *fname);
int main()
{
	string text = read_from_file("news.txt");
	cout << text << endl;
	return 1;
}
string read_from_file(const char* fname)
{
	ifstream inFile(fname);
	stringstream strStream;
	strStream << inFile.rdbuf();
	return strStream.str();
}
*/