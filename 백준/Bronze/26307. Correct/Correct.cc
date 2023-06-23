#include<iostream>

using namespace std;

int main(){
    int h, m;
    cin >> h >> m;

    if(h == 9) cout << m;
    else{
        cout << (h - 9) * 60 + m;
    }
}