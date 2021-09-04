//
//  xy.h
//  pdExample
//
//  Created by Mac on 8/24/20.
//

#ifndef xy_h
#define xy_h
#include "ofMain.h"

class xy : public ofBaseApp {
    
    public:
    void setup(int xPosIn, int baseIn);
    void update();
    void draw(int xPosIn, int baseIn);
   
    bool com;
    int xPos;
    int xMax;
    int bMax;
    int base;

    double valueX, valX;
    double valueY, valY;
    
    double posX,pX;
    double posY, pY, mX, mAx, mY, mAy;
    
    int radiusM;
    int radiusP;
    double dist;
    double mP,cmP;
    double rot;
    int c1;
    xy();
    
  
    
};
#endif /* toggle_h */

