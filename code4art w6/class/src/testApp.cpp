#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    a.x = 20;
    a.y = 50;
    a.radius = 100;
    a.r = 255;
    a.g = 255;
    a.b = 0;
    
    b.x = 300;
    b.y = 100;
    b.radius = 100;
    b.r = 255;
    b.g = 0;
    b.b = 255;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    a.drawMe();
    b.drawMe();
    
//    ofSetColor(a.r, a.g, a.b);
//    ofCircle(a.x, a.y, a.radius);
//    
//    ofSetColor(b.r, b.g, b.b);
//    ofCircle(b.x, b.y, b.radius);
    
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