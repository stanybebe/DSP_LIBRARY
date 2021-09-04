//
//  envUI.hpp
//  DSP_library
//
//  Created by Mac on 7/5/21.
//


#ifndef envUI_hpp
#define envUI_hpp
#include <stdio.h>
#include "ofMain.h"

#endif /* envUI_hpp */

class envui : public ofBaseApp{

    public:
    
    void setup(int xposIn, int baseIn);
    void draw(float aINmin, float aInmax, float dInmin, float dInmax, float rInmin, float rInmax);
    int xpos;
    int base;
    int xMax;
    int bMax;
    int radiusA, radiusB, radiusC, radiusD, c1;
    double distA, distB, distC, distD;
    bool aF,dF,sF,rF;
    float attackV, decayV, susV, relV;
    float p1x, p2x, p3x, p4x, p5x;
    float p1y, p2y, p3y, p4y, p5y;

    
    //            (p2x,p2y)
    //           /         \
    //          /            (p3x,p3y)------(p4x,p4y)
    //         /                                     \
    // (p1x,p1y)                                      (p5x,p5y)
    // p2x should go between xpos and 50 & p2y should be set to base
    // p3x should go between p2x and 50  & p3y should be set to base + 25
    // p4x should go between p3x and 50  & p4y should be set to base + 25
    // p5x should go between p4x and 25  & p3y should be set to bMax
};
