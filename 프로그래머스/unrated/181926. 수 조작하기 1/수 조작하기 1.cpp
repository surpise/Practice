#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = n;
    for(int i = 0; i < control.size(); i++){
        switch (control[i]){
            case 'w':
                answer++;
                break;
            case 's':
                answer --;
                break;
            case 'd':
                answer += 10;
                break;
            case 'a':
                answer -= 10;
                break;
        }
    }
    return answer;
}