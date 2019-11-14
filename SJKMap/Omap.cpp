//
//  Omap.cpp
//  SJKMap
//
//  Created by Daniel Varivoda on 11/11/19.
//  Copyright © 2019 Daniel Varivoda. All rights reserved.
//

#include "Omap.hpp"

//takes in a4 400 character string as an argument and creates a private member which is a 20x20 vector
//this vector is the final output with all the Os and spacesconverted to the correct tiles denoted by a char
Omap::Omap(std::string m): map_data(m)
{
    fin_map = create_map(m);
}

//takes a string with 400 chars and converts it to a 20x20 string array
std::vector<std::vector<char>> Omap::Convert_string(std::string map)
{
    //set position in string to iterate over, as well as the size and row of columns
    size_t pos = 0;
    size_t row = 20;
    size_t col = 20;
    
    //create a 2D vector to return
    std::vector<std::vector<char>> converted;
    //set size
    converted.resize(20);

    //iterate through string and copy the first 20 chars to the the first row, etc...
    for(int r = 0; r < row; r++)
    {
        converted[r].resize(20);
        for(int c = 0; c < col; c++)
        {
            converted[r][c] = map[pos];
            pos++;
        }
    }
    
    //converted vector
    return converted;
}

//takes the 400 char string and converts it to a useable map of chars for the level
std::vector<std::vector<char>> Omap::create_map(std::string map)
{
    //use you method to convert the original string
    std::vector<std::vector<char>> converted = Convert_string(map);
    //size of the vector to be returned
    size_t row = 20;
    size_t col = 20;
    //converted map to be returned
    std::vector<std::vector<char>> omap;
    omap.resize(20);
    
    for(int r = 0; r < row; r++)
    {
        omap[r].resize(20);
        for(int c = 0; c < col; c++)
        {
            //for the top row only
            if(r == 0)
            {
                if(c == 0)
                {
                    omap[r][c] = 's';
                }
                else if( c == 19)
                {
                    omap[r][c] = 'x';
                }
                else
                {
                    omap[r][c] = 'p';
                }
            }
            
            else if(r==19)
            {
                if(c == 19)
                {
                    omap[r][c] = 's';
                }
                else if( c == 0)
                {
                    omap[r][c] = 'x';
                }
                else
                {
                    omap[r][c] = 'p';
                }
            }
            
            else if((c == 0 || c == 19) && (r != 0 || r != 19))
            {
                omap[r][c] = 'q';
            }
            
            else if(converted[r][c] == 'O')
            {
                //horizontal bar: Space above or Below only
                if((converted[r+1][c] == ' ' || converted[r-1][c] == ' ') && (converted[r][c-1] != ' ' && converted[r][c+1] != ' ') )
                {
                    omap[r][c] = 'p';
                }
                
                //Vertical: Space left or right
                else if((converted[r][c+1] == ' ' || converted[r][c-1] == ' ') && (converted[r+1][c] != ' ' && converted[r-1][c] != ' ') )
                {
                    omap[r][c] = 'q';
                }
                
                //L Angle: space below and on the left
                else if(converted[r][c-1] == ' ' && converted[r+1][c] == ' ')
                {
                    omap[r][c] = 'w';
                }
                
                //r Angle: space above and on the left
                else if(converted[r][c-1] == ' ' && converted[r-1][c] == ' ')
                {
                    omap[r][c] = 's';
                }
                
                //downleft Angle: space below and on the right
                else if(converted[r][c+1] == ' ' && converted[r+1][c] == ' ')
                {
                    omap[r][c] = 't';
                }
                
                //upright angle: above and on the right
                else if(converted[r][c+1] == ' ' && converted[r-1][c] == ' ')
                {
                    omap[r][c] = 'x';
                }
                
                //half horiz L: space above below and left
                else if(converted[r-1][c] == ' ' && converted[r][c-1] == ' ' && converted[r+1][c] == ' ')
                {
                    omap[r][c] = 'v';
                }
                
                
                //half hor R: above below and right
                else if(converted[r-1][c] == ' ' && converted[r][c+1] == ' ' && converted[r+1][c] == ' ')
                {
                    omap[r][c] = 'r';
                }
                
                //half vertical U: above left and right
                else if(converted[r-1][c] == ' ' && converted[r][c-1] == ' ' && converted[r][c+1] == ' ')
                {
                    omap[r][c] = 'u';
                }
                
                //half vert D: space below left and right
                else if(converted[r+1][c] == ' ' && converted[r][c-1] == ' ' && converted[r][c+1] == ' ')
                {
                    omap[r][c] = 'y';
                }
                
                //Center block: space all around
                else if(converted[r-1][c] == ' ' && converted[r][c-1] == ' ' && converted[r+1][c] == ' ' && converted[r][c+1] == ' ')
                {
                    omap[r][c] = 'z';
                }
            }
            else if(converted[r][c] == ' ')
            {
                //vertical
                if(converted[r-1][c] == '0' && converted[r+1][c] == '0')
                {
                    omap[r][c] = 'a';
                }
                
                //Vertical: topend
                else if(converted[r+1][c] == '0' && converted[r-1][c] != '0')
                {
                    omap[r][c] = 'b';
                }
                
                //Vertical: botend
                else if(converted[r+1][c] == '0' && converted[r-1][c] != '0')
                {
                    omap[r][c] = 'c';
                }
                
                //Horizontal
                else if(converted[r][c] == '0' && converted[r][c] == '0')
                {
                    omap[r][c] = 'd';
                }
                //Horizontal: leftend
                else if(converted[r][c+1] == '0' && converted[r][c-1] != '0')
                {
                    omap[r][c] = 'e';
                }
                //Horizontal: rightend
                else if(converted[r][c+1] != '0' && converted[r][c-1] == '0')
                {
                    omap[r][c] = 'f';
                }
                //T shape
                else if(converted[r][c+1] == '0' && converted[r][c-1] == '0' && converted[r+1][c] == '0')
                {
                    omap[r][c] = 'g';
                }
                //T shape:upside down
                else if(converted[r][c+1] == '0' && converted[r][c-1] == '0' && converted[r-1][c] == '0')
                {
                    omap[r][c] = 'h';
                }
                //T shape:Left
                else if(converted[r][c+1] == '0' && converted[r+1][c] == '0' && converted[r-1][c] == '0')
                {
                    omap[r][c] = 'i';
                }
                //T shape:right
                else if(converted[r][c-1] == '0' && converted[r+1][c] == '0' && converted[r-1][c] == '0')
                {
                    omap[r][c] = 'j';
                }
                //+ shape
                else if(converted[r][c+1] == '0'&& converted[r][c-1] == '0' && converted[r+1][c] == '0' && converted[r-1][c] == '0')
                {
                    omap[r][c] = 'k';
                }
                
                //L angle
                else if(converted[r][c+1] == '0' && converted[r-1][c] == '0')
                {
                    omap[r][c] = 'l';
                }
                
                //r angle
                else if(converted[r][c+1] == '0' && converted[r+1][c] == '0')
                {
                    omap[r][c] = 'm';
                }
                
                //upside down r angle
                else if(converted[r][c-1] == '0' && converted[r-1][c] == '0')
                {
                    omap[r][c] = 'n';
                }
                
                //backwards r angle
                else if(converted[r][c-1] == '0' && converted[r+1][c] == '0')
                {
                    omap[r][c] = 'o';
                }
            }
        }
    }
    
    return converted;
}

std::vector<std::vector<char>> Omap::get_map()
{
    return fin_map;
}
