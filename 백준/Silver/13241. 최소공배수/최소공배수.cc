#include <iostream>

using namespace std;

long long a, b, m, x;
void eq(int i, int j){
    if(i % j == 0) x = j;
    else eq(j, i % j);
}

int main(){
    cin >> a >> b;
    m = (a > b) ? a : b;
    eq(m, a + b - m);
    cout << a * b / x;
}