#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	 
	ofSetFrameRate(24);
	
	// this load font loads the non-full character set
	// (ie ASCII 33-128), at size "32"
	
	franklinBook.loadFont("frabk.ttf", 32);
	franklinBook.setLineHeight(36);

//	string url = "http://www.flickr.com/services/rest/?method=flickr.interestingness.getList&api_key=76fee119f6a01912ef7d32cbedc761bb&format=json&nojsoncallback=1";

    string url = "http://api.flickr.com/services/rest/?method=flickr.interestingness.getList&api_key=3dda56307d2900c95e9b3616ae613b8e&format=json&nojsoncallback=1&auth_token=72157629841975585-02d795a70e6b07f2&api_sig=ba25de0ccca78a7840c32be31ec212cf";
    
	bool parsingSuccessful = response.open(url);
	if ( !parsingSuccessful )
    {
		cout  << "Failed to parse JSON\n" << endl;
	}
    
    cout << response.getRawString();
    
	int numImages = response["photos"]["photo"].size();
	for(int i=0; i<100; i++)
	{
		int farm = response["photos"]["photo"][i]["farm"].asInt();
		string id = response["photos"]["photo"][i]["id"].asString();
		string secret = response["photos"]["photo"][i]["secret"].asString();
		string server = response["photos"]["photo"][i]["server"].asString();
		string url = "http://farm"+ofToString(farm)+".static.flickr.com/"+server+"/"+id+"_"+secret+".jpg";
		
		ofImage img;
		img.loadImage(url);
		images.push_back( img );
	}
	
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	for(int i=0; i<100; i++)
	{
		images[i].draw(i*ofGetWidth()/100, 0, ofGetWidth()/100, ofGetHeight());
	}
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
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
