//
//  knob.h
//  pdExample
//
//  Created by Mac on 8/22/20.
//

#ifndef knob_h
#define knob_h


#include "ofMain.h"

class knob : public ofBaseApp {

public:
void setup();
void update();
void draw(int xPosIn, int baseIn, float range, float rangeMin);
    

    bool com;
    int xPos;
 
    int base;

    double value;
    int radiusM;
    int radiusP;
    double dist;
    double mP,cmP;
    double rot;
    int c1;
    knob();
    
    
  
    
};
#endif /* toggle_h */
