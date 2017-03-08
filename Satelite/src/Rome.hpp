//
//  Rome.hpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/21.
//
//

#ifndef Rome_hpp
#define Rome_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"


class Rome{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    ofxJSONElement response2;
    
    ofTrueTypeFont waster;
    
};

#endif /* Rome_hpp */
