//
//  TaskQueue.cpp
//  ComputePi
//
//  Created by Eric Bell on 11/7/17.
//  Copyright © 2017 Eric Bell. All rights reserved.
//

#include "taskQueue.hpp"

int taskQueue::pop(){
    std::lock_guard<std::mutex> guard(mtx);
    auto task = tasks.front();
    tasks.pop();
    return task;
}

void taskQueue::push(int newValue){
    std::lock_guard<std::mutex> guard(mtx);
    tasks.push(newValue);
}

bool taskQueue::empty(){
    std::lock_guard<std::mutex> guard(mtx);
    auto isEmpty = tasks.empty();
    return isEmpty;
}
