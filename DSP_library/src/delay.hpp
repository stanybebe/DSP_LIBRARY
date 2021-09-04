//
//  delay.hpp
//  DSP_library
//
//  Created by Mac on 7/23/21.
//

#ifndef delay_hpp
#define delay_hpp

#include <stdio.h>
#include "ofMain.h"
#endif /* delay_hpp */



class delayIn: public ofBaseApp{
    public:
    
    float* buffer;
    int wIndex;
    int size;
    float sampleRate;
  
    
    delayIn(float timeMS, int SampleRate){
     
        static const int _size = (timeMS * .001 *  SampleRate);
        buffer = new float[_size];
        wIndex = 0;
        sampleRate = SampleRate;
        for(int i = 0; i < size; i++){buffer[i] = 0; }
        size = _size;
    }
    

    
    float feed( float sample){
        buffer[wIndex] = sample;
        wIndex++;
        if (wIndex>=size){
            wIndex = 0;
        }
        
    }
   
    
  
    
};

class delayOut: public ofBaseApp{
     public:
    
    float* ref;
    
    int size;
    int rIndex;
    int sampleRate;
   
    
   
    delayIn* inRef;
    
    delayOut(delayIn* inref, float timeMS){
        ref = inref->buffer;
        size =inref->size;
        sampleRate = inref->sampleRate;
        rIndex = size - (timeMS * 0.001 *  sampleRate)-1;
        inRef = inref;
      
    
    }
    
    float getSample(){
       float temp = ref[rIndex];
        rIndex ++;
        if (rIndex>= size){
            rIndex = 0;
        }
        return temp;
    }
    
    void setTime (float time_MS){
        int temp = ( time_MS * 0.001 *  48000);
        rIndex = inRef->wIndex - temp;
        if(rIndex < 0){rIndex += size;}
    }
    
    
    
    
    
    
    
    
};

