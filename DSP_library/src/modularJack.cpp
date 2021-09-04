//
//  modularJack.cpp
//  DSP_library
//
//  Created by Mac on 7/21/21.
//

#include "modularJack.hpp"

modJack:: modJack(){
    
}

void modJack::setup(int xPos, int Base, string name){
    
    xpos = xPos;
    base = Base;
    Name = name;
    xMax = xpos + 10;
    bMax = base + 10;
    
    
}

void modJack:: draw(bool isIn){
    
    
    if (isIn != true){
        
    }
    
    ofDrawSphere(xpos, base, 10);
    
    
}

