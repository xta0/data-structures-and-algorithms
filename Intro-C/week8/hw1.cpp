#include <iostream>

int main(){

    int x = 0,y=0;
    std::cin >> x;
    int sum = 0;
    for (int i=0;i<5;i++){
        std::cin >> y;
        if(y<x){
            sum+=y;
        }
    }
    std::cout<<sum;

    return 0;
}