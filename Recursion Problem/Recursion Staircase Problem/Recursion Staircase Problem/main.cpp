
#include <iostream>

//num_ways(N) = num_ways(N-1) + num_ways(N-2)
//num_ways(0) = 1
//num_ways(1) = 1
//dynamic programming

//n la so bac thang
// n day so 12345
// n mang 01234
int num_ways(int n){
    if (n == 0|| n == 1)
        return 1;
    else
        return num_ways(n-1) + num_ways(n-2);
    
}

int num_ways_bottom_up (int n){
    if (n==0 || n==1)
        return 1;
    int * nums = new int [n+1];
    nums[0] = 1;
    nums[1] = 1;
    for (int i=2; i<n+1 ; ++i){
        nums[i] = nums[i-1] + nums[i-2];
    }
    int a = nums[n];
    delete [] nums;
    return a;
   
}

int num_ways_X (int n){
    if (n==0 || n==1 )
        return 1;
    if (n==3)
        return ;
    if (n==5)
        return ;
    
   
    return num_ways(n-1) + num_ways(n-3) +num_ways(n-5);
    
}

int num_ways_x (int n){
    if (n==0)
        return 1;
    int total = 0;
    
    for (int i=1; i<6; i+=2 ){
        if ((n-i) >=0 )
            total += num_ways_x (n-i);
        
    }
    return total;
    
}
int num_ways_bottom_up_x(int n){
    if (n==0) return 1;
    int *nums = new int[n+1];
    nums[0] = 1;
    int total;
    for (int i=0;i<n;++i){
         total = 0;
        for (int j=1; j<=5; j+=2)
            if (i-j>=0)
                total +=nums[i-j];
        nums[i] = total;
    }
    return nums[n];
}

int main(int argc, const char * argv[]) {
    int n;
    std::cout << "Enter n : ";
    std::cin  >>n;
    
    std::cout << num_ways_bottom_up(n);
    std::cout << std::endl;
    
    std::cout<< num_ways(n);
    std::cout << std::endl;
    

    std::cout <<  num_ways_X(n);//step 1 3 5
    std::cout << std::endl;
    
    /*
    std::cout << num_ways_x(n);
    std::cout << std::endl;
    
    std::cout << num_ways_bottom_up_x(n);
    std::cout << std::endl; */
    
 }
