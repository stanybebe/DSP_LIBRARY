//
//  pad.h
//  smalldrum
//
//  Created by Mac on 10/16/20.
//

#ifndef pad_h
#define pad_h

#include <stdio.h>
#include "ofMain.h"
class pad : public ofBaseApp {
    public:
    void setup(int p);
    void update();
    void draw(int xp, int yp);
    bool com;
    int xPos;
    int base;
    int xMax;
    int bMax;
    bool value;
    int radiusM;
    int radiusP;
    double dist;
    int c1;
    int pitch;
    pad();
    
    int shp;
    
    
   
    
  
    
};


#endif /* pad_hpp */
