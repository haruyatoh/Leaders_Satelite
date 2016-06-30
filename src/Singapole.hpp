//
//  Singapole.hpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/21.
//
//

#ifndef Singapole_hpp
#define Singapole_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"


class Singapole{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    ofxJSONElement response2;
    
    ofTrueTypeFont waster;

};


#endif /* Singapole_hpp */
