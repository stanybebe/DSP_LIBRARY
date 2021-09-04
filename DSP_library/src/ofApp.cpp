#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    midiIn.listInPorts();
    midiIn.openPort(4);
    //midiIn.openPort("IAC Pure Data In");    // by name
    //midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
    
    // don't ignore sysex, timing, & active sense messages,
    // these are ignored by default
    midiIn.ignoreTypes(false, false, false);
    
    // add ofApp as a listener
    midiIn.addListener(this);
    
    // print received messages to the console
    midiIn.setVerbose(true);
    sampleRate = 48000;
    //channels out / in/ sampleRate/ block size/ buffer#
    int bufferSize= 512;
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = 512;
    soundStream.setup(settings);
    soundStream.printDeviceList();
    auto devices = soundStream.getDeviceList();
    settings.setOutDevice(devices[4]);
    lAudio.assign(bufferSize, 0.0);
    rAudio.assign(bufferSize, 0.0);
    for (int i =0; i < numOsc; i++){
        osc[i].setup(440*(i+.5), 0, sampleRate, 1/ (float)(i+1));
        oscB[i].setup(440*(i+.5), 0, sampleRate, 1/ (float)(i+1));
        oscC[i].setup(440*(i+.5), 0, sampleRate, 1/ (float)(i+1));
        oscD[i].setup(440*(i+.5), 0, sampleRate, 1/ (float)(i+1));
      
    }
   
    filter = new Biquad(bq_type_lowpass, 0/(float)sampleRate,2,-3);
    smoother = new Biquad(bq_type_lowpass, 5000/(float)sampleRate,1,-3);
    smootherB = new Biquad(bq_type_lowpass, 1000/(float)sampleRate,1,-3);
    smootherC = new Biquad(bq_type_lowpass, 10000/(float)sampleRate,2,-3);
    smootherD = new Biquad(bq_type_lowpass, 5000/(float)sampleRate,1,-3);
    smootherF = new Biquad(bq_type_lowpass, 1000/(float)sampleRate,1,-3);
    smootherG = new Biquad(bq_type_lowpass, 1/(float)sampleRate,2,-3);
    smootherH = new Biquad(bq_type_lowpass, 5000/(float)sampleRate,1,-3);
    smootherI = new Biquad(bq_type_lowpass, 5000/(float)sampleRate,1,-3);
    smootherJ = new Biquad(bq_type_lowpass, 500/(float)sampleRate,1,-3);
    smootherK = new Biquad(bq_type_lowpass, 500/(float)sampleRate,1,-3);
    knobA.setup();
    knobB.setup();
    knobC.setup();
    knobD.setup();
    knobE.setup();
    knobF.setup();

    smooth.targetVal = 0;
    smooth.lerp_object = new lerp(20 , sampleRate);
    autoPan.setup(1, 0, sampleRate, 1);
    vib.setup(1, 0, sampleRate, 1);
    vib2.setup(1, 0, sampleRate, 1);
    op1.setup(0,0,sampleRate, 1);
    ADSR = new adsr(500,10,1,300,sampleRate);
    ADSR_2 = new adsr(500,10,1,300,sampleRate);
    env1.setup(300,550);
    env2.setup(300,680);
   // padA.setup(440);
    
    d_in1 = new delayIn(10000, sampleRate);
    d_out1 = new delayOut(d_in1, 800);
    
    knobC.value = .01;
    knobA.value = 100;
    XY.setup(100, 600);
}

