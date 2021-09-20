//
//  Slider.cpp
//  pdExample
//
//  Created by Mac on 8/17/20.
//

#include "Slider.h"

Slider::Slider(){
    
}


//--------------------------------------------------------------
void Slider::setup(){
    
    c1 = 10;
  
  
    value=0;
    radiusM=40;
    radiusP=40;
    
    

    
    
}
void Slider::update(){
//
    xPos2 = xPos;
    base2= base-250;
 
    
    
    
}

void Slider::draw(){
    
   ofFill();
    dist = ofDist(xPos, base, ofGetMouseX(), ofGetMouseY());
    dist2 = ofDist(xPos2, base2, ofGetMouseX(), ofGetMouseY());
   
    if(ofGetMousePressed()==true){
        c1--;
    if(dist<=radiusM){
        if(c1<0){
        value--;
        ofGetMousePressed()==false;
//        cout << "printing"<<endl;
//        cout << value <<endl;
        c1=10;
        }
        }

    }
    
    if(ofGetMousePressed()==true){
        c1--;
    if(dist2<=radiusP){
        if(c1<0){
        value++;
//        cout << "printing"<<endl;
//        cout << value <<endl;
        c1=10;
        }
        }

    }
    
    if (value<=0){
        
        value = 0;
        
    }
    
    if (value>=24){
          
          value = 24;
          
      }
    
    //buttons and bars
    ofPushMatrix();
    sMap=ofMap(value,0,24,0,500);
    ofSetRectMode(OF_RECTMODE_CORNER);
   
    ofSetColor(80,46,232);
    ofDrawCircle(xPos,base, radiusM);
    ofDrawCircle(xPos2,base2, radiusP);
    ofSetColor(41,240,114);
    ofDrawRectangle(xPos +150, base+80, 40, -sMap);
    ofSetColor(80,46,232);
    ofDrawCircle(xPos +170,(base+60)-sMap,60);
     ofPopMatrix();
    //symbols inside buttons
    ofPushMatrix();
    ofSetColor(41,240,114);
    ofDrawBitmapString(value, xPos-25, base-100);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(xPos, base2, 40, 10);
    ofDrawRectangle(xPos, base2, 10, 40);
    ofDrawRectangle(xPos, base, 40, 10);
    ofPopMatrix();
}
