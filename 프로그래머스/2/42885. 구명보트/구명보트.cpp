#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<int>());
    
    int lIdx = 0, rIdx = people.size() - 1;
    
    while(lIdx <= rIdx){
        if(lIdx != rIdx && people[lIdx] + people[rIdx] <= limit) rIdx--;
        
        lIdx++;
        answer++;
    }
    
    
    return answer;
}