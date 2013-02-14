#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    
    for(int i=0; i<30; i++) {
        Boid newBoid;
        newBoid.setup(ofRandom(3, 7), 10);
        
        boids.push_back( newBoid );
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    mouse.x = mouseX;
    mouse.y = mouseY;
    
    for(int i=0; i<boids.size(); i++) {
        
        boids[i].addNoise();
        boids[i].accelerateTowards(mouse);
        
        boids[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    
    for(int i=0; i<boids.size(); i++) {
        boids[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    Boid newBoid;
    newBoid.setup(ofRandom(3, 7), 10);
    
    boids.push_back( newBoid );
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
    
    boids.erase( boids.begin() );
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