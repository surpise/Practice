#include <iostream>

using namespace std;

int main(){
    int n, x;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> str;
        str.erase(x - 1, 1);
        cout << str << '\n';
    }
}