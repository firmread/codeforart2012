#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    //do while loop
    int i = 0;
    int x = 20;
    
    do{
        ofCircle(x,300,10);
        x += 20;
        i++;
    }while(i < 50);
    
    
    //for loop
    int x2 = 20;
    for (int i = 0; i<50; i++) {
        ofCircle(x2, 350, 10);
        x2 += 20;
    }
    
    //for loop without x
    for (int i = 0; i<50; i++) {
        ofCircle(i*20, 400, 10);
    }
    
    //tricky!
    
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