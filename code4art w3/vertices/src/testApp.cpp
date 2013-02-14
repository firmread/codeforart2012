#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(0,0,0);
    ofBeginShape();

    int outerRadius = 200;
    int innerRadius = 150;
    bool useInner = false;
    
    for(int i=0; i<360; i+=30)
    {
        //int r = (useInner) ? innerRadius : outerRadius;
        int r;
        if (useInner) {
            r = innerRadius;
        }
        else {
            r = outerRadius;
        }
        
        int x = 300 + cos(ofDegToRad(i)) * r;
        int y = 300 + sin(ofDegToRad(i)) * r;
        
        useInner = !useInner;
        ofVertex(x, y);
    }
    
    ofEndShape();
    
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