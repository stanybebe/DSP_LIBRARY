//
//  adsr.hpp
//  DSP_library
//
//  Created by Mac on 7/5/21.
//

#ifndef adsr_hpp
#define adsr_hpp

#include <stdio.h>
#include "ofMain.h"
#endif /* adsr_hpp */

class adsr : public ofBaseApp {
    
public:
    
    float aTime, dTime, sTime, rTime;
    adsr(float iATime ,float iDTime,float iSTime, float iRTime, double SR ){
        sampleRate = SR;
        aTime = iATime;
        dTime = iDTime;
        sTime = iSTime;
        rTime = iRTime;
        calInc(A);
        calInc(D);
        calInc(R);
        currentVal = 0.0;
        state = OFF;
        gate = 0;
        
    }
   
    void process();
    
    void setGate(int nGate){
        int pGate = gate;
        gate = nGate;
        if (pGate ==0 && gate == 1){
            state = A;
        }
        if (pGate ==1 && gate == 0){
            state = R;
        }
        
    }
    
    float getVal(){
      
        calInc(A);
        calInc(D);
        calInc(R);
        return currentVal;
    }
private:
   
    enum states { OFF, A, D, S, R };
    double sampleRate;
    
    float currentVal;
    int gate;
    double aInc, dInc, rInc;
    int state;
    
    
    void calInc ( int iState){
        
        switch (iState) {
            case A:
               aInc = 1/(sampleRate * (aTime*.001));
                break;
            case D:
               dInc = (1-sTime)/(sampleRate * (dTime*.001));
                break;
            case R:
               rInc = (sTime)/(sampleRate * (rTime*.001));
                break;
                    
        }
            
    }
};



