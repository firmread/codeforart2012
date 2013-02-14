#include "testApp.h"
string myString;

//--------------------------------------------------------------
void testApp::setup(){
    myString = "Hello, World!";
    
    cout << myString << endl;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
/*
        // ofGetFrameRate();
        // ofToString
        float theFPSfloat = ofGetFrameRate();
        string theFPSString = ofToString(theFPSfloat);
        // variable type need to be convert

        
        string fps;
        fps = theFPSString+"frames per second";

        ofDrawBitmapString(fps, 10, 20);
*/
    
    //or just consolidate to 1 single line: 
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10,20);
    
    
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