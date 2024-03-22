#include <vector>

using namespace std;

int calcCnt(int startD, int endD, int w){
    int range = endD - startD + 1;
    int antena = 2 * w + 1;
    
    if(range <= 0) return 0;
    if(range % antena == 0) return range / antena;
    return (range / antena) + 1;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    for(int idx = 0; idx < stations.size(); idx++){
        if(idx == 0) answer += calcCnt(1, stations[idx] - w - 1, w);
        else answer += calcCnt(stations[idx - 1] + w + 1, stations[idx] - w - 1, w);
    }
    answer += calcCnt(stations[stations.size() - 1] + w + 1, n, w);
    
    return answer;
}