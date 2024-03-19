#include <string>
#include <vector>

using namespace std;

int countTwo(int n){
    int cnt = 0;
    
    while(n >= 1){
        if(n % 2 == 1) cnt++;
        
        n /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    int two = countTwo(n);
    
    int answer = n + 1;
    while(true){
        if(two == countTwo(answer)) break;
        
        answer++;
    }
    
    return answer;
}