function solution(n, works) {
    works.sort((a, b) => b - a);
    while(n){
        let maxIndex = 0;
        while(maxIndex < works.length && works[maxIndex] <= works[maxIndex + 1]){
            maxIndex++;
        }
        
        if(works[maxIndex] <= 0) break;
        works[maxIndex]--;
        n--;
    }
    
    const answer = works.reduce((acc, cur, idx) =>{
        return acc += cur * cur; 
    }, 0);
    return answer;
}