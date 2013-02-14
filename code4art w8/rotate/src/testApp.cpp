#include "testApp.h"

ofPoint planet; 
float dist;
float angle;
//--------------------------------------------------------------
void testApp::setup(){
    ofSetCircleResolution(100);
    ofSetFrameRate(24);
    dist = 250;
    angle = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    angle +=2;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofSetColor(205,20,50);
        ofCircle(0, 0, 100);
    
    
        ofRotateZ(angle);
        ofRotateX(angle);
        //ofRotateY(angle);
        ofTranslate(dist, 0);
        ofSetColor(20,20,250);
        ofCircle(0, 0, 20);
            
    ofPopMatrix();
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