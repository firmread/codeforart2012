#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	
	ofBackground(255, 246, 0);
	ofAddListener(recognizer.speechRecognizedEvent, this, &testApp::speechRecognized);
    recognizer.initRecognizer();
    recognizer.loadDictionaryFromFile("dictionary.txt");
    recognizer.startListening();
	
	scrollspace = 0;
	
	franklinBook.loadFont("frabk.ttf", 14);
	franklinBook.setLineHeight(100);

    refreshRate=2;
	searchjapan=true;
	searchchina=false;
    

	}


//--------------------------------------------------------------
void testApp::update()
{
		
	
	if(ofGetElapsedTimef()-lastRefreshTime > refreshRate)
    {
        string url = "http://search.twitter.com/search.json" + json["refresh_url"].asString();
        json.open(url);
        cout << json.getRawString();
		
		string url2 = "http://search.twitter.com/search.json" + json2["refresh_url"].asString();
        json2.open(url2);
        cout << json2.getRawString();
        
        for(int i=0; i<json["results"].size(); i++)
        {
            string tweet = json["results"][i]["text"].asString();
			ofSetColor(233, 100, 0);
            tweets.push_back( tweet );
        }
        
		
        for(int i=0; i<json2["results"].size(); i++)
        {
            string tweet2 = json2["results"][i]["text"].asString();
			ofSetColor(233, 100, 0);
            tweets2.push_back( tweet2 );
        }
        
        lastRefreshTime = ofGetElapsedTimef();
    }
}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetColor(244, 100, 100);
	ofCircle(200, 200,tweets.size());
	ofCircle(400, 200, tweets2.size());
	//cout << "China = " << tweets.size() << ", Japan = "<< tweets2.size()<< endl;
	ofPushMatrix();
	ofTranslate(0, scrollspace);
	
	
    for(int i=0; i<tweets.size(); i++)
    {
		ofSetColor(0);
        franklinBook.drawString(tweets[i], 10, 148+i*30);
		
    }
	for(int i=0; i<tweets2.size(); i++)
    {
		ofSetColor(0);
        franklinBook.drawString(tweets2[i], 10, 148+i*30);
		
    }
	ofPopMatrix();

}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	//switch (key) {
//		case '=':
//			scrollspace += 70;
//			break;
//		case '-':
//			scrollspace -= 70;
//			break;
//
//	}
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

void testApp::speechRecognized(string & wordRecognized)
{
    cout << wordRecognized << endl;
/*    
    if(wordRecognized == "bigger")
    {
        circle_radius += 20;
    }
    
    if(wordRecognized == "smaller")
    {
        circle_radius -= 20;
    }
 */
	
    if(wordRecognized == "up")
    {
        scrollspace -= 50;
    }
    
    else if(wordRecognized == "down")
    {
        scrollspace += 50;
    }
	else if(wordRecognized == "japan")
    {
        for(int i=0; i<tweets2.size(); i++)
		{
			ofSetColor(0);
			franklinBook.drawString(tweets2[i], 10, 148+i*30);
			
		}
		searchjapan= true;
		searchchina= false;

    }
	else if(wordRecognized == "china")
    {
       searchchina= true;
		searchjapan= false;

    }
	else if(wordRecognized == "scroll")
    {
        scrollspace += 50;
    }else if(wordRecognized == "both")
    {
        searchchina=true;
		searchjapan=true;
    }
	// Twitter API: http://dev.twitter.com/doc/get/trends/current
	string url = "http://search.twitter.com/search.json?q=China&rpp=5&include_entities=true&result_type=mixed";
	string url2 = "http://search.twitter.com/search.json?q=Japan&rpp=5&include_entities=true&result_type=mixed";
	
    // Now parse the JSON
	if (searchchina==true && searchjapan==false) {
		json.open(url);
		
	}else if(searchchina==false && searchjapan==true){
		json2.open(url2);
		
	}else if(searchchina==true && searchjapan==true){
		json.open(url);
		json2.open(url2);
	}
	
    lastRefreshTime = ofGetElapsedTimef();
    
	// cout << json.getRawString();
	// cout << json2.getRawString();
    
    
    for(int i=0; i<json["results"].size(); i++)
	{
		string tweet = json["results"][i]["text"].asString();
		tweets.push_back( tweet );
		
	}
	for(int i=0; i<json2["results"].size(); i++)
	{
		string tweet2 = json2["results"][i]["text"].asString();
		tweets2.push_back( tweet2 );
		
	}	
	
	
	
	
	//string url3 = "http://search.twitter.com/search.json?q=";
//	string searchterm;
//	string restUrl= "&rpp=5&include_entities=true&result_type=mixed";
//	url3 += searchterm += restUrl;
}


//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
