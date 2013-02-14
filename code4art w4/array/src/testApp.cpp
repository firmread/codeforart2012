#include "testApp.h"

//we can't use variable to declare variable
//depound ,,, preprocessor directive

#define NUM_CIRCLE 100

float circleX [NUM_CIRCLE];
float circleY [NUM_CIRCLE];
float circleRadius [NUM_CIRCLE];

int red [NUM_CIRCLE];
int blu [NUM_CIRCLE];
int gre [NUM_CIRCLE];

float vx [NUM_CIRCLE];
float vy [NUM_CIRCLE];

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(40);
    ofSetCircleResolution(100);
    ofBackground(230, 230, 230);
    
    for(int i=0; i<NUM_CIRCLE; i++)
    {
        red[i] = ofRandom(255);
        blu[i] = ofRandom(255);
        gre[i] = ofRandom(255);
        
        circleX[i] = ofGetWidth()/(NUM_CIRCLE-1) * i;
        circleY[i] = ofRandom(ofGetHeight());
        circleRadius[i] = ofRandom(20,100);
        
        vx[i] = ofRandom(-3,3);
        vy[i] = ofRandom(-3,3);        
    }

    

}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<NUM_CIRCLE; i++)
    {
        circleX[i] += vx[i];
        circleY[i] += vy[i];
        
        if(circleX[i] > ofGetWidth())
        {
            vx[i] *= -1;
        }
        if(circleX[i] < 0)
        {
            vx[i] *= -1;
        }
        if(circleY[i] > ofGetHeight())
        {
            vy[i] *= -1;
        }
        if(circleY[i] < 0)
        {
            vy[i] *= -1;
        }        
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<NUM_CIRCLE; i++)
    {
        ofSetColor (red[i], blu[i], gre[i]);
        ofCircle(circleX[i],circleY[i],circleRadius[i]);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if (button == 0){
        
        for(int i=0; i<NUM_CIRCLE; i++)
        {
            circleRadius[i] += ofRandom(-5, 5);
        }
        
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}