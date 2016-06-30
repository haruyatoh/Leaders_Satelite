//
//  LosAngels.hpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/18.
//
//

#ifndef LosAngels_hpp
#define LosAngels_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"


class LosAngels{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    ofxJSONElement response2 ;
    
    ofTrueTypeFont waster;
};


#endif /* LosAngels_hpp */
