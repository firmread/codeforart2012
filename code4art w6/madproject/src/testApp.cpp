#include "testApp.h"
bool relief;
bool norm;
bool mad;
bool reset;

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetBackgroundAuto(false);
    
    relief = false;
    norm = true;
    mad = false;
    reset = false;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofFill();
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255,1);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    if (norm){
        ofNoFill();
        ofSetColor(0, 0, 0, 40);
        ofSetLineWidth(1);
        ofTriangle(mouseX, mouseY, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
    
    if (relief){
        ofFill();
        ofSetColor(255, 255, 255, 100);
        ofTriangle(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
    
    if (mad){
        ofSetLineWidth(ofRandom(4));
        ofSetColor(255, 0, 0, 150);
        ofTriangle(mouseX, mouseY, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
    
    if (reset){
        ofFill();
        ofSetColor(255, 255, 255);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
    }
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 97){
        reset = true;
    }
    
    if (key == 32){
        relief = true;
        norm = false;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == 97){
        reset = false;
    }
    
    if (key == 32){
        relief = false;
        norm = true;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if (button == 0){
        mad = true;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if (button == 0){
        mad = false;
    }
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