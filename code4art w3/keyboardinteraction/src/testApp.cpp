#include "testApp.h"


int myCircleX;
int myCircleY;
//--------------------------------------------------------------
void testApp::setup(){
    
    myCircleX = 400;
    myCircleY = 500;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 0, 255);
    ofCircle(myCircleX, myCircleY, 200);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    cout << "keyPressed" << key << endl;
    //we're pushing everything to the console window
    // 'endl' is platform independent or can go windows etc.
    // use it instead of "/n"
    
    

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    cout << "keyReleased" << key << endl;
    
    if(key=='w' || key=='W') // up
    // or key=119
    // you can get the no. from asciitable.com or print out w/ cout
    // incase user put caplocks on
    {
        myCircleY--;
    }
    if(key=='a' || key=='A') //left
    {
        myCircleX--;
    }
    if(key=='s' || key=='S') //down
    {
        myCircleY++;
    }
    if(key=='d' || key=='D') //right
    {
        myCircleX++;
    }

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