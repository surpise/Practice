#include <string>
#include <vector>
#include <set>
using namespace std;

#define MAX 9999999

int ans = 0;
bool primes[10000000], visited[7];
int res[7];
vector<int> v;
set<int> s;


void p(int sz, int depth){
    if(sz == depth){   
        if(res[0] == 0) return;
        
        int tmp = 0;
        for(int idx = 0; idx < depth; idx++){
            tmp *= 10;
            tmp += res[idx];
        }
        s.insert(tmp);
    }
    
    for(int idx = 0; idx < v.size(); idx++){
        if(!visited[idx]){
            visited[idx] = 1;
            res[depth] = v[idx];
            p(sz, depth + 1);
            visited[idx] = 0;
        }
    }
}

int solution(string numbers) {
    primes[0] = 1;
    primes[1] = 1;
    
    for(int i = 2; i <= MAX; i++){
        for(int j = 2; i * j < MAX; j++) primes[i * j] = 1;
    } 
    
    for(int idx = 0; idx < numbers.size(); idx++){
        v.push_back(numbers[idx] - '0');
    }
    
    for(int i = 1; i <= v.size(); i++) p(i, 0);
    
    for(auto e = s.begin(); e != s.end(); e++){
        if(!primes[*e]) ans++;
    }
    
    return ans;
}