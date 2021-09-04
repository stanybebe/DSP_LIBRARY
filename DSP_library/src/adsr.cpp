//
//  adsr.cpp
//  DSP_library
//
//  Created by Mac on 7/5/21.
//

#include "adsr.hpp"

void adsr::process(){
    
    switch (state) {
        case OFF:
            //off
            currentVal = 0.0;
        break;
            
        case A:
            //attack
            currentVal += aInc;
            if (currentVal>= 1.0){
                currentVal = 1.0;
                state = D;
            }
        break;
            
        case D:
            //decay
            currentVal -= dInc;
            if (currentVal <= sTime){
                currentVal = sTime;
                state = S;
            }
            
        break;
            
        case S:
            //sustain
            currentVal = sTime;
            
        break;
        
        case R:
            //release
            currentVal -= rInc;
            if ( currentVal <= 0){
                currentVal = 0;
                state = OFF;
            }
        break;
            
            
            
            
     
    }}

//void adsr::setVals (float iATimeB ,float iDTimeB,float iSTimeB, float iRTimeB){
//
//      aTime = iATimeB;
//      dTime = iDTimeB;
//      sTime = iSTimeB;
//      rTime = iRTimeB;
//
//
//
//}
