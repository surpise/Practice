#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    unsigned long long int answer = 1, j = 1;
    for(int i = balls; i > share; i--){
        answer *= i;
        if(j <= balls - share) answer /= j++;
    }

    return answer;
}