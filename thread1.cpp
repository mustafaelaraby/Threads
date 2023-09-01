#include <iostream>
#include <thread>


void test(int x){
    std::cout << "Testing Thread" << x << std::endl;
    std::cout << "Argument passed in: " << x << std::endl;
}

int main()
{
    std::thread t1(&test, 1);
    t1.join();
    std::cout << "Hello from main thread" << std::endl;
    return 0;
}