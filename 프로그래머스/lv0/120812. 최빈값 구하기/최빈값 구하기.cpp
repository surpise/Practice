#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    sort(array.begin(), array.end());
    
    int answer, max = 0, tmp = array[0], cnt = 1, f = 0;
    for(int i = 1; i < array.size(); i++){
        if(array[i] == tmp) cnt++;
        else{
            if(cnt > max){
                f = 0;
                max = cnt;
                answer = tmp;
            }
            else if(cnt == max) f = 1;
            tmp = array[i];
            cnt = 1;
        }
    }
    if(cnt > max){
        f = 0;
        answer = tmp;
    }
    else if(cnt == max) f = 1;
    if(f) answer = -1;
    return answer;
}