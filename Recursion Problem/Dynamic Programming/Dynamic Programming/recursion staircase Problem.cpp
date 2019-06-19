#include <iostream>

// tinh tu 1
int num_ways(int n){
    if (n==1 || n==2)
        return 1;
    return num_ways(n-1) + num_ways(n-2);
}

//tinh tu 1
//step 1 or step 2
int num_ways_bottom_up (int n){
    if (n==1 || n==2)
        return 1;
    int *nums = new int [n+1];
    nums[1] = 1;
    nums[2] = 1;
    for (int i=3; i<=n;++i){
        nums[i] = nums[i-1] + nums[i-2];
    }
    int result = nums[n];
    delete [] nums;
    return result;
}
/*
int num_ways_135 (int n){
    if (n==0 )
        return 1;
    return num_ways_135(n-1) + num_ways_135(n-3) + num_ways_135(n-5);
    
} */

//star 1
//step 1 or 3 or 5

int num_ways_135 (int n){
    if (n==1)
        return 1;
    int total = 0;
    for (int i=2; i<=6; i+=2){
        if (n-i>=0)
            total += num_ways_135(n-i);
    }
    return total;
}
int num_ways_bottom_up135(int n){
    if (n==1 )
        return 1;
    if (n==4)//step 3, 1
        return 3;
    if (n==6)//step 5, 3, 1
        return 7;
    int * nums = new int [n+1];
    for (int i=7;i<=n;++i){
        nums[i] = nums[i-1] + nums[i-2] + nums[i-4] + nums[i-6];
    }
    int result = nums[n];
    delete [] nums;
    return result;
}

int main (){
    int n;
    std::cout << "Enter n : ";
    std::cin >> n;
    
    std::cout << num_ways(n) << std::endl;
    std::cout <<num_ways_bottom_up(n) << std::endl;
    std::cout <<num_ways_135(n) << std::endl;
    std::cout << num_ways_bottom_up135(n) <<std::endl;
}
