#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    for (int i=0; i<10; i++) {
        Boid newBoid;
        newBoid.setup(ofRandom(3,7), 10);
        
        boids.push_back(newBoid);
    }

}

//--------------------------------------------------------------
void testApp::update(){
    ofPoint mouse;
    mouse.x = mouseX;
    mouse.y = mouseY;
    
    ofPoint center;
    center.x = ofGetWidth()/2;
    center.y = ofGetHeight()/2;
    
    for (int i = 0; i<boids.size(); i++) {
        boids[i].update();
        boids[i].addNoise();
        boids[i].accelerateTowards(mouse);
        boids[i].acelerateAwayFrom(center);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    
    for (int i = 0; i<boids.size(); i++) {
        boids[i].draw();
    }
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
    
    Boid newBoid;
    newBoid.setup(ofRandom(3,7), 10);
    
    boids.push_back(newBoid);
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