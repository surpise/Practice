#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int d = 6;
    for(int i = 6; i > 0; i--){
        if(n % i == 0 && d % i == 0){
            d = i; 
            break;
        }
    }
    int answer = n / d;
    return answer;
}