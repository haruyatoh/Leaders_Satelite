//
//  RiodeJaneiro.hpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/21.
//
//

#ifndef RiodeJaneiro_hpp
#define RiodeJaneiro_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"


class RiodeoJaneiro{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    ofxJSONElement response2;
    
    ofTrueTypeFont waster;

};


#endif /* RiodeJaneiro_hpp */
