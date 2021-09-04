//
//  envUI.cpp
//  DSP_library
//
//  Created by Mac on 7/5/21.
//

#include "envUI.hpp"
#include <stdio.h>




void envui::setup(int xposIn, int baseIn){
    xpos = xposIn;
    base = baseIn;
    
   
    radiusA=20;
    radiusB=20;
    radiusC=20;
    radiusD=20;
    c1 =10;
    p2x = xpos;
    p3x = xpos+55;
    p4x = xpos+115;
    p5x = xpos+175;
    aF = false;
    sF = false;
    rF = false;
    dF = false;
  
    
}

void envui::draw(float aINmin, float aInmax, float dInmin, float dInmax, float rInmin, float rInmax){
  
    xMax = xpos + 200;
    bMax = base + 100;

    
    distA = ofDist(p2x, base, ofGetMouseX(), ofGetMouseY());
    distB = ofDist(p3x, base+30, ofGetMouseX(), ofGetMouseY());
    distC = ofDist(p4x, base+30, ofGetMouseX(), ofGetMouseY());
    distD = ofDist(p5x, base+110, ofGetMouseX(), ofGetMouseY());
   
    if(ofGetMousePressed()==true){
        
         if(distA <= radiusA){
             aF = true;
              cout << "clik" <<endl;
              p2x = ofMap(ofGetMouseY(),base,base+110,xpos,xpos+50);
             if (p2x < xpos){
                 p2x = xpos;
             }
             if (p2x > xpos+50){
                 p2x = xpos+50;
             }
         }
         
        
    }else{aF =false;}
    
    if(ofGetMousePressed()==true){
      
        if(distB <= radiusB){
            dF = true;
             cout << "clik" <<endl;
             p3x = ofMap(ofGetMouseY(),base,base+110,xpos+55,xpos+95);
            if (p3x < xpos+55){
                p3x = xpos+55;
            }
            if (p3x > xpos+95){
                p3x = xpos+95;
            }
      
    }
       
    }else{ dF =false;}
    
    if(ofGetMousePressed()==true){
      
        if(distC <= radiusC){
            sF = true;
             cout << "clik" <<endl;
             p4x = ofMap(ofGetMouseY(),base,base+110,xpos+115,xpos+170);
            if (p4x < xpos+115){
                p4x = xpos+115;
            }
            if (p4x > xpos+170){
                p4x = xpos+170;
            }
      
    }
       
    }else{ sF =false;}
    
    if(ofGetMousePressed()==true){
      
        if(distD <= radiusD){
            rF = true;
             cout << "clik" <<endl;
             p5x = ofMap(ofGetMouseY(),base,base+110,xpos+175,xpos+250);
            if (p5x < xpos+175){
                p5x = xpos+175;
            }
            if (p5x > xpos+250){
                p5x = xpos+250;
            }
      
    }
       
    }else{ rF =false;}
    
    if (aF == true){
        radiusA = ofGetHeight();
    }else{ radiusA = 20;}
    
    if (dF == true){
         radiusB = ofGetHeight();
    }else{radiusB = 20;}
    
    if (sF == true){
         radiusC = ofGetHeight();
    }else{radiusC = 20;}
    
    if (rF == true){
            radiusD = ofGetHeight();
       }else{radiusD = 20;}
    
    attackV = ofMap(p2x, xpos,xpos+50, aINmin, aInmax);
    decayV = ofMap(p3x, xpos+55,xpos+95, dInmin, dInmax);
    susV = ofMap(p4x,xpos+115,xpos+170, .9, .1);
    relV = ofMap(p5x, xpos+175,xpos+250, rInmin, rInmax);
    
//    cout << p2x <<endl;
//    cout << attackV<< "_atime" <<endl;
//    cout << radiusB<< "_radiusB" <<endl;
//    cout << radiusC<< "_radiusC" <<endl;
    
    ofSetColor(206, 247, 214);
    
    ofDrawRectRounded(xpos, base-10, 250, 110,9);
    
    ofSetColor(68, 199, 184);
    ofDrawEllipse(xpos,bMax, 10, 10);
    ofDrawLine(xpos, bMax, p2x, base);
    ofDrawEllipse(p2x,base, 20, 20);
    ofDrawLine(p2x, base, p3x, base+30);
    ofDrawEllipse(p3x,base+30, 25, 25);
    ofDrawLine(p3x, base+30, p4x, base+30);
    ofDrawEllipse(p4x,base+30, 10, 10);
    ofDrawLine(p4x, base+30, p5x, bMax);
    ofDrawEllipse(p5x,bMax, 20, 20);
}
