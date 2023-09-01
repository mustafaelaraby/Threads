#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

std::mutex gLock;
std::condition_variable gConditionVariable;

int main(){

    int result = 0;
    bool notified = false;

    // roporting thread.
    std::thread reporter([&]{
        std::unique_lock<std::mutex> lock(gLock);
        if(!notified){
            gConditionVariable.wait(lock);
        }
        std::cout << "reporter: " << result << std::endl;
    });


    // worker thread.
    std::thread worker([&]{
        std::unique_lock<std::mutex> lock(gLock);
        result = 42 + 1 + 7;
        notified = true;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "work completed \n";
        gConditionVariable.notify_one();
    });

    reporter.join();
    worker.join();
}