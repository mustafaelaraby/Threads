#include <iostream>
#include <future>

int square(int x){
    return x * x;
}

int main() {
    std::future<int> asyncFunction = std::async(&square,12);

    for(int i = 0; i < 10; i++) {
        std::cout << "square(" << i << ") is: " << square(i) << std::endl;
    }

    int result = asyncFunction.get();

    std::cout << "result is: " << result << std::endl;

    return 0;
}