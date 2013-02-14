//
//  myBall.h
//  emptyExample
//
//  Created by firm on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef emptyExample_myBall_h
#define emptyExample_myBall_h

//class name actually should always started with capital letter " MyBall "

// 2 thing it can do
// have proporties
// can do things

class myBall{
public:
    float x;
    float y;
    float radius;
    
    int r;
    int g;
    int b;
    
    //we can also put fn into the class
    void drawMe(){
        ofSetColor(r, g, b);
        ofCircle(x, y, radius);
    }
};
//*** close bracket with semicolon ***


#endif
