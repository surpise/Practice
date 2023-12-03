function solution(A,B){
    let tmp1 = 0;
    
    A.sort((a, b) => a - b);
    B.sort((a, b) => b - a);
    for(let i = 0; i < A.length; i++){
        tmp1 += A[i] * B[i];
    }
    
    let tmp2 = 0;
    A.sort((a, b) => b - a);
    B.sort((a, b) => a - b);
    for(let i = 0; i < A.length; i++){
        tmp2 += A[i] * B[i];
    }
    
    if(tmp1 > tmp2){
        return tmp1;
    }
    else{
        return tmp2;
    }
}