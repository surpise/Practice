#include <iostream>
#include <set>

using namespace std;

int main(){
    set<string> s;
    string str, tmp;

    cin >> str;
    for(int i = 0; i < str.size(); i++){
        tmp = "";
        for(int j = i; j < str.size(); j++){
            tmp += str[j];
            s.insert(tmp);
        }
    }
    cout << s.size();
}