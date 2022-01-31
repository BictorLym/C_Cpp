#include <iostream>

int main(void) 
{
    int cnt=0, x;
    int a_3, a_2, a_1;
    printf("Hello World!");
    scanf("%d", &x);
    
    for (int i = 1; i<=x; i++)
    {
        if( i < 100&& x > 0 )   cnt++;
        else
        {
            a_1 = i%10;
            a_2 = (i%100)/10;
            a_3 = i/100;
            if ((a_2-a_1) == (a_3-a_2)) cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main()
// {
//     vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

//     for (const string& word : msg)
//     {
//         cout << word << " ";
//     }
//     cout << endl;
// }