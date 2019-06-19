
#include <iostream>

int fib (int n){
    if (n==1 || n==2)
        return 1;
    else
        return fib(n-1)  + fib(n-2);
}

int fib2 (int n, int *memo){
    if (memo[n-1] != -1)
        return memo[n-1];
    
    if (n==1 || n==2)
        memo[n-1]= 1;
    else
        memo[n-1]= fib2(n-1,memo) + fib2(n-2,memo);
    return memo[n-1];
}

int fib_bottom_up (int n){
    
    int *memo = new int [n+1];
    memo[1] = 1;
    memo[2] = 1;
    if (n==1 || n==2)
        return 1;
    for (int i=3;i<=n;++i){
        memo[i] = memo[i-1] + memo[i-2];
    }
    int result = memo[n];
    delete [] memo;
    return result;
}

int fib_bottom_up2 (int n){
    if (n==1 || n==2)
        return 1;
    int *memo = new int [n];
    memo[0] = 1;
    memo[1] = 1;
    if (n==1 || n==2)
        return 1;
    for (int i=2;i<n;++i){
        memo[i] = memo[i-1] + memo[i-2];
    }
    int result = memo[n-1];
    delete [] memo;
    return result;
}

int main (){
    int n;
    std::cout << "Enter n : ";
    std::cin >> n;
    
   
    int *array = new int [n];
    for (int i=0;i<n;++i)
        array[i]=-1;
    std::cout << fib2(n, array)<<std::endl;
    
   
    std::cout << fib_bottom_up(n)<<std::endl;
    std::cout << fib_bottom_up2(n) <<std::endl;
    
    std::cout << fib(n)<< std::endl;
    
    delete []array;
    
}
