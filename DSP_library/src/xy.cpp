#include <stdio.h>



#include "xy.h"
xy::xy(){
    
}
void xy::setup(int xPosIn, int baseIn){
    
    c1 = 5;
    rot= 50;
    radiusM=8;
    radiusP=20;
    //com=true;
    
    
    xMax = xPos+120;
    bMax = base+120;
    
    pX = xPosIn + 60;
    pY = baseIn + 60;
    

    
    
}
void xy::update(){

 
    
    
    
}

void xy::draw(int xPosIn, int baseIn){
   
   xPos=xPosIn;
   base =baseIn;
    
    //( = ! )//
    //   &  //
    // <--> //
    //  ?   //
   
    
    if(ofGetMousePressed()==true){
       
        if(ofGetMouseX()>xPos && ofGetMouseX()<xPos+xMax && ofGetMouseY()>base && ofGetMouseY()< base + bMax){

            pX =ofGetMouseX();
            pY =ofGetMouseY();

            valueX = (ofMap(pX,xPos,xPos+xMax, .01, .2));
            valueY = (ofMap(pY,base,base+bMax, .01, 5));
            
         
            
            cout << "printing"<<endl;
            cout << valueX  << "xpos" <<endl;
   
           
            }
    }
    
   
    ofPushMatrix();
   // ofRectMode(OF_RECTMODE_CORNER);
    ofFill();
 
    ofTranslate(xPos-(xMax/2), base-(xMax/2));
  
    ofSetColor(68, 199, 184);
 
    ofDrawRectRounded(0+(xMax/2), 0+(bMax/2), xMax , bMax ,9 );
    
    ofPopMatrix();
     ofPushMatrix();
    ofSetColor(206, 247, 214);
    ofDrawRectangle(xPos+(xMax/2), base,1,bMax);
    ofDrawRectangle(xPos, base+(xMax/2),xMax,1);
  
    
   
    
    cout << posX <<endl;
    cout << posY <<endl;
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofNoFill();
    
    //ofRectMode(OF_RECTMODE_CORNER);
    ofTranslate(xPos-(xMax/2), base-(xMax/2));
       for (int i =0; i<5; i++){
//           ofDrawEllipse(xPos+(xMax/2), base+(xMax/2), xMax-(i*(valueX*.02)),);
           //ofDrawRectRounded(0+(xMax/2), 0+(bMax/2), xMax-(i*(valueX*.02)) , bMax-(i*(valueY*.02)),9);
       }
    ofPopMatrix();
    ofFill();
    
    ofDrawEllipse(pX,pY, 10, 10);
    
    


    
  
    
    ofDrawBitmapString(valueX, xPos-10, base-5);
    ofDrawBitmapString(valueY, xPos+ 116, base+130);
      
}

