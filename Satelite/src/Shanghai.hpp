//
//  Shanghai.hpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/25.
//
//

#ifndef Shanghai_hpp
#define Shanghai_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"

class Shanghai{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    ofxJSONElement response2;
    
    ofTrueTypeFont waster;
    
};


#endif /* Shanghai_hpp */
