
#include <iostream>

int add (int x, int y){
    return x+y;
}
int mul (int x, int y){
    return x*y;
}


//typedef char* string0
typedef int (*Operation)(int,int);
int calc (int x, int y,Operation p){
    return p(x,y);
}

int calc (int x, int y, int(*p)(int,int));

int main(int argc, const char * argv[]) {
    std::cout << add (2,3);
    std::cout << mul (2,3);
    std::cout << calc (2,3,add);
    
    
}
