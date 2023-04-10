#include <string>
#include <set>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> s;
    vector<int> answer;
    for(int i = 0; i < numbers.size(); i++){
        for(int j = i + 1; j < numbers.size(); j++) s.insert(numbers[i] + numbers[j]);
    }
    for(auto e = s.begin(); e != s.end(); e++) answer.push_back(*e);
    return answer;
}