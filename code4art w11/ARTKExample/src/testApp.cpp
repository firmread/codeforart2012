#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	vidGrabber.initGrabber(640, 480);

	// Load the image we are going to distort
	pizza.loadImage("pizza.png");
    
	artk.setup(vidGrabber.getWidth(), vidGrabber.getHeight());

    threshold=85;
	artk.setThreshold(threshold);
}

//--------------------------------------------------------------
void testApp::update(){

	vidGrabber.grabFrame();

	if(vidGrabber.isFrameNew()) 
    {	
        grayFrame.setFromPixels(vidGrabber.getPixelsRef());
        grayFrame.setImageType(OF_IMAGE_GRAYSCALE);
        
		// Pass in the new image pixels to artk
		artk.update(grayFrame.getPixels());
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(255);
	vidGrabber.draw(0, 0);
	artk.draw(0, 0);
	
    
	artk.applyProjectionMatrix(); // First apply the projection matrix once
	ofEnableAlphaBlending();
    ofNoFill();
	for(int i=0; i<artk.getNumDetectedMarkers(); i++) 
    {
        int id = artk.getMarkerID(i);
        
        if(id%2==0)
        {
            // Set the matrix to the perspective of this marker
            // The origin is in the middle of the marker	
            artk.applyModelMatrix(i);
            
            ofSetColor(255, 255, 255, 255);
            pizza.draw(-25, -25, 50, 50);
            
            // Draw a line from the center out
            ofSetLineWidth(5);
            ofLine(ofPoint(0, 0, 0), ofPoint(0, 0, 50));

            
            // Draw a stack of rectangles by offseting on the z axis
            ofEnableSmoothing();
            ofSetColor(255, 255, 0, 50);	
            for(int i=0; i<10; i++) 
            {		
                ofRect(-25, -25, 50, 50);
                ofTranslate(0, 0, i*1);
            }
        }
	}
    ofDisableAlphaBlending();    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == OF_KEY_UP) {
		artk.setThreshold(++threshold);
	}
    
    if(key == OF_KEY_DOWN) {
		artk.setThreshold(--threshold);		
	}

	if(key == 's')
    {
		vidGrabber.videoSettings();
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

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

