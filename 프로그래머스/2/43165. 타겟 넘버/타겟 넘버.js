function solution(numbers, target) {
    let answer = 0;
    
    const dfs = (cnt, sum) => {
        if(cnt === numbers.length){
            if(sum === target){
                answer++;
            }
            return;
        }
        
        dfs(cnt + 1, sum + numbers[cnt]);
        dfs(cnt + 1, sum - numbers[cnt]);
    }
    
    dfs(0, 0);
    return answer;
}