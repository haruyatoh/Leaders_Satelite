//
//  Paris.hpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/21.
//
//

#ifndef Paris_hpp
#define Paris_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"


class Paris{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    ofxJSONElement response2;
    
    ofTrueTypeFont waster;
    
};

#endif /* Paris_hpp */
