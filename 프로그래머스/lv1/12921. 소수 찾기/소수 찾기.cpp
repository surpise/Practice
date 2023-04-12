#include <string>
#include <vector>

using namespace std;

bool arr[1000001];
int solution(int n) {
    for(int i = 2; i <= n; i++){
        if(arr[i]) continue;
        for(int j = 2; i * j <= n; j++) arr[i * j] = 1;
    }
    int answer = 0;
    for(int i = 2; i <= n; i++) {
        if(!arr[i]) answer++;
    }
    return answer;
}