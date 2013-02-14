//conceptualize the thing we want to write as an object
//object with a lot of recipe
//write a blueprint/recipe for it

//new .h file in src


#pragma once

#include "ofMain.h"
#include "myBall.h"
//include new file we create

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
  
        myBall a;
        myBall b;
        // these two objects are objects of the same class
    

};
