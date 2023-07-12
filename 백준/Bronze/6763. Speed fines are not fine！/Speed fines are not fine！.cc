#include <iostream>

using namespace std;

int main(){
    int l, s, f;
    cin >> l >> s;
    if(s - l <= 0) cout << "Congratulations, you are within the speed limit!";
    else{
        if(s - l <= 20) f = 100;
        else if(s - l <= 30) f = 270;
        else f = 500;
        cout << "You are speeding and your fine is $" << f << ".";
    }
}