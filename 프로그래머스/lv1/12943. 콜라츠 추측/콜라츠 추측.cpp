#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    while(n != 1 && answer <= 500){
        if(n % 2 == 0) n /= 2;
        else n = (n * 3) + 1;
        answer++;
    }
    if(n != 1) answer = -1;
    return answer;
}