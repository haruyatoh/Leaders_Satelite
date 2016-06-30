//
//  London.cpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/21.
//
//

#include "London.hpp"

void London::setup(){
    
    bool result = response.open("http://api.openweathermap.org/data/2.5/weather?units=metric&lat=51&lon=0&appid=6a0656100a27de971546482677c35c2e");
    bool result2 = response2.open("http://api.fixer.io/latest?base=GBP");
    
    ofTrueTypeFont::setGlobalDpi(72);
    waster.loadFont("FFWaster_L.TTF", 20);
    waster.setLineHeight(18.0f);
    waster.setLetterSpacing(1.1);

    
}

void London::draw(){
    ofSetColor(0, 0, 255);
    
    int s = ofGetSeconds();
    int m = ofGetMinutes();
    int h = ofGetHours();
    int n;
    if(h>=8){
        n = h-8;
        
    }else{
        n = h+24-8;
    }
    
    string weather = response["weather"][0]["main"].asString();
    float temp = response["main"]["temp"].asFloat();
    float rate = response2["rates"]["JPY"].asFloat();

    
    string city = "     London\n\n";
    city += "        United Kingdom\n\n";
    city += "     " + ofToString(n, 0) + ":" + ofToString(m, 0) + ":" + ofToString(s, 0) + "\n\n";
    city += "              -8h\n\n";
    city += "         12h15min\n\n";
    city += "        " + weather + "\n\n";
    city += "           " + ofToString(temp, 1) + "\n\n";
    city += "         " + ofToString(rate,2) + "yen";
    waster.drawString(city, ofGetWidth()-250, 250);
}