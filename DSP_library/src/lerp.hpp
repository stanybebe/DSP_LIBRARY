//
//  lerp.hpp
//  DSP_library
//
//  Created by Mac on 6/25/21.
//

#ifndef lerp_hpp
#define lerp_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* lerp_hpp */
            
                
class lerp : public ofBaseApp {
    
    
    
public:
    
    lerp (float smoothingTime, float sampleRate){
     a = exp(-TWO_PI)/ (smoothingTime *.001 * sampleRate);
     b = 1.0 -a;
     z = 0.0;
    }
     
    inline float process ( float input){
        z = (input * b) + (z*a);
        return z;
        }
    

    
    float a;
    float b;
    float z;
    
};

struct lerpVal {
    float targetVal;
    float currentVal;
    
    lerp* lerp_object;
};
    
