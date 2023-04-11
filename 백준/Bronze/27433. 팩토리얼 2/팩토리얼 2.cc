#include <iostream>
using namespace std;

void facto(int a, unsigned long long x){
    if(a <= 1) cout << x;
    else  facto(a - 1, x * a);
}

int main(){
    int n;
    cin >> n;

    unsigned long long ans = 1;
    facto(n, ans);
}