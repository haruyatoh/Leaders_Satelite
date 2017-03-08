//
//  London.hpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/21.
//
//

#ifndef London_hpp
#define London_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"


class London{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    ofxJSONElement response2;
    
    ofTrueTypeFont waster;
    
};


#endif /* London_hpp */
