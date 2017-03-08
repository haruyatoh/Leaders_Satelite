//
//  Tokyo.hpp
//  Satelite
//
//  Created by 矢頭春香 on 2016/12/27.
//
//

#ifndef Tokyo_hpp
#define Tokyo_hpp

#include "ofMain.h"
#include "ofxJSONElement.h"


class Tokyo{
public:
    void setup();
    void draw();
    
    ofxJSONElement response;
    
    ofTrueTypeFont waster;
};

#endif /* Tokyo_hpp */
