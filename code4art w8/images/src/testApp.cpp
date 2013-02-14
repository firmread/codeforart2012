#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myImage.loadImage("batmancar.png");
    float imageWidth = myImage.getWidth();
    float imageHeight = myImage.getHeight();
    
    myImage.resize(imageWidth/2, imageHeight/2);
    myImage.saveImage("batmancar_half.jpg");
    myImage.mirror(false, true);
    
    //pixelate technique > resize it down and draw it at
    //bigger size
    //interpolation process ?

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground( 0,0,0);
    
    //enable just something that need it 
    //for performance reason
    
    ofEnableAlphaBlending();
    //myImage.draw(20,20);
    //myImage.draw(20,20,400,400);
    

    //myImage.draw(20,20,imageWidth/2, imageHeight/2);
    myImage.draw(mouseX,mouseY);
    
    ofDisableAlphaBlending();

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