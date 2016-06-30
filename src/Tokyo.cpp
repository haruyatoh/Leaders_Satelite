//
//  Tokyo.cpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/18.
//
//

#include "Tokyo.hpp"

void Tokyo::setup(){
    
    bool result = response.open("http://api.openweathermap.org/data/2.5/weather?units=metric&lat=35&lon=139&appid=6a0656100a27de971546482677c35c2e");
    
    
        if(!result){
            cout << "fail to get JSON data!" <<endl;
        }else{
            cout << response.getRawString() << endl;
        }
    
    ofTrueTypeFont::setGlobalDpi(72);
    waster.loadFont("FFWaster_L.TTF", 20);
    waster.setLineHeight(30.0f);
    waster.setLetterSpacing(1.1);
}

void Tokyo::draw(){
    ofSetColor(255);
    int s = ofGetSeconds();
    int m = ofGetMinutes();
    int h = ofGetHours();
    
    string weather = response["weather"][0]["main"].asString();
    float temp = response["main"]["temp"].asFloat();
    
    string city = "City: Tokyo\n";
    city += "Country: Japan\n";
    city += "Time: " + ofToString(h, 0) + ":" + ofToString(m, 0) + ":" + ofToString(s, 0)+"\n";
    city += "Weather: " + weather + "\n";
    city += "Temperature: " + ofToString(temp, 1) + "\n";
    waster.drawString(city, ofGetWidth()-250, 30);
}

