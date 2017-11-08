//
//  main.cpp
//  ComputePi
//
//  Created by Eric Bell on 11/7/17.
//  Copyright © 2017 Eric Bell. All rights reserved.
//

#include <iostream>
#include <thread>
#include <vector>
#include "taskQueue.hpp"
#include "digitHash.hpp"
#include "computePiDigit.hpp"

//    each thread:
//    pop front task of queue
//    compute digit
//    store digit into hash table
void findAndStorePiDigit(taskQueue & myTaskQueue, digitHash & myDigitHash) {
    while (!myTaskQueue.empty()) {
        std::cout << ".";
        std::cout.flush();
        int digitToFind = myTaskQueue.pop();
        int piDigitFound = compute::computePiDigit(digitToFind);
        myDigitHash.insert(digitToFind, piDigitFound);
    }
}

int main(int argc, const char * argv[]) {
    
    //declare queue and hash table
    const int NUMBER_OF_THREADS = std::thread::hardware_concurrency();
    taskQueue myTaskQueue;
    digitHash myDigitHash;
    
    //forEach 1-1000 add to queue
    for (int i = 1; i <= 1000; i++) {
        myTaskQueue.push(i);
    }
    
    //multithread
    std::vector<std::thread> threadPool;
    for (int i = 0; i < NUMBER_OF_THREADS; i++){
        threadPool.push_back(std::thread(findAndStorePiDigit, std::ref(myTaskQueue), std::ref(myDigitHash)));
    }
    
    for (auto& th : threadPool) th.join();

    std::cout << std::endl << std::endl;
    std::cout << "3.";
    for (int i = 1; i <= 1000; i++) {
        std::cout << myDigitHash.find(i);
    }
    
    std::cout << std::endl << std::endl;
    
    return 0;
}
