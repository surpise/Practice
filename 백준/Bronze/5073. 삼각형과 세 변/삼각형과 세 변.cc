#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c, l;
    while(1){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        l = max({a, b, c});
        if(l >= (a + b + c) - l) cout << "Invalid" << '\n';
        else{
            if(a == b && a == c && b == c) cout << "Equilateral" << '\n';
            else if(a != b && a != c && b != c) cout << "Scalene" << '\n';
            else cout << "Isosceles" << '\n';
        }
    }
}