#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, tmp = 0;
    for(int i = 0; i < n; i++){
        answer++;
        tmp = answer;
        if(tmp % 3 == 0) i--;
        else if(tmp >= 10){
            while(tmp > 0){
                if(tmp % 10 == 3) {
                    i--;
                    break;
                }
                tmp /= 10;
            }
        }
    }
    return answer;
}