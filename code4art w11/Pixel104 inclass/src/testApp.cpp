#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    input.loadMovie("laser.mov");
    input.play();
    
    targetHue = ofMap(25, 0, 360, 0, 255);
    targetSaturation = ofMap(49, 0, 100, 0, 255);
    targetValue = ofMap(85, 0, 100, 0, 255);
    // you can get it straight from Photoshop 
    // but it's 360 scale but OF take at 255 scale
    
}

//--------------------------------------------------------------
void testApp::update(){

    input.update();
    
    //running too much than video needed can be too expensive
    //only do this when it's going to new frame
    if(input.isFrameNew()){
        
        //create empty set of pixel
        ofPixels singleColorPixels;
        singleColorPixels.allocate(input.getWidth(), input.getHeight(), 1);
        // draw the same thing 
        // place of input video and only one value for each pixel (b/w)
        
        ofPixels videoPixels = input.getPixelsRef();
        
        for (int y = 0 ; y<input.getHeight(); y++) {
            
            for (int x = 0; x<input.getWidth(); x++) {
            
                ofColor c = videoPixels.getColor(x, y);
                int hueDiff = abs(targetHue - c.getHue());
                int satDiff = abs(targetSaturation - c.getSaturation());
                int valDiff = abs(targetValue - c.getBrightness());
                
                if(hueDiff < 20 && satDiff < 20 && valDiff < 20){
                    singleColorPixels.setColor(x, y, 255);
                }
                else {
                    singleColorPixels.setColor(x, y, 0);
                }
                   
            }
        }
        singleColor.setFromPixels(singleColorPixels);
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    input.draw(20,20);
    singleColor.draw(360,20);
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