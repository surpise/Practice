const fibo = (n, arr = {}) => {
    
}

function solution(n) {
    if(n === 0) return 0;
    if(n === 1) return 1;
    
    let l = 0, r = 1, res = 0;
    for(let idx = 2; idx <= n; idx++){
        res = (l + r) % 1234567;
        l = r;
        r = res;
    }
    
    return res;
}