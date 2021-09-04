//
//  modularJack.hpp
//  DSP_library
//
//  Created by Mac on 7/21/21.
//

#ifndef modularJack_hpp
#define modularJack_hpp

#include <stdio.h>

#endif /* modularJack_hpp */
#include "ofMain.h"
class modJack : public ofBaseApp {
    modJack();
    void setup( int xPos, int Base, string name);
    void draw( bool isIn);
    int xpos;
    int base;
    int xMax;
    int bMax;
    string Name;
    int xIn, yIn;
    bool isConnected;
    
    
    
};
