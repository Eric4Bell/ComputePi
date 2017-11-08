//
//  TaskQueue.hpp
//  ComputePi
//
//  Created by Eric Bell on 11/7/17.
//  Copyright © 2017 Eric Bell. All rights reserved.
//

#ifndef taskQueue_hpp
#define taskQueue_hpp

#include <stdio.h>
#include <mutex>
#include <queue>

class taskQueue {
    
public:
    
    int pop();
    void push(int);
    bool empty();
    
private:
    
    std::queue<int> tasks;
    std::mutex mtx;
    
};

#endif /* taskQueue_hpp */
