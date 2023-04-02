#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;

    set<string> s;
    string na, o;
    for(int i = 0; i < n; i++){
        cin >> na >> o;
        if(o == "enter") s.insert(na);
        else s.erase(na);
    }
    for(auto e = s.rbegin(); e != s.rend(); e++) cout << *e << '\n';
}