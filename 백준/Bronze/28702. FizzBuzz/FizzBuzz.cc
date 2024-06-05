#include <iostream>

using namespace std;

int stringToInt(string s){
    int res = 0;

    for(int idx = 0; idx < s.size(); idx++){
        res *= 10;
        res += s[idx] - '0';
    }

    return res;
}

int main(){
    string str[3];
    for(int idx = 0; idx < 3; idx++) cin >> str[idx];

    for(int idx = 0; idx < 3; idx++){
        if(str[idx][0] < '0' || str[idx][0] > '9') continue;

        int target = stringToInt(str[idx]) + (3 - idx);
        if(target % 3 == 0 && target % 5 == 0) cout << "FizzBuzz";
        else if(target % 3 == 0) cout << "Fizz";
        else if(target % 5 == 0) cout << "Buzz";
        else cout << target;

        break;
    }
}