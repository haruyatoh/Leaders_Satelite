//
//  Macau.cpp
//  Leaders_Satellite
//
//  Created by 矢頭　春香 on 2016/06/21.
//
//

#include "Macau.hpp"

void Macau::setup(){
    
    bool result = response.open("http://api.openweathermap.org/data/2.5/weather?units=metric&lat=22&lon=113&appid=6a0656100a27de971546482677c35c2e");
    bool result2 = response2.open("http://api.fixer.io/latest?base=CNY");
    
}

void Macau::draw(){
    ofSetColor(0, 255, 127);
    
    int s = ofGetSeconds();
    int m = ofGetMinutes();
    int h = ofGetHours();
    int n;
    if(h>=1){
        n = h-1;
        
    }else{
        n = h+24-1;
    }
    
    string weather = response["weather"][0]["main"].asString();
    float temp = response["main"]["temp"].asFloat();
    float rate = response2["rates"]["JPY"].asFloat();
    
    string city = "City　: Macau\n\n";
    city += "Country　: China\n\n";
    city += "Time　: " + ofToString(n, 0) + ":" + ofToString(m, 0) + ":" + ofToString(s, 0) + "\n\n";
    city += "Time difference : -1h\n\n";
    city += "Flight time : 5h5min\n\n";
    city += "Weather : " + weather + "\n\n";
    city += "Temperature : " + ofToString(temp, 1) + "\n\n";
    city += "Exchange : " + ofToString(rate,2) + " yen";
    ofDrawBitmapString(city, ofGetWidth()-200, 200);
    
}