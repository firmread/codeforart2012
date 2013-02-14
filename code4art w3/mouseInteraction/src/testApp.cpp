#include "testApp.h"

int myCircleX;
int myCircleY;
int myCircleRadius;
bool mouseIsDown;

//--------------------------------------------------------------
void testApp::setup(){
    myCircleX = 500;
    myCircleY = 500;
    myCircleRadius = 100;
    mouseIsDown=false;
}

//--------------------------------------------------------------
void testApp::update(){

    if(mouseIsDown)
    {
        int d;
        d = ofDist(mouseX, mouseY, myCircleX, myCircleY);
        //cout << "distance btw click and circle = " << d << endl;

        if ( d< myCircleRadius)
        {
            cout << "clicked on circle" << endl;
            myCircleRadius++;
        } 
        else 
        {
            cout << "didn't click on circle" << endl;
            //myCircleX = x;
            //myCircleY = y;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(230, 178, 94);
    ofCircle(myCircleX, myCircleY, myCircleRadius);
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
    mouseIsDown = true;
    //myCircleX = x;
    //myCircleY = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    mouseIsDown = false;
    
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