//--------------------------------------------------------------
void ofApp::update(){
    XY.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(34, 69, 78);
   for( int i = 0; i < midiMessages.size(); i++) {
   
        ofxMidiMessage &message = midiMessages[i];
       if (message.status == MIDI_NOTE_ON){
           noteOn = true;
          
           cout << "midiComingOut"<<endl;
           
       }
       
       if (noteOn ==true){
         ADSR->setGate(1);
         ADSR_2->setGate(1);
           cNote = message.pitch;
//          pitches.push_back(message.pitch);
//
//           voices[0]=pitches[0];
//           voices[1]=pitches[1];
//           voices[2]=pitches[2];
//           voices[3]=pitches[3];
           
           v = v + 1;
           if (v > 3) v = 0;

           switch (v) {
             case 0:
               voices[0] = message.pitch;
               break;
             case 1:
               voices[1] = message.pitch;
               break;
             case 2:
               voices[2] = message.pitch;
             case 3:
               voices[3] = message.pitch;
                                  
               break;
           }
//
       }
       
       if (message.status == MIDI_NOTE_OFF){
           ADSR->setGate(0);
           ADSR_2->setGate(0);
           noteOn = false;
             vo = vo + 1;
                      if (vo > 3) vo = 0;

                      switch (vo) {
                        case 0:
                          voices[0] = 0;
                          break;
                        case 1:
                          voices[1] = 0;
                          break;
                        case 2:
                          voices[2] = 0;
                        case 3:
                          voices[3] = 0;
                                             
                          break;
                      }
           //
       }


     
   }


    
    for (unsigned int i=0; i<voices.size();i++){
    cout << voices[0]<<"note"<<endl;
    cout << voices[1]<<"note"<<endl;
    cout << voices[2]<<"note"<<endl;
    cout << voices[3]<<"note"<<endl;
    }
    ofPushMatrix();
    env1.draw(1,1000,20,500,10,500);
    env2.draw(1,1000,20,500,10,500);
    ofPopMatrix();
    // draw the left channel:
  
    
    ofPushStyle();
    ofNoFill();
        ofPushMatrix();
        ofTranslate(50, 150, 0);
            

       

        ofSetColor(206, 247, 214);
        ofSetLineWidth(3);
                    
            
            for (unsigned int i = 0; i < lAudio.size(); i++){
                float x =  ofMap(i, 0, lAudio.size(), 0, 500, true);
                ofVertex(x, 100 -lAudio[i]*100.0f);
            }
           
            
        ofPopMatrix();
        ofPushMatrix();
           ofTranslate(50, 225, 0);
               
        
           
       

           ofSetColor(206, 247, 214);
           ofSetLineWidth(3);
     
               ofBeginShape();
               for (unsigned int i = 0; i < rAudio.size(); i++){
                   float x =  ofMap(i, 0, rAudio.size(), 0, 500, true);
                   ofVertex(x, 100 -rAudio[i]*100.0f);
               }
               ofEndShape(false);
               
           ofPopMatrix();
    ofPopStyle();


     ofPushMatrix();
    knobA.draw(150, 150, 1000, 10);
    knobB.draw(450, 150, 7000, 1);
    knobC.draw(150, 450, .2, .01);
    knobD.draw(450, 450, 12, 0);
    knobE.draw(300, 150, 10, 0);
    knobF.draw(300, 450, 5, .01);
    ofPopMatrix();
    
    t++;
    tempo= XY.valueX;
   

    if ( t > tempo) {
     ran = ofRandom(0, XY.valueY);
      t = 0;
    }
//
//    if (t > tempo - len) {
//      Note = 0;
//    }

//    if (timer == true) {
//         yep = round(ofRandom(0, 8));
//        stepi = stepi + 1;
//        timer = false;
//      if (stepi > 7) {
//        stepi = 0;
//      }
//    }
//
  
    
  
    op1.setFreq(smootherF->process((knobF.value)));
    
    op1.setAmp(.4);
    
    autoPan.setFreq(smootherB->process(knobE.value));
    
    vib.setFreq(smootherJ->process(XY.valueX+ran));
    vib.setFreq(smootherK->process(XY.valueY+ran));
//    for (int j = 0; j<voices.size();j++){
    for (int k = 0; k < numOsc; k++){
         
              
              osc[k].setFreq(smootherC->process(mtofarray[cNote])*(k+round(knobD.value)));
              osc[k].setAmp(smootherD->process(knobC.value));
//              oscB[k].setFreq(smootherG->process(mtofarray[voices[1]])*(k+round(knobD.value)));
//              oscB[k].setAmp(smootherD->process(knobC.value));
//              oscC[k].setFreq(smootherH->process(mtofarray[voices[2]])*(k+round(knobD.value)));
//              oscC[k].setAmp(smootherD->process(knobC.value));
//              oscD[k].setFreq(smootherI->process(mtofarray[voices[3]])*(k+round(knobD.value)));
//              oscD[k].setAmp(smootherD->process(knobC.value));
//
         }
    
    
   // padA.draw(100, 540);
    
//    if (padA.value == true){
//
//        ADSR->setGate(1);
//
//    }else{ADSR->setGate(0);}
//
  
    
    
//   cout << ADSR->aTime<<"aTIME"<<endl;
//    cout << ADSR->dTime<<"dTIME"<<endl;
//    cout << ADSR->sTime<<"sTIME"<<endl;
//    cout << ADSR->rTime<<"rTIME"<<endl;
    XY.draw(100, 600);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

void ofApp::newMidiMessage(ofxMidiMessage& msg) {

    // add the latest message to the message queue
    midiMessages.push_back(msg);

    // remove any old messages if we have too many
    while(midiMessages.size() > maxMessages) {
        midiMessages.erase(midiMessages.begin());
    }
}

void ofApp::audioOut(ofSoundBuffer & buffer){
    
    for (int i = 0; i<buffer.getNumFrames();i++){
      
        d_out1->setTime(smootherG->process(knobA.value));
        float currentS = 0;
        for(int j = 0; j < numOsc; j++){
            currentS += (osc[j].getSine()*op1.getSine())*vib.getSine();
        
        }
        
       

        ADSR->aTime = env1.attackV;
        ADSR->dTime = env1.decayV;
        ADSR->sTime = env1.susV;
        ADSR->rTime = env1.relV;
        
        ADSR_2->aTime = env2.attackV;
        ADSR_2->dTime = env2.decayV;
        ADSR_2->sTime = env2.susV;
        ADSR_2->rTime = env2.relV;
    
        ADSR -> process();
        ADSR_2 -> process();
        
        
        currentS *= ADSR->getVal();
        float fRamp = ofMap(ADSR_2->getVal(), 0, 1, 10, 2000);
        filter->setFc(smoother->process(fRamp/float(sampleRate)+(knobB.value/float(sampleRate))));
        currentS = filter->process(currentS);
        
        float dOutSample = d_out1->getSample();
     
        d_in1->feed(currentS+(dOutSample*.7));
        
       
        currentPanFrame = pans.pan(currentS + dOutSample, autoPan.getSine()*vib2.getSine());
        
        lAudio[i] =buffer[i*buffer.getNumChannels()+0] = currentPanFrame.leftSamp ;
        rAudio[i] = buffer[i*buffer.getNumChannels()+1] = currentPanFrame.rightSamp ;
    }
    
}
//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit(){
    ofSoundStream().close();
    midiIn.closePort();
    midiIn.removeListener(this);
}
