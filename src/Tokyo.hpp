//
//  Tokyo.hpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/18.
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
