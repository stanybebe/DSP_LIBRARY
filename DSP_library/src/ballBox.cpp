//
//  ballBox.cpp
//  iosMIDIball
//
//  Created by Mac on 2/7/21.
//
#include "ballBox.h"


ballBox::ballBox(){
    
}
void ballBox::setup(float m, float x, float y, float xpos, float base, float s){
   
    r = mass * 8;
   
    pos.set(x,y);
     
    size = s;
    vel.set(0,0);
     
     
    acc.set(0,0);
     
   
    r= 30;
    
    boxW = xpos;
    boxH = base;
    
    boxWmax = boxW + size;
    boxHmax = boxH + size;
    
    
}

void ballBox::applyForce(ofPoint force){
   
    ofPoint f ;
    f = force/mass;
    acc += f;

}

void ballBox::update(){
    
  
   vel += acc;
   pos += vel;
   acc *= 0;
   

    
    
}

void ballBox::draw(){
 
    
       ofPushMatrix();
       ofSetColor(254,100,97);
      
       ofDrawRectangle(boxW, boxH, size ,  size);
       ofPopMatrix();

     
       ofPushMatrix();
       ofSetColor(41,240,114);
       ofDrawCircle(pos.x,pos.y, r);
       ofPopMatrix();
    
    
 


}
void ballBox::edgeCheck(){
  
    if (pos.x > boxWmax ) {
        pos.x = boxWmax;
        vel.x *= -1;
        col1 = true;
     }
    else if (pos.x < boxW) {
        vel.x *= -1;
        pos.x =boxW;
        col1 = true;
     }
    if (pos.y > boxHmax   ) {
        vel.y *= -1;
       pos.y =boxHmax;
       col1 = true;
    }
    else if (pos.y < boxH) {
        vel.y *= -1;
        pos.y =boxH;
        col1 = true;
        }
 
    
}
