//
//  DigitHash.cpp
//  ComputePi
//
//  Created by Eric Bell on 11/7/17.
//  Copyright © 2017 Eric Bell. All rights reserved.
//

#include "digitHash.hpp"

void digitHash::insert(int key, int digit){
    std::lock_guard<std::mutex> guard(mtx);
    digitStorage.insert({key, digit});
}

int digitHash::find(int key) {
    std::lock_guard<std::mutex> guard(mtx);
    return digitStorage.find(key)->second;
}
