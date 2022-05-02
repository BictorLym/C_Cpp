/******************************************************************************************
<백준 1541> 잃어버린 괄호


문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 
입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.

예제 입력 1 
55-50+40
예제 출력 1 
-35
예제 입력 2 
10+20+30+40
예제 출력 2 
100
예제 입력 3 
00009-00009
예제 출력 3 
0
******************************************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
int calc(vector<int>& numberArray,vector<char>& symbolArray);
//void changeSymbol(vector<char>& symbolArray);
void changeSymbol1(vector<char>& symbolArray);
void printNumberArray(vector<int>& numberArray);
void printSymbolArray(vector<char>& symbolArray);
int main(){
   string str;
   cin >> str;
   int n = str.length();
   vector<int> numberArray;
   vector<char> symbolArray;
   stack<int> s;
   int tmp=0;
   s.push(tmp);
   for(int i = 0; i < n; i++){
      if(str[i]>='0'&&str[i]<='9'){
         tmp = s.top()*10; s.pop();
         tmp = tmp + ((int)str[i]-48);
         s.push(tmp);
      }
      else if(str[i]=='+'||str[i]=='-'){
         tmp = s.top(); s.pop();
         numberArray.push_back(tmp);
         tmp = 0;
         s.push(tmp);
         symbolArray.push_back(str[i]);
      }
      if(i==n-1){
         tmp = s.top();
         s.pop();
         numberArray.push_back(tmp);
      }
   }
   //printNumberArray(numberArray);
   //printSymbolArray(symbolArray);

   changeSymbol1(symbolArray);
   //printSymbolArray(symbolArray);
   
   int ans = calc(numberArray, symbolArray);

   cout << ans;

   return 0;
}

void changeSymbol1(vector<char>& symbolArray)
{
   int ans = 0, idx = 0;
   int n = symbolArray.size();
   bool checkMinus = 0;
   if(!checkMinus){
      for(int i = 0; i < n; i++){
         if(symbolArray[i]=='-'){
            checkMinus = 1;
            idx = i;
            break;
         }
      }
   }
   if(checkMinus){
      for(int i = idx; i < n; i++){
         symbolArray[i] = '-';
      }
   }
}
int calc(vector<int>& numberArray,vector<char>& symbolArray)
{
   int ans = 0, operand = numberArray[0], idx = 0;
   int n = symbolArray.size();
   ans += operand;
   for(int i = 0; i < n; i++){
      if(symbolArray[i]=='+'){
         operand = numberArray[i+1];
         ans += operand;
      }
      else if(symbolArray[i]=='-'){
         operand = numberArray[i+1];
         ans -= operand;
      }
   }
   return ans;
}

void printNumberArray(vector<int>& numberArray)
{
   for(int i = 0; i < numberArray.size(); i++){
      cout << numberArray[i] << " ";
   }
   cout << "\n";
}
void printSymbolArray(vector<char>& symbolArray)
{
   for(int i = 0; i < symbolArray.size(); i++){
      cout << symbolArray[i] << " ";
   }
   cout << "\n";
}


// #include<iostream>
// #include<string>
// #include<stack>
// using namespace std;

// int main(){
//    string str; cin >> str;
//    stack<int> s;
//    bool check = 0;
//    int operand1 = 0, operand2 = 0, sum = 0, n = str.size();
//    int i = 0, j, idx = 0;
//    char operator1;
//    while(1){
//       if(str[i]=='+'){
//          idx = i;
//          operator1 = str[i];
//          break;
//       }
//       else if(str[i]=='-'){
//          idx = i;
//          check = 1;
//          operator1 = str[i];
//          break;
//       }
//       operand1 = operand1 * 10 + (int)(str[i]-48);
//       idx = i;
//       i++;
//    }
//    cout << "i:" << i << endl;
//    sum += operand1;
//    i++;
//    while(1){
//       if(str[i]=='+' || str[i]=='-'||i==n){
//          i;
//          idx = i;
//          break;
//       }
//       operand2 = operand2 * 10 + (int)(str[i]-48);
//       idx = i;
//       i++;
//    }
//    cout << "i:" << i << endl;
//    cout << operand1 << " " << operand2;
//    for(i = idx; i <= n; i++){
//       if(str[i]=='-'){
//          check = 1;
//       }
//    }
//    return 0;
// }
