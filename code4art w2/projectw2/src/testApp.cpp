#include "testApp.h"
int circleXPosition,circleYPosition;
int circleSize;


//--------------------------------------------------------------
void testApp::setup(){
    ofSetCircleResolution(80);
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    
    circleXPosition = 300;
    circleYPosition = 200;
    circleSize = 10;
}

//--------------------------------------------------------------
void testApp::update(){
    circleXPosition += 4 ;
    
    //int windowWidth = ofGetWidth();
    //if (circleXPosition > windowWidth+circleSize) {
    
    
    if (circleXPosition > ofGetWidth()+circleSize) {
        circleXPosition = -circleSize;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(140, 50, 0);
    ofCircle(circleXPosition, circleYPosition, circleSize);
    
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);

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