//
//  LosAngels.cpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/18.
//
//

#include "LosAngels.hpp"

void LosAngels::setup(){
    
    bool result = response.open("http://api.openweathermap.org/data/2.5/weather?units=metric&lat=34&lon=-118&appid=6a0656100a27de971546482677c35c2e");
    bool result2 = response2.open("http://api.fixer.io/latest?base=USD");
    
    ofTrueTypeFont::setGlobalDpi(72);
    waster.loadFont("FFWaster_L.TTF", 20);
    waster.setLineHeight(18.0f);
    waster.setLetterSpacing(1.1);

    
}

void LosAngels::draw(){
    ofSetColor(255, 127, 0);
    
    int s = ofGetSeconds();
    int m = ofGetMinutes();
    int h = ofGetHours();
    int n;
    if(h>=16){
        n = h-16;
        
    }else{
        n = h+24-16;
    }
    
    string weather = response["weather"][0]["main"].asString();
    float temp = response["main"]["temp"].asFloat();
    float rate = response2["rates"]["JPY"].asFloat();
    
    string city = "     Los Angels\n\n";
    city += "        United States\n\n";
    city += "     " + ofToString(n, 0) + ":" + ofToString(m, 0) + ":" + ofToString(s, 0) + "\n\n";
    city += "              -16h\n\n";
    city += "         10h10min\n\n";
    city += "        " + weather + "\n\n";
    city += "           " + ofToString(temp, 1) + "\n\n";
    city += "         " + ofToString(rate,2) + "yen";
    waster.drawString(city, ofGetWidth()-250, 250)
    ;}

