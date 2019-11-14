//
//  Omap.hpp
//  SJKMap
//
//  Created by Daniel Varivoda on 11/11/19.
//  Copyright © 2019 Daniel Varivoda. All rights reserved.
//

#ifndef Omap_hpp
#define Omap_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class Omap
{
private:
    std::string map_data;
    std::vector<std::vector<char>> fin_map;

public:
    Omap(std::string md);
    std::vector<std::vector<char>> Convert_string(std::string map);
    std::vector<std::vector<char>> create_map(std::string map);
    std::vector<std::vector<char>> get_map();
};

#endif /* Omap_hpp */
