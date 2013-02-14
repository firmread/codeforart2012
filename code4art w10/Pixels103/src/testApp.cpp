#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(24);
    
    source.loadMovie("cats.mov");
    source.play();
    
    int numPixels = source.getWidth() * source.getHeight() * 3;
    pixels = new unsigned char[numPixels];
}

//--------------------------------------------------------------
void testApp::update(){
    
   
    source.idleMovie();
    pixels = source.getPixels();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();
    ofTranslate((ofGetWidth()/2.0)-(source.getWidth()), (ofGetHeight()/2.0));
    ofRotateX(ofGetFrameNum());
    ofTranslate(0, -source.getHeight());
    
    // Loop through the pixels (every other pixel)
    for(int y=0; y<source.getHeight(); y+=2)
    {
        for(int x=0; x<source.getWidth(); x+=2) 
        {
            // Calculate where in the pixels array the RGB values for (x,y) is
            int i = (y*source.getWidth()+x) * 3;
            int r = pixels[ i+0 ];
            int g = pixels[ i+1 ];
            int b = pixels[ i+2 ];
            int brightness = (r+g+b)/3.0;
            
            ofSetColor(r, g, b);
            ofPushMatrix();
            ofTranslate(x*2, y*2, brightness);
            //ofRect(0, 0, 4, 4);
            ofCircle(0, 0, 6);
            ofPopMatrix();
        }
    }
    
    ofPopMatrix();
    
    
    ofSetColor(0);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, ofGetHeight()-20);
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