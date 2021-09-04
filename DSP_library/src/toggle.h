//
//  toggle.h
//  pdExample
//
//  Created by Mac on 8/22/20.
//

#ifndef toggle_h
#define toggle_h





#include "ofMain.h"

class toggle : public ofBaseApp {
    public:
    void setup();
    void update();
    
    void draw(int xp, int yp);
    bool com;
    int xPos;
 
    int base;

    bool value;
    int radiusM;
    int radiusP;
    double dist;
    int c1;
    toggle();
   
    
  
    
};
#endif /* toggle_h */

