#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(long long n) {
    long long answer = -1, t = 1;
    while(t * t <= n){
        if(t * t == n) {
            answer = (t + 1) * (t + 1);
            break;
        }
        t++;
    }
    return answer;
}