#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    input.loadMovie("laser.mov");
    input.play();
    
    target.setHsb(25, 120, 226);
    
    hueThresh = 20;
    satThresh = 20;
    briThresh = 20;
    
    singleColor.allocate(input.getWidth(), input.getHeight(), OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void testApp::update(){
    
    input.idleMovie();
    if(input.isFrameNew()) 
    {
        ofPixels inputPixels = input.getPixelsRef();
       
        int numPix = input.getWidth() * input.getHeight();
        unsigned char pix[numPix];
        
        for(int y=0; y<input.getHeight(); y++) 
        {
            for(int x=0; x<input.getWidth(); x++)
            {
                ofColor c = inputPixels.getColor(x, y);
   
                int hueDiff = abs(target.getHue() - c.getHue());
                int satDiff = abs(target.getSaturation() - c.getSaturation());
                int briDiff = abs(target.getBrightness() - c.getBrightness());
                
                int i = y * input.getWidth() + x;
                if(hueDiff < hueThresh && satDiff < satThresh && briDiff < briThresh)
                    pix[i] = 255;
                else
                    pix[i] = 0;
            }
        }
        
        singleColor.setFromPixels(pix, input.getWidth(), input.getHeight(), OF_IMAGE_GRAYSCALE);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(target);
    ofRect(20, 30, 320, 10);
    
    ofSetColor(255);
    input.draw(20, 50);
    singleColor.draw(360, 50);
    
    
    
    ofSetColor(0);
    stringstream report;
    report << ofGetFrameRate() << "fps" << endl;
    report << "Hue Threshold: " << hueThresh << " (q & z to adjust)" << endl;
    report << "Saturation Threshold: " << satThresh << " (w & x to adjust)" << endl;
    report << "Brightness Threshold: " << briThresh << " (e & c to adjust)" << endl;
    ofDrawBitmapString(report.str(), 10, ofGetHeight()-100);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch(key) {
        case ' ':
            input.setPaused(!input.isPaused());
        case 'q':
            hueThresh+=5;
            break;
        case 'z':
            hueThresh-=5;
            break;
        case 'w':
            satThresh+=5;
            break;
        case 'x':
            satThresh-=5;
            break;
        case 'e':
            briThresh+=5;
            break;
        case 'c':
            briThresh-=5;
            break;
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
    // Make sure we are clicking inside the movie
    if(x>=20&&y>=50&&x<=340&&y<=290)
    {
        ofPixels inputPixels = input.getPixelsRef();
        target = inputPixels.getColor(x-20, y-50);
    }
    
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