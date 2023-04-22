#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0, t;
    for(int i = 0; i < section.size(); i++){
        t = section[i];
        answer++;
        while(i < section.size() && t + m - 1 >= section[i]) i++;
        i--;
    }
    return answer;
}