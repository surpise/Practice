#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] - 'a' < 0 )str[i] += 'a' - 'A';
        else str[i] -= 'a' - 'A';
    }
    cout << str;
}