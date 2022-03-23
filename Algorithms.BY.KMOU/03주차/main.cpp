#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<ctime>
#include<string>
#include<map>

#include"Student.h"
#include"Tokenizer.h"


//#define SWAP(a,b) /*{int t; t=a; a=b; b=t;}*/ (((c)=(a)),((a)=(b)),((b)=(c)))


using namespace std;
#define EXIT_FAILURE 1
vector<Student> read_data(const char *fname);

//void quicksort(vector<Student>& students); /*, int start, int end*/
//int partition(vector<Student>& students); /*, int start, int end*/

//template<class T>
void quickSort(vector<Student>& lst);
void quickSort(vector<Student>& lst, int left, int right);
int partition(vector<Student>& lst, int left, int right);
void swap(Student& x, Student& y);
//template <class T>
//void quickSort(vector<T>& lst);
//template <class T>
//void quickSort1(vector<T>& lst, int left, int right);
//template <typename T>
//int partition(vector<T>& lst, int left, int right);
int main()
{
	const char* fname = "data.txt";
	vector<Student> students = read_data(fname);
    for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        //it->doSomething();
        cout << it->get_name() << " "
            << it->get_telno() << endl;
        /*home_work*/
        //cout << *it << endl;
        /*home_work*/
    }
    cout << '\n';

    /*실습*/
    quickSort(students);
    //sort(students.begin(), students.end());
    for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        cout << it->get_name() << " "
            << it->get_telno() << endl;
    }
    /*실습*/

    cout << "\n" << "정답" << "\n";
    sort(students.begin(), students.end());
    for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        cout << it->get_name() << " "
            << it->get_telno() << endl;
    }
	return 0;
}
vector<Student> read_data(const char* fname)
{
    vector<Student> students;
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
        string name = str.next();
        string telno = str.next();
        students.push_back(Student(name, telno));

        //while ((token = str.next()) != "")
        //{
        //    cout << token << '\n';
        //}
        //cout << '\n';
        ////lines.push_back(line);
    }
    return students;
}



/*실습*/
//template<class T>
void quickSort(vector<Student>& lst)
{
    //sort(lst.begin(), lst.end());
    
    int left = 0;
    int right = lst.size() - 1;
    /*string start = lst[0].get_name();
    string end = lst[lst.size() - 1].get_name();*/
    quickSort(lst, left, right);
}
void quickSort(vector<Student>& lst, int left, int right)
{
    if (left < right) {
        int q = partition(lst, left, right);
        quickSort(lst, left, q - 1);
        quickSort(lst, q + 1, right);
    }
}
int partition(vector<Student>& lst, int left, int right)
{
    Student pivot, temp;
    int low, high;

    low = left;
    high = right+1;
    pivot = lst[left];
    do {
        do
            low++;
        while (lst[low] < pivot);
        do
            high--;
        while (lst[high] > pivot);
        if (low < high)    
            swap(lst[low], lst[high]);
    } while (low < high);

    swap(lst[left], lst[high]);
    return high;
}
void swap(Student& x, Student& y)
{
    Student temp;
    temp.set_name(x.get_name());
    temp.set_telno(x.get_telno());

    x.set_name(y.get_name());
    x.set_telno(y.get_telno());

    y.set_name(temp.get_name());
    y.set_telno(temp.get_telno());
}
//template <class T>
//void swap(T& x, T& y, T& temp)
//{
//    temp = x;
//    x=y;
//    y = temp;
//    //{
//    //    temp.set_name(x.get_name);
//    //    temp.set_telno(x.get_telno);
//    //}
//    //{
//    //	x.set_name(y.get_name);
//    //	x.set_telno(y.get_telno);
//    //}
//    //{
//    //	y.set_name(temp.get_name);
//    //	y.set_name(temp.get_name);
//    //}
//}
/*실습*/
