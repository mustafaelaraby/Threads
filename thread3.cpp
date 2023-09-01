#include <iostream>
#include <thread>
#include <vector>


int main()
{
    auto lambda = [](int x){
    std::cout << "Hello From Thread: " << std::this_thread::get_id()<< std::endl;
    std::cout << "Argument passed in: " << x << std::endl;
    };

    // std::vector<std::thread> threads;
    // for (size_t i = 0; i < 10; i++)
    // {
    //     threads.push_back(std::thread(lambda, i));
    //     threads[i].join();
    // }

    //ouput...
    /*
        Hello From Thread: 2
        Argument passed in: 0
        Hello From Thread: 3
        Argument passed in: 1
        Hello From Thread: 4
        Argument passed in: 2
        Hello From Thread: 5
        Argument passed in: 3
        Hello From Thread: 6
        Argument passed in: 4
        Hello From Thread: 7
        Argument passed in: 5
        Hello From Thread: 8
        Argument passed in: 6
        Hello From Thread: 9
        Argument passed in: 7
        Hello From Thread: 10
        Argument passed in: 8
        Hello From Thread: 11
        Argument passed in: 9
        Hello from main thread
    */

       std::vector<std::thread> threads;
    for (size_t i = 0; i < 10; i++)
    {
        threads.push_back(std::thread(lambda, i));
    }

    for (size_t i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }

    //output...
    /*
        Hello From Thread: 2
        Hello From Thread: 3
        Argument passed in: 1
        Hello From Thread: 5
        Argument passed in: 3
        Hello From Thread: 6
        Argument passed in: 4
        Hello From Thread: 9
        Argument passed in: 7
        Argument passed in: 0
        Hello From Thread: 7
        Argument passed in: 5
        Hello From Thread: 10
        Argument passed in: 8
        Hello From Thread: 4
        Argument passed in: 2
        Hello From Thread: 8
        Argument passed in: 6
        Hello From Thread: 11
        Argument passed in: 9
        Hello from main thread
    */
    
    std::cout << "Hello from main thread" << std::endl;
    return 0;
}