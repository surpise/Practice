#include <iostream>
#include <string>
using namespace std;

int main(){
    string cn, cg;
    float cs, ans = 0, grade = 0;
    for(int i = 0; i < 20; i++){
        cin >> cn >> cs >> cg;
        if(cg == "A+") ans += cs * 4.5;
        else if(cg == "A0") ans += cs * 4.0;
        else if(cg == "B+") ans += cs * 3.5;
        else if(cg == "B0") ans += cs * 3.0;
        else if(cg == "C+") ans += cs * 2.5;
        else if(cg == "C0") ans += cs * 2.0;
        else if(cg == "D+") ans += cs * 1.5;
        else if(cg == "D0") ans += cs * 1.0;
        if(cg != "P") grade += cs;
    }
    cout << ans / grade;
}