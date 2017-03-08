//
//  Copenhagen.hpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/21.
//
//

#ifndef Copenhagen_hpp
#define Copenhagen_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"


class Conpenhagen{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    ofxJSONElement response2;
    
    ofTrueTypeFont waster;
    
};


#endif /* Copenhagen_hpp */
