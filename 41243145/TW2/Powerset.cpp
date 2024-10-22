#include <iostream>
#include<string>
using namespace std;

class Powerset {
public:
    int endding = 1;

    Powerset(string str ) {
        int count = str.length();
        while (count) {
            endding *= 2;
            count--;
        }
        cout << "S(" << str << ") = {";
        print_subset(str, 0);
    }
    void print_subset(string str, short int count) {
        if (count == endding) {
            cout << "}\n";
            return;
        }
        bool Fg = false;
        cout << '(';
        for (int i = 0; i < str.length(); i++) {
            if (count & (1 << i)) {
                if (!Fg) 
                    Fg = true;
                else 
                    cout << ',';
                cout << str[i];
            }
        }
        cout << ')';
        if (count + 1 < endding) {
            cout << ",";
        }
        print_subset(str, count + 1);
    }
};

int main()
{
    string user_input;
    cout << "請輸入一個集合字串:";
    cin >> user_input;
    Powerset run(user_input);
    system("pause");
    return 0;
}