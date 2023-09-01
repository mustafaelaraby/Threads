#include <iostream>
#include <future>
#include <thread>
#include <chrono>

bool bufferedFileLoader(){
    size_t bytesLoaded = 0;
    while(bytesLoaded < 20000){
        std::cout << "Loading file... " << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        bytesLoaded += 1000;
    }
    return true;
}


int main(){
    std::future<bool>backGroundThread = std::async(std::launch::async, bufferedFileLoader);
    std::future_status status;
    while(true){
        std::cout << "Main Thread is Running" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status = backGroundThread.wait_for(std::chrono::milliseconds(1));
        if(status == std::future_status::ready){
            std::cout << "Our Data is Ready..." << std::endl;
            break;
        }
    }

    std::cout << "Program is Complete." << std::endl;
}