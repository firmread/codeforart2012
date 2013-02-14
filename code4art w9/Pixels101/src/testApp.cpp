#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    
    pixelSize=3;

    fraggles.loadImage("fraggles.jpg");
    
#ifdef USE_PIX_OBJECT
    pix = fraggles.getPixelsRef();
#else
    pix = fraggles.getPixels();
#endif
    
}

//--------------------------------------------------------------
void testApp::update(){
    depth = cos(ofGetFrameNum() / 10.0) + 1;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofPushMatrix();
    float x = (ofGetWidth()/2.0)-(fraggles.getWidth()/2.0);
    float y = (ofGetHeight()/2.0);
    
    ofTranslate(x, y);
    ofRotateX(ofGetFrameNum());
    ofTranslate(0, -fraggles.getHeight()/2.0);
    
    for(int y=0; y<fraggles.getHeight(); y+=pixelSize) {
        for(int x=0; x<fraggles.getWidth(); x+=pixelSize) {

#ifdef USE_PIX_OBJECT
            ofColor c = pix.getColor(x, y);
            ofSetColor(c);
            int brightness = c.getBrightness();
#else
            int i = (y * fraggles.getWidth() + x) * 3;
            int r = pix[i+0];
            int g = pix[i+1];
            int b = pix[i+2];
            int brightness = (r+g+b)/3;
            ofSetColor(r, g, b);
#endif
            
            ofPushMatrix();
            float z = ( brightness/2.0 ) * depth;
            ofTranslate(x, y, z);
            ofRect(0, 0, pixelSize, pixelSize);
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