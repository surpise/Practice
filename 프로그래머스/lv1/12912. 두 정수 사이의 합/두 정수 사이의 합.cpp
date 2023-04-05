#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    int s = (a < b) ? a : b;
    int l = (a < b) ? b : a;
    long long answer = 0;
    for(int i = s; i <= l; i++) answer += i;
    return answer;
}