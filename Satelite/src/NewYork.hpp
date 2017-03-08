//
//  NewYork.hpp
//  Satelite
//
//  Created by 矢頭春香 on 2016/12/27.
//
//

#ifndef NewYork_hpp
#define NewYork_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"


class NewYork{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    ofxJSONElement response2;
    
    ofTrueTypeFont waster;
    
};

#endif /* NewYork_hpp */
