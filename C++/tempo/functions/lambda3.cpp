#include <functional>

std::function<int(int)> makeLambda(int a){    
    return [a](int b){ return a + b; };
}

int main(){
    
    auto add5 = makeLambda(5);      
    
    auto add10 = makeLambda(10);      
    
    add5(10) == add10(5);               
    
}