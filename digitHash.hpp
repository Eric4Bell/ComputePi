//
//  DigitHash.hpp
//  ComputePi
//
//  Created by Eric Bell on 11/7/17.
//  Copyright © 2017 Eric Bell. All rights reserved.
//

#ifndef digitHash_hpp
#define digitHash_hpp

#include <stdio.h>
#include <mutex>
#include <unordered_map>

class digitHash{
public:
    void insert(int, int);
    int find(int);
    
    
private:
    std::mutex mtx;
    std::unordered_map<int, int> digitStorage;
};

#endif /* digitHash_hpp */
