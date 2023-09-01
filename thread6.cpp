#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std:: mutex gLock;

static int shared_value = 0;

void shared_value_increment(){
    std::lock_guard<std::mutex> lock_guard(gLock);
    shared_value+=1;
}

int main(){
    std::vector<std::thread> threads;
    for(size_t i = 0; i < 1000; i++) {
        threads.push_back(std::thread(shared_value_increment));
    }

    for(size_t i = 0; i <threads.size(); i++){
        threads[i].join();
    }
    std::cout <<"Shared Value: " << shared_value << std::endl;
}