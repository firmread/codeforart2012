#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxJSONElement.h"
#include "ofxSpeech.h"

class testApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void speechRecognized(string & wordRecognized);
	
	
		ofxSpeechRecognizer  recognizer;
		
		ofTrueTypeFont  franklinBook;
	
		ofxJSONElement json;
	ofxJSONElement json2;
    
        vector<string> tweets;
    vector<string> tweets2;
        float lastRefreshTime;
        float refreshRate;
		int scrollspace;
		int	tweetsize;
		bool searchjapan;
		bool searchchina;
	
	
};

#endif	

