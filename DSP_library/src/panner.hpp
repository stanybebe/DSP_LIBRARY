

#include <stdio.h>
#include "ofMain.h"


struct stereoFrame{
    
    float leftSamp;
    float rightSamp;
    
    
};

class Panner : public ofBaseApp {
    
public:
    stereoFrame pan(float input, float pos);
private:
    float sqTwo = sqrt(2)/(float)2;
    
};
