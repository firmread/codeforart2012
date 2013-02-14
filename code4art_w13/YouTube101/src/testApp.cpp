#include "testApp.h"


// This function runs a command as if you were in the command line
// It also returns the output from that command as a string.
string exec(string cmd) 
{
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    result.erase(remove(result.begin(), result.end(), '\n'), result.end());
    return result;
}


//--------------------------------------------------------------
void testApp::setup(){

    // use ofToDataPath to get the complete path to the youtube-dl program
    // https://github.com/rg3/youtube-dl
    string youtube_dl = ofToDataPath("youtube-dl", true);
    

    // Open a Youtube video feed
    // http://code.google.com/apis/youtube/2.0/developers_guide_protocol_video_feeds.html
    // http://gdata.youtube.com/feeds/api/standardfeeds/most_popular?v=2&alt=json
    ofxJSONElement youtube;
    youtube.open("http://gdata.youtube.com/feeds/api/videos?q=charlie+brown&alt=json");
    
    // Loop through all of the feed->entry items in the feed
    int numVideos = min(4, (int)youtube["feed"]["entry"].size());
    for(int i=0; i<numVideos; i++)
    {
        // In each one, there will be a "link" item that contains multiple "href" strings
        // We want the first href string inside the link item
        string youtube_url = youtube["feed"]["entry"][i]["link"][UInt(0)]["href"].asString(); 
        
        // Assemble a command just like the one you would use on the command line
        // Format 18 = H264  (see http://en.wikipedia.org/wiki/YouTube#Quality_and_codecs)
        string command = youtube_dl+" --get-url --format 18 "+youtube_url;
        
        // Get the full (nasty) URL of the raw video
        string vid_url = exec(command);
        
        // Load the video (from a url!) and start playing it
        vids[i].loadMovie(vid_url);
        vids[i].play();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<4; i++)
    {
        vids[i].idleMovie();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
//    vids[0].draw(0, 0, 320, 240);
//    vids[1].draw(320, 0, 320, 240);
//    vids[2].draw(0, 240, 320, 240);
//    vids[3].draw(320, 240, 320, 240);
    vids[0].draw(0, 0, ofGetWidth()/2, ofGetHeight()/2);
    vids[1].draw(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight()/2);
    vids[2].draw(0, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2);
    vids[3].draw(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'f'){
        bool fscreen;
        fscreen = !fscreen;
        ofSetFullscreen(fscreen);
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}