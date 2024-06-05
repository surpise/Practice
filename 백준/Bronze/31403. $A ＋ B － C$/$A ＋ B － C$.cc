#include <iostream>

using namespace std;

string intToStr(int v){
    string str = "";
    while(v > 0){
        char num = char(v % 10) + '0';
        str = num + str;
        v /= 10;
    }
    return str;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << '\n';
    
    string strA = intToStr(a);
    string strB = intToStr(b);
    string tmp = strA + strB;
    
    int ab = 0;
    for(int idx = 0; idx < tmp.size(); idx++){
        ab *= 10;
        ab += tmp[idx] - '0';
    }
    cout << ab - c;
}