#include <iostream>

using namespace std;

int main(){
    string a, b, c,d;
    cin >> a >> b >> c >> d;
    a = a + b;
    c = c + d;

    unsigned long long A = 0, B = 0;
    for(int i = 0; i < a.size(); i++){
        A *= 10;
        A += a[i] - '0';
    }
    for(int i = 0; i < c.size(); i++){
        B *= 10;
        B += c[i] - '0';
    }
    cout << A + B;
}