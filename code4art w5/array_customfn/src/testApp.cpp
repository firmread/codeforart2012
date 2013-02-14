#include "testApp.h"

#define NUM_SHAPES 500

float xpos[NUM_SHAPES];
float ypos[NUM_SHAPES];
float size[NUM_SHAPES];
// cast the variable since you started
int type[NUM_SHAPES];   // 0 = circle, 1 = square

float r[NUM_SHAPES];   // Red
float g[NUM_SHAPES];   // Green
float b[NUM_SHAPES];   // Blue

float vx[NUM_SHAPES];  // X velocity
float vy[NUM_SHAPES];  // Y velocity


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
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    
    for(int i=0; i<NUM_SHAPES; i++)
    {
        xpos[i] = ofRandom(0, ofGetWidth());
        ypos[i] = ofRandom(0, ofGetHeight());
        size[i] = ofRandom(5, 30);
        
        r[i] = ofRandom(0, 255);
        g[i] = ofRandom(0, 255);
        b[i] = ofRandom(0, 255);
        
        vx[i] = ofRandom(-5, 5);
        vy[i] = ofRandom(-5, 5);
        
        //exactly zero or exactly one or two only out of random
        type[i] = (int)ofRandom(3);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    for(int i=0; i<NUM_SHAPES; i++)
    {
        xpos[i] += vx[i];   // Add the x velocity to the x position
        ypos[i] += vy[i];   // Add the y velocity to the y position
        
        // Bounce on right side of screen
        if(xpos[i] > ofGetWidth()-size[i])
        {
            xpos[i] = ofGetWidth()-size[i];
            vx[i] *= -1;
        }
        
        // Bounce on left side of screen
        if(xpos[i] < size[i])
        {
            xpos[i] = size[i];
            vx[i] *= -1;
        }
        
        // Bounce on bottom of screen
        if(ypos[i] > ofGetHeight()-size[i])
        {
            ypos[i] = ofGetHeight()-size[i];
            vy[i] *= -1;
        }
        
        // Bounce on top of screen
        if(ypos[i] < size[i])
        {
            ypos[i] = size[i];
            vy[i] *= -1;
        }
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 255, 255, 5);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    for(int i=0; i<NUM_SHAPES; i++)
    {
        ofSetColor(r[i], g[i], b[i],200);
        if(type[i]==0)
        {
            ofCircle(xpos[i], ypos[i], size[i]);
        }
        else if(type[i]==1)
        {
            ofRect(xpos[i], ypos[i], size[i], size[i]);
        }
        else if(type[i]==2)
        {
            equilateralTriangleInACircle(xpos[i], ypos[i], size[i]);
        }
        else
        {
            cout << "unknown type" << type[i] << endl;
        }
    }
    
    
    // Show the frames per second on the top left
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+" fps", 10, 20);
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


