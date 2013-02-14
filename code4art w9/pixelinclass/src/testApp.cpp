#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    thexx.loadImage("thexx.png");
    pixels = thexx.getPixels();
    //pixels is actually = pixels [thexx.width * thexx.height * 3];
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();
    ofRotateX(ofMap(mouseY, 0, ofGetHeight(), -360, 360));
    ofTranslate(200, 100);
    for (int y=0; y<thexx.getHeight(); y++) {
        //first row
        for(int x=0; x<thexx.getWidth(); x++){
            //pixel by pixel on each row
            // this is going to loop through every (x,y) coordinate

            int i = ((y*thexx.getWidth()) + x) * 3;
            int r = pixels [i+0];
            int g = pixels [i+1];
            int b = pixels [i+2];
            int brightness = (r+g+b)/3.0;
            
            ofPushMatrix();
            ofTranslate(0, 0, -brightness);
            ofSetColor(r, g, b);
            ofRect(x*3, y*3, 2, 2);
//            ofBox(x*3, y*3, -brightness, 2);
            
            ofPopMatrix();
        }
    }
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