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
	
	//video + fullscreen
    ofVideoPlayer   boonmee;
    bool bFullscreen;
    
    //soundin
    void audioReceived(float *input, int bufferSize, int nChannels);	
    
    float volume;
    float *inputBufferCopy;
    
    //box
    ofPoint p[20];
    int boxSize;
    int boxNo;
};
