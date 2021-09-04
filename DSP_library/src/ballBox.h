//
//  ballBox.h
//  iosMIDIball
//
//  Created by Mac on 2/7/21.
//

#ifndef ballBox_h
#define ballBox_h

#include "ofMain.h"
#endif /* ballBox_h */

class ballBox : public ofBaseApp {
    
    public:
    void setup(float m, float x, float y,float xpos, float base, float s);
    void applyForce(ofPoint  force);
    void update();
    void draw();
    void edgeCheck();
    float x,y,mass, r, size;
    
    
    float boxW, boxH, boxWmax, boxHmax;
    
    
    ofPoint  pos;
    
    
    ofPoint  vel;
    
    
    ofPoint  acc;
    
    bool col1, col2, col3, col4;
    
    
    ballBox();
    
    
    
    
    
    
    
};
