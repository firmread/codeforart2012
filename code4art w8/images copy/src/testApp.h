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
    void drawSnowman()
    {
        ofPushStyle();
        
        // Head
        ofFill();
        ofSetColor(255,255,255);
        ofCircle(50, 50, 25);
        ofCircle(50, 90, 30);
        ofCircle(50, 160, 50);
        
        // Eyes & Buttons
        ofSetColor(0, 0, 0);
        ofCircle(42, 43, 4);
        ofCircle(57, 43, 4);
        ofCircle(50, 80, 3);
        ofCircle(50, 100, 3);
        ofCircle(50, 120, 3);
        
        // Nose
        ofSetHexColor(0xED9121);
        ofTriangle(45, 51, 55, 51, 50, 65);
        
        //Arms
        ofSetHexColor(0x7B3F00);
        ofSetLineWidth(3);
        ofLine(76, 85, 101, 75);
        ofLine(96, 78, 97, 65);
        ofLine(96, 79, 102, 85);
        ofLine(24, 86, -3, 77);
        ofLine(2, 80, 4, 68);
        
        // Hat
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(0, 0, 0);
        ofRect(50, 25, 50, 5);
        ofRect(50, 15, 30, 20);
        
        ofPopStyle();
    }
    
    void drawBoat()
    {
        ofPushStyle();
        ofFill();
        
        // Hull
        ofSetHexColor(0x603311);
        ofCurve(800, -400, 50, 200, 400, 200, 200, -400);
        
        // Mast
        ofRect(200, 0, 10, 200);
        
        // Flag
        ofSetColor(0, 0, 0);
        ofRect(100, 0, 100, 60);
        
        ofPopStyle();
    }
    
    void drawSkullAndCrossbones()
    {
        ofPushStyle();
        
        // Bones
        ofFill();
        ofSetHexColor(0xFFFFCC);
        ofSetLineWidth(10);
        ofLine(85, 110, 305, 308);
        ofLine(330, 112, 87, 286);
        ofCircle(85, 110, 20);
        ofCircle(305, 308, 20);
        ofCircle(330, 112, 20);
        ofCircle(87, 286, 20);
        
        // Skull
        ofEllipse(200, 200, 180, 200);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofRect(200, 280, 100, 100);
        
        // Teeth
        ofSetLineWidth(3);
        ofSetColor(0, 0, 0);
        ofLine(170, 300, 170, 330);
        ofLine(190, 300, 190, 330);
        ofLine(210, 300, 210, 330);
        ofLine(230, 300, 230, 330);
        
        // Eyes
        ofCircle(166, 168, 30);
        ofCircle(230, 168, 25);
        
        ofPopStyle();
		
};
