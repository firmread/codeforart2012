#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    grabBackground=true;
    
    input.loadMovie("pepe.mov");
    input.play();
}

//--------------------------------------------------------------
void testApp::update(){
    input.idleMovie();
    if(input.isFrameNew()) 
    {
        grayFrame.setFromPixels(input.getPixelsRef());
        grayFrame.setImageType(OF_IMAGE_GRAYSCALE);
        
        if(grabBackground) 
        {
            background.setFromPixels( grayFrame.getPixelsRef() );
            grabBackground=false;
        }
        
        unsigned char* bgPix = background.getPixels();
        unsigned char* videoPix = grayFrame.getPixels();
        int numPix = input.getWidth()*input.getHeight();
        unsigned char* diffPix = new unsigned char[numPix];
        
        for (int y=0; y<input.getHeight(); y++) 
        {
            for(int x=0; x<input.getWidth(); x++) 
            {
                int i = y * input.getWidth() + x;
                
                if(bgPix[i] - videoPix[i] > 20)
                    diffPix[i] = 255;
                else
                    diffPix[i] = 0;
            }
        }
        difference.setFromPixels(diffPix, input.getWidth(), input.getHeight(), OF_IMAGE_GRAYSCALE);
 
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255);
    input.draw(20, 20);
    grayFrame.draw(360, 20);
    background.draw(20, 280);
    difference.draw(360, 280);
    
    ofSetColor(0);
    stringstream report;
    report << ofGetFrameRate() << "fps" << endl;
    ofDrawBitmapString(report.str(), 10, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key==' ')
        grabBackground=true;
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