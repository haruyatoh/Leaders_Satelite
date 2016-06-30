//
//  RiodeJaneiro.cpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/21.
//
//

#include "RiodeJaneiro.hpp"

void RiodeoJaneiro::setup(){
    
    bool result = response.open("http://api.openweathermap.org/data/2.5/weather?units=metric&lat=-22&lon=43&appid=6a0656100a27de971546482677c35c2e");
    bool result2 = response2.open("http://api.fixer.io/latest?base=BRL");
    
    ofTrueTypeFont::setGlobalDpi(72);
    waster.loadFont("FFWaster_L.TTF", 20);
    waster.setLineHeight(18.0f);
    waster.setLetterSpacing(1.1);

    
}

void RiodeoJaneiro::draw(){
    ofSetColor(255, 0, 127);
    
    int s = ofGetSeconds();
    int m = ofGetMinutes();
    int h = ofGetHours();
    int n;
    if(h>=12){
        n = h-12;
        
    }else{
        n = h+24-12;
    }

    string weather = response["weather"][0]["main"].asString();
    float temp = response["main"]["temp"].asFloat();
    float rate = response2["rates"]["JPY"].asFloat();

    
    string city = "     Rio de Janeiro\n\n";
    city += "        Brazil\n\n";
    city += "     " + ofToString(n, 0) + ":" + ofToString(m, 0) + ":" + ofToString(s, 0) + "\n\n";
    city += "              -12h\n\n";
    city += "         25h20min\n\n";
    city += "        " + weather + "\n\n";
    city += "           " + ofToString(temp, 1) + "\n\n";
    city += "         " + ofToString(rate,2) + "yen";
    waster.drawString(city, ofGetWidth()-250, 250);
    
}