//
//  oscillator.cpp
//  DSP_library
//
//  Created by Mac on 6/10/21.
//
#include "ofMain.h"
#include "oscillator.hpp"
oscillator::oscillator(){
    
}
void oscillator::setup(float freq_, double phase_, int sampleRate_, float amp_){
    sampleRate = sampleRate_;
    frequency = freq_;
    phase = phase_;
    amplitude = amp_;
    phaseInc = (TWO_PI*frequency)/(float)sampleRate;
    currentSample=0;
    
    
}
float oscillator::getSine(){
//    sine
   
    phase+= phaseInc;
    currentSample = sin(phase)*amplitude;
  //  if ( phase >= 1.0 ) phase -= 2.0;
    return currentSample;
    
}

float oscillator::getPhasor(){
    
    currentSample=phase*amplitude;
    if ( phase >= 1.0 ) phase -= 1.0;
    phase += (1./(sampleRate/(frequency)));
    return(currentSample);
 
}

float oscillator::getSaw(){
    //Sawtooth generator. This is like a phasor but goes between -1 and 1
    currentSample=phase*amplitude;
    if ( phase >= 1.0 ) phase -= 2.0;
    phase += (1./(sampleRate/(frequency)));
    return(currentSample);
    
}

void oscillator::setFreq(float freq){
    frequency = freq;
    phaseInc = (TWO_PI*frequency)/(float)sampleRate;
}

void oscillator:: setAmp( float amp){
    amplitude = amp;
}


