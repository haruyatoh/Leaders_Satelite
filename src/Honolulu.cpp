//
//  Honolulu.cpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/20.
//
//

#include "Honolulu.hpp"

void Honolulu::setup(){
    
    bool result = response.open("http://api.openweathermap.org/data/2.5/weather?units=metric&lat=21&lon=-157&appid=6a0656100a27de971546482677c35c2e");
    bool result2 = response2.open("http://api.fixer.io/latest?base=USD");
    
    ofTrueTypeFont::setGlobalDpi(72);
    waster.loadFont("FFWaster_L.TTF", 20);
    waster.setLineHeight(18.0f);
    waster.setLetterSpacing(1.1);

}

void Honolulu::draw(){
    ofSetColor(255, 255, 0);
    
    int s = ofGetSeconds();
    int m = ofGetMinutes();
    int h = ofGetHours();
    int n;
    if(h>=10){
        n = h-10;
        
    }else{
        n = h+24-10;
    }
    
    string weather = response["weather"][0]["main"].asString();
    float temp = response["main"]["temp"].asFloat();
    float rate = response2["rates"]["JPY"].asFloat();
    
    string city = "     Honolulu\n\n";
    city += "        United States\n\n";
    city += "     " + ofToString(n, 0) + ":" + ofToString(m, 0) + ":" + ofToString(s, 0) + "\n\n";
    city += "              -10h\n\n";
    city += "         7h30min\n\n";
    city += "        " + weather + "\n\n";
    city += "           " + ofToString(temp, 1) + "\n\n";
    city += "         " + ofToString(rate,2) + "yen";
    waster.drawString(city, ofGetWidth()-250, 250);
    
}