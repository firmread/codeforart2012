#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        
        ofImage thexx;
    
        //raw pixel data of the image
        //create an array that hold rgb pixel value
        
        //char smaller room on memory 0-255
        //unsigned is only plus
    
        
        //unsigned char pixels [100];
        unsigned char* pixels;
    
        //while we don't know the size of the picture > size of the array
        //pointer just save location in memory
        //placeholder for an array that we haven't make yet
    
};
