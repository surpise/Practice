#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b + c != 180) cout << "Error";
    else {
        if(a == b || a == c || b == c){
            if(a == 60 && b == 60) cout << "Equilateral";
            else cout << "Isosceles";
        }
        else cout << "Scalene";
    }
}