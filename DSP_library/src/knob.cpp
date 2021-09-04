//
//  knob.cpp
//  pdExample
//
//  Created by Mac on 8/22/20.
//

#include <stdio.h>
#include "knob.h"
knob::knob(){
    
}
void knob::setup(){
    
    c1 = 10;
    rot= 50;
    radiusM=8;
    radiusP=50;
    //com=true;

    
}
void knob::update(){
    
    
}

void knob::draw(int xPosIn, int baseIn, float range , float rangeMin){
   
   ofFill();
   xPos=xPosIn;
   base =baseIn;
   c1--;
   dist = ofDist(xPos, base, ofGetMouseX(), ofGetMouseY());
    
 
    //( = ! )//
    //   &  //
    // <--> //
    //  ?   //
   
    
    if(ofGetMousePressed()==true){
       
        
        rot = ofGetMouseX();
        if(dist <= radiusP){
            
            if(c1<0){
                
          
           rot = ofGetMouseX();
            
            mP = ofMap(rot ,xPos-radiusP, xPos+radiusP, 0, 360);
                
         
            value = (ofMap(mP, 0, 360, rangeMin, range));
            
            
            cout << "printing"<<endl;
            cout << value <<endl;
                c1=10;
           
            }}

    }
    
    ofRectMode(OF_RECTMODE_CENTER);
    ofPushStyle();
    ofPushMatrix();
   // ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(68, 199, 184);
    ofDrawCircle(xPos, base, radiusP);
    ofTranslate(xPos, base);
    ofRotateDeg(mP);
    cout << mP <<endl;
    ofSetColor(206, 247, 214);
    ofDrawCircle(0, 0, radiusP-25);
    ofSetColor(253, 122, 120);
    ofDrawRectangle(-6, 0, 12, 50);
    ofPopMatrix();
    ofPopStyle();
    ofDrawBitmapString(value, xPos-10, base-radiusP-8);
      
}

