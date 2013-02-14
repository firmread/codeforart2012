#include "testApp.h"


//custom function!
//have to be declare before we use it so it have to be waaaay up here

//this actually can be inside the code in draw loop
//but this is very organized way to saperate subtasks for the sake of readability

void equilateralTriangleInACircle(float x, float y, float radius)
{
    // Calculate the point directly above (x,y) at the specified radius
    int angle = -90;
    int x1 = x + cos(ofDegToRad(angle)) * radius;
    int y1 = y + sin(ofDegToRad(angle)) * radius;
    
    // Calculate the point 120 degrees from the first point at the specified radius
    angle += 120;
    int x2 = x + cos(ofDegToRad(angle)) * radius;
    int y2 = y + sin(ofDegToRad(angle)) * radius;
    
    // Add 120 and do it again
    angle += 120;
    int x3 = x + cos(ofDegToRad(angle)) * radius;
    int y3 = y + sin(ofDegToRad(angle)) * radius;
    
    // Draw the triangle
    ofTriangle(x1, y1, x2, y2, x3, y3);
}


//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    
    for(int i=0; i<NUM_SHAPES; i++)
    {
//        xpos[i] = ofRandom(0, ofGetWidth());
//        ypos[i] = ofRandom(0, ofGetHeight());
        pos[i].x =  ofRandom(0, ofGetWidth());
        pos[i].y = ofRandom(0, ofGetHeight());
        size[i] = ofRandom(5, 30);
        
        color[i].r = ofRandom(0, 255);
        color[i].g = ofRandom(0, 255);
        color[i].b = ofRandom(0, 255);
        color[i].a = ofRandom(10,255);
        
        v[i].x = ofRandom(-5, 5);
        v[i].y = ofRandom(-5, 5);
        
        //exactly zero or exactly one or two only out of random
        type[i] = (int)ofRandom(3);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    for(int i=0; i<NUM_SHAPES; i++)
    {
        //pos[i].x += v[i].x;   // Add the x velocity to the x position
        //pos[i].y += v[i].y;   // Add the y velocity to the y position
        pos[i] += v[i];
        //we can combine ofPoint together at the same time it will plus x and y seperately for us
        
        
        // Bounce on right side of screen
        if(pos[i].x > ofGetWidth()-size[i])
        {
            pos[i].x = ofGetWidth()-size[i];
            v[i].x *= -1;
        }
        
        // Bounce on left side of screen
        if(pos[i].x < size[i])
        {
            pos[i].x = size[i];
            v[i].x *= -1;
        }
        
        // Bounce on bottom of screen
        if(pos[i].y > ofGetHeight()-size[i])
        {
            pos[i].y = ofGetHeight()-size[i];
            v[i].y *= -1;
        }
        
        // Bounce on top of screen
        if(pos[i].y < size[i])
        {
            pos[i].y = size[i];
            v[i].y *= -1;
        }
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, 5);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    for(int i=0; i<NUM_SHAPES; i++)
    {
        ofSetColor(color[i]);
        if(type[i]==0)
        {
            //ofCircle(pos[i].x, pos[i].y, size[i]);
            ofCircle(pos[i], size[i]);
            
            //ofCircle can also take ofPoint as initial variable
            //ofCircle(<#const ofPoint &p#>, <#float radius#>)
        }
        else if(type[i]==1)
        {
            ofRect(pos[i].x, pos[i].y, size[i], size[i]);
        }
        else if(type[i]==2)
        {
            equilateralTriangleInACircle(pos[i].x, pos[i].y, size[i]);
        }
        else
        {
            cout << "unknown type" << type[i] << endl;
        }
    }
    
    
    // Show the frames per second on the top left
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+" fps", 10, 20);
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


