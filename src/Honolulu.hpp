//
//  Honolulu.hpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/20.
//
//

#ifndef Honolulu_hpp
#define Honolulu_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"


class Honolulu{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    ofxJSONElement response2;
    
    ofTrueTypeFont waster;
};

#endif /* Honolulu_hpp */
