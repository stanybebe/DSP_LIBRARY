#pragma once

#include "ofMain.h"
#include "oscillator.hpp"
#include "biquadFilter.hpp"
#include "knob.h"
#include "panner.hpp"
#include "lerp.hpp"
#include "adsr.hpp"
#include "envUI.hpp"
#include "pad.h"
#include "ofxMidi.h"
#include "delay.hpp"
#include "xy.h"






class ofApp : public ofBaseApp, public ofxMidiListener  {

	public:
		void setup();
		void update();
		void draw();
        void exit();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void audioOut(ofSoundBuffer & buffer);
        void newMidiMessage(ofxMidiMessage& eventArgs);
       
    int sampleRate;

    ofSoundStream soundStream;

    vector <float> lAudio;
    vector <float> rAudio;
    static const int numOsc = 12;
    oscillator osc[numOsc];
    oscillator oscB[numOsc];
    oscillator oscC[numOsc];
    oscillator oscD[numOsc];
   

    vector <int> queueDaddy;
    oscillator autoPan;
    oscillator vib;
    oscillator vib2;
       
    oscillator op1;
    Biquad* filter;
    Biquad* smoother;
    Biquad* smootherB;
    Biquad* smootherC;
    Biquad* smootherD;
    Biquad* smootherF;
    Biquad* smootherG;
    Biquad* smootherH;
    Biquad* smootherI;
    Biquad* smootherJ;
    Biquad* smootherK;
    bool noteOn =false;
    
    knob knobA, knobB, knobC, knobD, knobE, knobF, knobG;
    pad padA;
    Panner pans;
    
    lerpVal smooth;
    stereoFrame currentPanFrame;
    
    float t, ran;
    float melody[8] = {261.6, 294.33, 313.96, 348.84, 392.52, 418.61, 470.93, 523.26};
    float tempo;
    bool timer;
    int len;
    float Note = 1320; // Middle C
    int stepi = 0;
    
    adsr* ADSR;
    envui env1;
    adsr* ADSR_2;
    envui env2;
    
    xy XY;
    int yep;
    
    
    int cNote;
    ofxMidiIn midiIn;
    std::vector<ofxMidiMessage> midiMessages;
    std::size_t maxMessages = 10; //< max number of messages to keep track of
    
    delayIn* d_in1;
    delayOut* d_out1;
    delayIn* d_in2;
    delayOut* d_out2;
    int v , vo;
  
    
    double mtofarray[129]={0, 8.661957, 9.177024, 9.722718, 10.3, 10.913383, 11.562325, 12.25, 12.978271, 13.75, 14.567617, 15.433853, 16.351599, 17.323914, 18.354048, 19.445436, 20.601723, 21.826765, 23.124651, 24.5, 25.956543, 27.5, 29.135235, 30.867706, 32.703197, 34.647827, 36.708096, 38.890873, 41.203445, 43.65353, 46.249302, 49., 51.913086, 55., 58.27047, 61.735413, 65.406395, 69.295654, 73.416191, 77.781746, 82.406891, 87.30706, 92.498604, 97.998856, 103.826172, 110., 116.540939, 123.470825, 130.81279, 138.591309, 146.832382, 155.563492, 164.813782, 174.61412, 184.997208, 195.997711, 207.652344, 220., 233.081879, 246.94165, 261.62558, 277.182617,293.664764, 311.126984, 329.627563, 349.228241, 369.994415, 391.995422, 415.304688, 440., 466.163757, 493.883301, 523.25116, 554.365234, 587.329529, 622.253967, 659.255127, 698.456482, 739.988831, 783.990845, 830.609375, 880., 932.327515, 987.766602, 1046.502319, 1108.730469, 1174.659058, 1244.507935, 1318.510254, 1396.912964, 1479.977661, 1567.981689, 1661.21875, 1760., 1864.655029, 1975.533203, 2093.004639, 2217.460938, 2349.318115, 2489.015869, 2637.020508, 2793.825928, 2959.955322, 3135.963379, 3322.4375, 3520., 3729.31, 3951.066406, 4186.009277, 4434.921875, 4698.63623, 4978.031738, 5274.041016, 5587.651855, 5919.910645, 6271.926758, 6644.875, 7040., 7458.620117, 7902.132812, 8372.018555, 8869.84375, 9397.272461, 9956.063477, 10548.082031, 11175.303711, 11839.821289, 12543.853516, 13289.75};
  
    int voiceCounter(bool is_on){
  
       int counter=0;
        bool isOn = false;
        isOn = is_on;
        
           if (isOn ==true){
               counter++;
           }else {counter = 0;}
           
           return counter;
       }
   
    
    int largest(int arr[], int n)
    {
        int i;
         
        // Initialize maximum element
        int max = arr[0];
     
        // Traverse array elements
        // from second and compare
        // every element with current max
        for (i = 1; i < n; i++)
            if (arr[i] > max)
                max = arr[i];
     
        return max;
    }
};

