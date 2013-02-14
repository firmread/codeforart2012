#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup() {

	kinect.init();
	kinect.setVerbose(true);
	kinect.open();

	// start with the live kinect source
	kinectSource = &kinect;

	colorImg.allocate(kinect.width, kinect.height);
	grayImage.allocate(kinect.width, kinect.height);
	grayThreshNear.allocate(kinect.width, kinect.height);
	grayThreshFar.allocate(kinect.width, kinect.height);

	nearThreshold = 230;
	farThreshold  = 70;
	bThreshWithOpenCV = true;

	ofSetFrameRate(60);


	// zero the tilt on startup
	angle = 0;
	kinect.setCameraTiltAngle(angle);

	// start from the front
	pointCloudRotationY = 180;
    pointCloudRotationX = 0;
	bDrawPointCloud = false;
}

//--------------------------------------------------------------
void testApp::update() {

	ofBackground(100, 100, 100);

	kinectSource->update();

	// there is a new frame and we are connected
	if(kinectSource->isFrameNew()) {

		// load grayscale depth image from the kinect source
		grayImage.setFromPixels(kinectSource->getDepthPixels(), kinect.width, kinect.height);

		// we do two thresholds - one for the far plane and one for the near plane
		// we then do a cvAnd to get the pixels which are a union of the two thresholds
		if(bThreshWithOpenCV) {
			grayThreshNear = grayImage;
			grayThreshFar = grayImage;
			grayThreshNear.threshold(nearThreshold, true);
			grayThreshFar.threshold(farThreshold);
			cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
		} else {

			// or we do it ourselves - show people how they can work with the pixels
			unsigned char * pix = grayImage.getPixels();

			int numPixels = grayImage.getWidth() * grayImage.getHeight();
			for(int i = 0; i < numPixels; i++) {
				if(pix[i] < nearThreshold && pix[i] > farThreshold) {
					pix[i] = 255;
				} else {
					pix[i] = 0;
				}
			}
		}

		// update the cv images
		grayImage.flagImageChanged();

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
    	// also, find holes is set to true so we will get interior contours as well....
    	contourFinder.findContours(grayImage, 10, (kinect.width*kinect.height)/2, 20, false);
	}
}

//--------------------------------------------------------------
void testApp::draw() {

	ofSetColor(255, 255, 255);

    ofPushMatrix();
    ofTranslate(420, 320);
    // we need a proper camera class
    drawPointCloud();
    ofPopMatrix();

	// draw instructions
	ofSetColor(255, 255, 255);
	stringstream reportStream;
	reportStream << "accel is: " << ofToString(kinect.getMksAccel().x, 2) << " / "
								 << ofToString(kinect.getMksAccel().y, 2) << " / "
								 << ofToString(kinect.getMksAccel().z, 2) << endl
				 << "using opencv threshold = " << bThreshWithOpenCV <<" (press spacebar)" << endl
				 << "set near threshold " << nearThreshold << " (press: + -)" << endl
				 << "set far threshold " << farThreshold << " (press: < >) num blobs found " << contourFinder.nBlobs
				 	<< ", fps: " << ofGetFrameRate() << endl
				 << "press c to close the connection and o to open it again, connection is: " << kinect.isConnected() << endl
                 << "press UP and DOWN to change the tilt angle: " << angle << " degrees" << endl;
	ofDrawBitmapString(reportStream.str(),20,652);
}

void testApp::drawPointCloud() {
	ofScale(400, 400, 400);
	int w = 640;
	int h = 480;
	ofRotateY(pointCloudRotationY);
    ofRotateX(pointCloudRotationX);
    //
//	glBegin(GL_POINTS);
//	int step = 2;
//	for(int y = 0; y < h; y += step) {
//		for(int x = 0; x < w; x += step) {
//			ofVec3f cur = kinect.getWorldCoordinateFor(x, y);
//			ofColor color = kinect.getCalibratedColorAt(x,y);
//			glColor3ub((unsigned char)color.r,(unsigned char)color.g,(unsigned char)color.b);
//			glVertex3f(cur.x, cur.y, cur.z);
//		}
//	}
//	glEnd();
    //
    
//	for(int y = 0; y < h; y ++) {
//		for(int x = 0; x < w; x ++) {

//	int step = 2;
//	for(int y = 0; y < h; y += step) {
//		for(int x = 0; x < w; x += step) {
//            ofVec3f cur = kinect.getWorldCoordinateFor(x, y);
//            cout << kinect.getWorldCoordinateFor(x, y) << endl;
//            ofColor color = kinect.getCalibratedColorAt(x,y);
//            ofTranslate(0, 0, cur.z);
//            ofSetColor(color.r, color.g, color.b);
//            ofRect(cur.x, cur.y, 1, 1);
//            //            ofBox(x*3, y*3, -brightness, 2);
//		}
//	}
	int step = 2;
	for(int y = 0; y < grayImage.height; y += step) {
		for(int x = 0; x < grayImage.width; x += step) {
            
            int i = (y*grayImage.getWidth()) + x;
            int brightness = [i];
            ofColor color = kinect.getCalibratedColorAt(x,y);
            ofTranslate(0, 0, cur.z);
            ofSetColor(color.r, color.g, color.b);
            ofRect(cur.x, cur.y, 1, 1);
            //            ofBox(x*3, y*3, -brightness, 2);
		}
	}

}

//--------------------------------------------------------------
void testApp::exit() {
	kinect.setCameraTiltAngle(0); // zero the tilt on exit
	kinect.close();
}

//--------------------------------------------------------------
void testApp::keyPressed (int key) {
	switch (key) {
		case ' ':
			bThreshWithOpenCV = !bThreshWithOpenCV;
		break;

		case'p':
			bDrawPointCloud = !bDrawPointCloud;
			break;

		case '>':
		case '.':
			farThreshold ++;
			if (farThreshold > 255) farThreshold = 255;
			break;

		case '<':
		case ',':
			farThreshold --;
			if (farThreshold < 0) farThreshold = 0;
			break;

		case '+':
		case '=':
			nearThreshold ++;
			if (nearThreshold > 255) nearThreshold = 255;
			break;

		case '-':
			nearThreshold --;
			if (nearThreshold < 0) nearThreshold = 0;
			break;

		case 'w':
			kinect.enableDepthNearValueWhite(!kinect.isDepthNearValueWhite());
			break;

		case 'o':
			kinect.setCameraTiltAngle(angle);	// go back to prev tilt
			kinect.open();
			break;

		case 'c':
			kinect.setCameraTiltAngle(0);		// zero the tilt
			kinect.close();
			break;


		case OF_KEY_UP:
			angle++;
			if(angle>30) angle=30;
			kinect.setCameraTiltAngle(angle);
			break;

		case OF_KEY_DOWN:
			angle--;
			if(angle<-30) angle=-30;
			kinect.setCameraTiltAngle(angle);
			break;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {
	pointCloudRotationY = x;
    pointCloudRotationX = y;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{}

