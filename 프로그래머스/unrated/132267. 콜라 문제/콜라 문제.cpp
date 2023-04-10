#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0, t;
    while(n >= a){
        t = (n / a) * b;
        answer += t;
        n = t + (n % a);
    }
    return answer;
}