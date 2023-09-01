#include <iostream>
#include <thread>


int main()
{
    auto lambda = [](int x){
    std::cout << "Testing Thread" << x << std::endl;
    std::cout << "Argument passed in: " << x << std::endl;
    };

    std::thread t1(lambda, 1);
    t1.join();
    std::cout << "Hello from main thread" << std::endl;
    return 0;
}