//
//  toggle.cpp
//  pdExample
//
//  Created by Mac on 8/22/20.
//

#include "toggle.h"
toggle::toggle(){
    
}
void toggle::setup(){
    
      c1 = 10;
    
    radiusM=48;
    radiusP=50;
    //com=true;
    value = false;
    
    
    
}
void toggle::update(){

 
    
    
    
}

void toggle::draw(int xp, int yp){
   xPos = xp;
   base = yp;
   ofFill();
   c1--;
   dist = ofDist(xPos, base, ofGetMouseX(), ofGetMouseY());
    
 
    //( = ! )//
    //   &  //
    // <--> //
    //  ?   //
   
    
    if(ofGetMousePressed()==true){
       
          
        if(dist <= radiusP){
            if(c1<0){
            value=!value;
            cout << "printing"<<endl;
            cout << value <<endl;
            c1 = 10;
           
            }}

    }
      
   
    
    if (value == true){
           ofPushMatrix();
           ofSetColor(4, 228, 165);
        
           ofDrawCircle(xPos,base, radiusP);
           ofSetColor(0);
           ofDrawCircle(xPos,base, radiusM);
           ofDrawBitmapString("on", xPos-10, base-20);
           ofPopMatrix();
           
           
    }
       
       if (value == false){
           
           ofPushMatrix();
           ofSetColor(41,240,114);
           ofDrawCircle(xPos,base, radiusP);
           ofDrawBitmapString("off", xPos-10, base-20);
           ofPopMatrix();
             
    }
    
    
  
   
   
   


}
