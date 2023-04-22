#include <string>
#include <vector>

using namespace std;

int arr[100001];
int solution(int number, int limit, int power) {
    int answer = 1;
    for(int i = 2; i <= number / 2; i++){
        for(int j = 2; j * i <= number; j++) arr[i * j] += 1;
    }
    
    for(int i = 2; i <= number; i++){
        if(arr[i] + 2 > limit) answer += power;
        else answer += arr[i] + 2;
    }
    return answer;
}