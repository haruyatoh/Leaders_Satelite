#pragma once

#include "ofMain.h"
#include "ofxSatellite.h"
#include "ofxJSONElement.h"
#include "Tokyo.hpp"
#include "NewYork.hpp"
#include "LosAngels.hpp"
#include "Honolulu.hpp"
#include "Sydney.hpp"
#include "Shanghai.hpp"
#include "Singapole.hpp"
#include "Paris.hpp"
#include "London.hpp"
#include "Rome.hpp"
#include "Copenhagen.hpp"
#include "RiodeJaneiro.hpp"

typedef struct {
    string name;
    float latitude;
    float longitude;
} City,City1,City2,City3,City4,City5,City6,City7,City8,City9,City10,City11;

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofSpherePrimitive earthSphere;
    
    ofImage colorMap;
    
    ofx::Geo::ElevatedCoordinate myLocation;
    
    std::vector<ofx::Satellite::Satellite> satellites;
    
    float scaler;
    
    float rot;
    
    ofEasyCam cam;
    
    ofTrueTypeFont waster;
    ofTrueTypeFont waster2;
    
    vector<City> cities;
    vector<City1> cities1;
    vector<City2> cities2;
    vector<City3> cities3;
    vector<City4> cities4;
    vector<City5> cities5;
    vector<City6> cities6;
    vector<City7> cities7;
    vector<City8> cities8;
    vector<City9> cities9;
    vector<City10> cities10;
    vector<City11> cities11;
    
    Tokyo tokyo;
    NewYork newyork;
    LosAngels losangels;
    Honolulu honolulu;
    Sydney sydney;
    Shanghai shanghai;
    Singapole singapole;
    Paris paris;
    London london;
    Rome rome;
    Conpenhagen copenhagen;
    RiodeoJaneiro riodejaneiro;
    
    bool nyk;
    bool los;
    bool hon;
    bool syd;
    bool sha;
    bool sing;
    bool par;
    bool lon;
    bool rom;
    bool cop;
    bool rio;
    bool came;
};
