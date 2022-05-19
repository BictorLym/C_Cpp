#include"Item.h"
#include"Tokenizer.h"
#include"trim.h"
Item::Item() {
    
}
Item::Item(string _name_, int _wet_, int _val_) {
    name = _name_;
    weight = _wet_;
    value = _val_;
    VperW = (float)_val_ / (float)_wet_;
}
string Item::get_name() const {
    return name;
}
int Item::get_weight() const {
    return weight;
}
int Item::get_value() const {
    return value;
}
float Item::get_VperW() const {
    return VperW;
}




vector<Item> read_items(int& W, const char* fname) {
    vector<Item> items;
    string line;
    ifstream input_file(fname);

    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << fname << "'" << endl;
        exit(EXIT_FAILURE);
    }
    Tokenizer str;
    string token;
    
    string tmp;
    getline(input_file, line);
    str.set(line, "		");
    tmp = str.next(); tmp = trim(tmp);
    W = stoi(tmp); 
    while (getline(input_file, line)) {
        str.set(line, "		");
        string fr = str.next(); fr = trim(fr); 
        string to = str.next(); to = trim(to); 
        string _wet_ = str.next(); _wet_ = trim(_wet_); 
        
        string name = fr;
        int weight = stoi(to);
        int value = stoi(_wet_);
        items.push_back(Item(name, weight, value));
    }
    return items;
}

void print_items(vector<Item>& items) {
    vector<Item>::iterator it;
    for (it = items.begin(); it != items.end(); ++it) {
        cout << "이름:" << it->get_name() << "  "
            << "무게:" << it->get_weight() << "  "
            << "가치:" << it->get_value() << "  "
            << "단위당가치:" << it->get_VperW() << endl;
    }
}