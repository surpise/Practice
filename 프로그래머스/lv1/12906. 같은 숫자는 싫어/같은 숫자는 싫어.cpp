#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int t = 0;
    answer.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++){
        if(answer[t] != arr[i]){
            answer.push_back(arr[i]);
            t++;
        }
    }

    return answer;
}