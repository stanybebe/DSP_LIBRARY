//
//  panner.cpp
//  DSP_library
//
//  Created by Mac on 6/15/21.
//

#include "panner.hpp"

stereoFrame Panner:: pan(float input, float pos){
    stereoFrame currentSamp;
    
    if (pos > 1){
        pos = 1;
    }
    
    if (pos < -1){
        pos = -1;
    }
    
    float theta = pos * 45;
    theta = ofDegToRad(theta);
    float sinT = sin(theta);
    float cosT = cos(theta);
    
    currentSamp.leftSamp = input * sqTwo * (sinT-cosT);
    currentSamp.rightSamp = input * sqTwo * (sinT+cosT);
    
    
    return currentSamp;
    
}


