#include <iostream>
#include <string>
using namespace std;

int main(){
    string str, tmp = "";
    cin >> str;
    for(int i = 0; i < str.size(); i++) tmp = str[i] + tmp;
    if(str == tmp) cout << 1;
    else cout << 0;
}