#include <iostream>

using namespace std;

unsigned long long a, b, c;

unsigned long long s(unsigned long long A, unsigned long long B){
    if(B == 1) return A;
    else{
        unsigned long long n = s(A, B / 2) % c;
        if(B % 2 == 0) return (n * n) % c;
        else return (((n * n)  % c) * A) % c;
    }
}

int main(){
    cin >> a >> b >> c;
    cout << s(a, b) % c;
}