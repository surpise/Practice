#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 1, s;
    for(int i = 1; i < b; i++){
        if(a % i == 0 && b % i == 0) s = i;
    }
    b /= s;
    while(b % 2 == 0) b /= 2;
    while(b % 5 == 0) b /= 5;
    if(b != 1) answer = 2;
    return answer;
}