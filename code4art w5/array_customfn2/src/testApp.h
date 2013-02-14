#pragma once

#include "ofMain.h"

#define NUM_SHAPES 500


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
		
          
    
        // move variables to header file makes life easier
    
        // try using ofPoint instead of x and y seperately
        // and ofColor instead of r g b separately
        
        
        //float xpos[NUM_SHAPES];
        //float ypos[NUM_SHAPES];
        ofPoint pos[NUM_SHAPES];
        
        float size[NUM_SHAPES];
        // cast the variable since you started
        int type[NUM_SHAPES];   // 0 = circle, 1 = square, 2 = triangle
        
        //float r[NUM_SHAPES];   // Red
        //float g[NUM_SHAPES];   // Green
        //float b[NUM_SHAPES];   // Blue
        ofColor color[NUM_SHAPES];
        
        //float vx[NUM_SHAPES];  // X velocity
        //float vy[NUM_SHAPES];  // Y velocity
        ofPoint v[NUM_SHAPES];
    
    
};
