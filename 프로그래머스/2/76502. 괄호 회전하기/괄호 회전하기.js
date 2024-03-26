const isCorrect = (str) => {
    const arr = [];
    const leftB = ['(', '{', '['];
    const rightB = [')', '}', ']'];
    
    for(let idx = 0; idx < str.length; idx++){
        if(leftB.includes(str[idx])){
            arr.push(str[idx]);
        }
        
        else if(rightB.includes(str[idx])){
            const bIdx = rightB.indexOf(str[idx]);
            
            if(arr[arr.length - 1] === leftB[bIdx]){
                arr.pop();
            }
            
            else return false;
        }
    }
    
    if(arr.length) return false;
    else return true;
}

function solution(s) {
    var answer = 0;
    
    for(let t = 0; t < s.length; t++){
        if(isCorrect(s)) answer++;
        
        const tmp = s[0];
        s = s.substr(1);
        s += tmp;
    }
    
    return answer;
}