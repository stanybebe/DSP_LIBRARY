//
//  Slider.h
//  pdExample
//
//  Created by Mac on 8/17/20.
//

#ifndef Slider_h
#define Slider_h
#include "ofMain.h"

class Slider : public ofBaseApp {
    public:
    void setup();
    void update();
    void draw();
    int xPos;
    int xPos2;
    int base;
    int base2;
    float value;
    int radiusM;
    int radiusP;
    bool mouseP;
    double sMap;
    double dist;
    double dist2;
    int preMap;
    int c1;
    Slider();
    
  
    
};


#endif /* Slider_h */
