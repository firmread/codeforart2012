#include "testApp.h"
    
//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
    ofBackground(255, 255, 255);
    //ofBackground(118, 161, 154);
    ofSetWindowTitle("firmHW2");
    ofSetWindowShape(500, 500);
    ofSetFrameRate(60);
    
    icount = 0;
    counter = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
	counter = counter + 0.033f;
    irandom = ofRandom(20);
    
    //cout << "icount = " << icount << "\n";
    //cout << "irandom = " << irandom << "\n";
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
    
    if( runner ){
        radius = 300 * sin(counter);
    }

    ofSetColor(176, 197, 187, 255);
    ofRect(100, 100, radius/3, radius/3);

    ofSetColor(166, 141, 96, 255);
    ofRect(400, 100, radius/3, radius/3);
    
    ofSetColor(217, 89, 61, 255);
    ofRect(100, 400, radius/3, radius/3);
    
    ofSetColor(176, 197, 187, 255);    
    ofRect(400, 400, radius/3, radius/3);
    
    ofSetColor(118, 161, 154, 255/3);
    ofRect(250,250,radius*1.5,radius*1.5);
    
    
    //ofPushMatrix();
    //ofTranslate(250, 250);
    
    //for (icount = 0 ; icount<20; icount++) {
        //ofRotate(icount);
        //ofScale(1+(icount/100), 1+(icount/100));
        //ofTriangle(0, -50, 50, 50, -50, 50);
        //ofEllipse(irandom, irandom, icount, icount);
    //}
    
    //ofPopMatrix();
    
    cout << "radius = " << radius << "\n";
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    cout << "key = " << key << "\n";
    
    if ((key = 'a')){
        runner = !runner;
    }
    
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

    if(button == 0){
        runner = !runner;
    }
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