#include "testApp.h"

int x;
int y;
int offset;

float noise_x;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    x = ofGetWidth() / 2.0;
    y = ofGetHeight() / 2.0;
    offset = 0;
    
    noise_x = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // using frame number as counter
    //offset = ofNoise(ofGetFrameNum() / 100.0)* 200;
    
    //use noise_x as a counter
    noise_x += 0.06;
    offset = ofNoise(noise_x)* 200;
    
    //another kind of noise 'signed'
    //offset = ofSignedNoise(noise_x, 0)* 200;
    
    //if you use noise from the next pixel 
    //they still random but will be in the same band
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(0, 0, 0 );
    ofSetColor(255,255,255);
    ofCircle (x, y+ offset, 20);
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