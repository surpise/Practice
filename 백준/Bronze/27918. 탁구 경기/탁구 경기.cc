#include <iostream>

using namespace std;

int main(){
    int n, d = 0, p = 0;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(d - p  >= 2 || p - d >= 2) continue;
        if(str == "D"){
            d++;
        }
        else if(str == "P"){
            p++;
        }
    }
    cout << d << ":" << p;
}