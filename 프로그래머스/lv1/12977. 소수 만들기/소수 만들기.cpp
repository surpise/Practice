#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0, tmp;
    for(int i = 0; i < nums.size() - 2; i++){
        for(int j = i + 1; j < nums.size() - 1; j++){
            for(int k = j + 1; k < nums.size(); k++){
                tmp = nums[i] + nums[j] + nums[k];
                int cnt = 0;
                for(int c = 2; c < tmp; c++){
                    if(tmp % c == 0) cnt++;
                }
                if(cnt == 0) answer++;
            }
        }
    }

    return answer;
}