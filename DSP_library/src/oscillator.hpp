//
//  oscillator.hpp
//  DSP_library
//
//  Created by Mac on 6/10/21.
//

#ifndef oscillator_hpp
#define oscillator_hpp
#include "ofMain.h"
#include <stdio.h>

#endif /* oscillator_hpp */
class oscillator : public ofBaseApp {
    
    public:
    
    void setup(float freq_, double phase_, int sampleRate_, float amp_);
    float getSine();
    float getPhasor();
    float getSaw();
    void setFreq(float freq);
    void setAmp( float amp);
    
    oscillator();
    
    double phase;
    double phaseInc;
    float frequency;
    float amplitude;
    float currentSample;
    int sampleRate;
    
    
};
