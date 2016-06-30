#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    
    rot = 0;
    
    scaler = 250 / ofx::Geo::Utils::EARTH_RADIUS_KM;
    
    colorMap.loadImage("color_map_1024.jpg");
    
    earthSphere.set(ofx::Geo::Utils::EARTH_RADIUS_KM, 24);
    ofQuaternion quat;
    quat.makeRotate(180, 0, 1, 0);
    earthSphere.rotate(quat);
    earthSphere.mapTexCoords(0,
                             colorMap.getTextureReference().getTextureData().tex_u,
                             colorMap.getTextureReference().getTextureData().tex_t,
                             0);
    
    myLocation = ofx::Geo::ElevatedCoordinate(51.507406923983446,
                                              -0.12773752212524414,
                                              0.05);

    ofHttpResponse responsed = ofLoadURL("http://www.celestrak.com/NORAD/elements/resource.txt");
    
    if (200 == responsed.status)
    {
        satellites = ofx::Satellite::Utils::loadTLEFromBuffer(responsed.data);
    }
    else
    {
        ofLogError("ofApp::setup()") << "Unable to load : " << responsed.error;
    }
    
    City okyo = { "Tokyo", -35 + 40./60, 139 + 45/60. };
    City1 ewyork = { "New york", -40 + 47/60., -73 + 58/60. };
    City2 osangels = {"Los Angels", -34 + 3/60, -118 + 15/60};
    City3 onolulu = {"Honolulu",-21 + 18/60, -157 + 50/60};
    City4 ydney = {"Sydney", 34 + 0/60, 151 + 0/60};
    City5 hanghai = {"Shanghai", -31 + 10/60, 121 + 28/60};
    City6 ingapole = {"Singapole", -1 + 14/60, 103 + 55/60};
    City7 aris = {"Paris", -48 + 48/60, 2 +20/60};
    City8 ondon = { "London", -51 + 32/60., 0./60. };
    City9 ome =  {"Rome", -41 + 54/60, 12 + 27/60};
    City10 openhagen = {"Copenhagen", -55 + 40/60, 12 + 34/60};
    City11 iodejaneiro = {"Rio de Janeiro", 22 + 57/60, -43 + 12/60};
    
    cities.push_back( okyo );
    cities1.push_back( ewyork );
    cities2.push_back( osangels );
    cities3.push_back( onolulu );
    cities4.push_back( ydney );
    cities5.push_back( hanghai );
    cities6.push_back( ingapole );
    cities7.push_back( aris );
    cities8.push_back( ondon );
    cities9.push_back( ome );
    cities10.push_back( openhagen );
    cities11.push_back( iodejaneiro );
    
    nyk = false;
    los = false;
    hon = false;
    syd = false;
    sha = false;
    sing = false;
    par = false;
    lon = false;
    rom = false;
    cop = false;
    rio = false;
    came = false;
    
    tokyo.setup();
    newyork.setup();
    losangels.setup();
    honolulu.setup();
    sydney.setup();
    shanghai.setup();
    singapole.setup();
    paris.setup();
    london.setup();
    rome.setup();
    copenhagen.setup();
    riodejaneiro.setup();
    
     cam.setPosition(0, 0, 0);
    
    ofTrueTypeFont::setGlobalDpi(72);
    waster.loadFont("FFWaster_L.TTF", 20);
    waster.setLineHeight(18.0f);
    waster.setLetterSpacing(1.1);
    
    waster2.loadFont("FFWaster_L.TTF", 15);
    waster2.setLineHeight(18.0f);
    waster2.setLetterSpacing(1.1);


}
//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofColor red = ofColor(255,0,0);
    ofColor orange = ofColor(255,127,0);
    ofColor yellow = ofColor(255,255,0);
    ofColor lightgreen = ofColor(127,255,0);
    ofColor green = ofColor(0,255,127);
    ofColor lightblue= ofColor(0,255,255);
    ofColor blue = ofColor(0,127,255);
    ofColor navy = ofColor(0,0,255);
    ofColor purple = ofColor(127,0,255);
    ofColor pink = ofColor(255,0,255);
    ofColor rose = ofColor(255,0,127);
    
    cam.begin();
    
    if(came){
    ofRotateY(ofGetFrameNum()/2);
    }
    
    if(nyk){
        ofRotateX(40);
        ofRotateY(73);
    }else if(los){
        ofRotateX(34);
        ofRotateY(118);
    }else if(hon){
        ofRotateX(21);
        ofRotateY(157);
    }else if(syd){
        ofRotateX(-34);
        ofRotateY(-151);
    }else if(sha){
        ofRotateX(31);
        ofRotateY(-121);
    }else if(sing){
        ofRotateX(1);
        ofRotateY(-103);
    }else if(par){
        ofRotateX(48);
        ofRotateY(-2);
    }else if(lon){
        ofRotateX(51);
        ofRotateY(0);
    }else if(rom){
        ofRotateX(41);
        ofRotateY(-12);
    }else if(cop){
        ofRotateX(55);
        ofRotateY(-12);
    }else if(rio){
        ofRotateX(-22);
        ofRotateY(43);
    }else if(came){
        ofRotateX(0);
        ofRotateY(0);
    }else{
        ofRotateX(35);
        ofRotateY(-139);
    }

    ofPushMatrix();
    ofScale(scaler, scaler, scaler);
    
    ofSetColor(255);
    colorMap.bind();
    earthSphere.draw();
    colorMap.unbind();
    
    std::vector<ofx::Satellite::Satellite>::const_iterator iter = satellites.begin();
    
    ofx::Geo::ElevatedCoordinate pos;
    
    Poco::DateTime now;
    
    while (iter != satellites.end())
    {
        if (iter->Name().compare("AQUA") != 0 && iter->Name().compare("TERRA") != 0)
        {
            ++iter;
            continue;
        }
        
        try
        {
            pos = ofx::Satellite::Utils::toElevatedCoordinate((*iter).find(now).ToGeodetic());
        }
        catch (...)
        {
            ++iter;
            continue;
        }
        
        
        ofVec3f center = ofVec3f(0,0, pos.getElevation() / 1000 + ofx::Geo::Utils::EARTH_RADIUS_KM);
        
        ofQuaternion latRot, longRot;

        for(int i = 0; i < cities.size(); i++){
            latRot.makeRotate(cities[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            if(worldPoint.z > 0){
            ofDrawBitmapString(cities[i].name, worldPoint);
            }
        }
        
        if(nyk){
            ofSetColor(red);
        }else{
            ofSetColor(255);
        }
    
//        for(int i = 0; i < cities1.size(); i++){
//            latRot.makeRotate(cities1[i].latitude, 1, 0, 0);
//            longRot.makeRotate(cities1[i].longitude, 0, 1, 0);
//            ofVec3f worldPoint = latRot * longRot * center;
//            if(worldPoint.x < 0){
//            ofDrawBitmapString(cities1[i].name, worldPoint);
//            }
//        }
        
        latRot.makeRotate( -40 + 47/60, 1, 0, 0);
        longRot.makeRotate(-73 + 58/60, 0, 1, 0);
        ofVec3f worldPoint = latRot * longRot * center;
        cout << worldPoint.y << endl;
        if(worldPoint.z > 0){
        ofDrawBitmapString("NewYork", worldPoint);
        }
        
        if(los){
            ofSetColor(orange);
        }else{
            ofSetColor(255);
        }
        for(int i = 0; i < cities2.size(); i++){
            latRot.makeRotate(cities2[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities2[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            ofDrawBitmapString(cities2[i].name, worldPoint);
        }

        if(hon){
            ofSetColor(yellow);
        }else{
            ofSetColor(255);
        }
        for(int i = 0; i < cities3.size(); i++){
            latRot.makeRotate(cities3[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities3[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            ofDrawBitmapString(cities3[i].name, worldPoint);
        }

        if(syd){
            ofSetColor(lightgreen);
        }else{
            ofSetColor(255);
        }
        for(int i = 0; i < cities4.size(); i++){
            latRot.makeRotate(cities4[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities4[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            ofDrawBitmapString(cities4[i].name, worldPoint);
        }

        if(sha){
            ofSetColor(green);
        }else{
            ofSetColor(255);
        }
        for(int i = 0; i < cities5.size(); i++){
            latRot.makeRotate(cities5[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities5[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            ofDrawBitmapString(cities5[i].name, worldPoint);
        }

        if(sing){
            ofSetColor(lightblue);
        }else{
            ofSetColor(255);
        }
        for(int i = 0; i < cities6.size(); i++){
            latRot.makeRotate(cities6[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities6[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            ofDrawBitmapString(cities6[i].name, worldPoint);
        }

        if(par){
            ofSetColor(blue);
        }else{
            ofSetColor(255);
        }
        for(int i = 0; i < cities7.size(); i++){
            latRot.makeRotate(cities7[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities7[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            ofDrawBitmapString(cities7[i].name, worldPoint);
        }

        if(lon){
            ofSetColor(navy);
        }else{
            ofSetColor(255);
        }
        for(int i = 0; i < cities8.size(); i++){
            latRot.makeRotate(cities8[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities8[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            ofDrawBitmapString(cities8[i].name, worldPoint);
        }

        if(rom){
            ofSetColor(purple);
        }else{
            ofSetColor(255);
        }
        for(int i = 0; i < cities9.size(); i++){
            latRot.makeRotate(cities9[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities9[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            ofDrawBitmapString(cities9[i].name, worldPoint);
        }

        if(cop){
            ofSetColor(pink);
        }else{
            ofSetColor(255);
        }
        for(int i = 0; i < cities10.size(); i++){
            latRot.makeRotate(cities10[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities10[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            ofDrawBitmapString(cities10[i].name, worldPoint);
        }

        if(rio){
            ofSetColor(rose);
        }else{
            ofSetColor(255);
        }
        for(int i = 0; i < cities11.size(); i++){
            latRot.makeRotate(cities11[i].latitude, 1, 0, 0);
            longRot.makeRotate(cities11[i].longitude, 0, 1, 0);
            ofVec3f worldPoint = latRot * longRot * center;
            ofDrawBitmapString(cities11[i].name, worldPoint);
        }

        
        
        ++iter;
    }
    
    
    ofPopMatrix();
    
    cam.end();
    
    int x = 100;
    ofSetColor(255);
    string full = "Full screen";
    waster2.drawString(full,30,x-70);
    
    ofSetColor(255);
    string rotate = "Rotate";
    waster2.drawString(rotate,30,x-50);
    
    ofSetColor(255);
    string stop = "Stop";
    waster2.drawString(stop,30,x-30);
    
    ofSetColor(red);
    string NewYork = "New York";
    waster.drawString(NewYork,30,x);
    
    ofSetColor(orange);
    string LosAngels= "Los Angels";
    waster.drawString(LosAngels,30,x+30);
    
    ofSetColor(yellow);
    string Honolulu = "Honolulu";
    waster.drawString(Honolulu,30,x+60);
    
    ofSetColor(lightgreen);
    string Sydney = "Sydney";
    waster.drawString(Sydney,30,x+90);
    
    ofSetColor(green);
    string Shanghai = "Shanghai";
    waster.drawString(Shanghai,30,x+120);
    
    ofSetColor(lightblue);
    string Singapole = "Singapole";
    waster.drawString(Singapole,30,x+150);
    
    ofSetColor(blue);
    string Paris = "Paris";
    waster.drawString(Paris,30,x+180);
    
    ofSetColor(navy);
    string London  = "London";
    waster.drawString(London,30,x+210);
    
    ofSetColor(purple);
    string Rome = "Rome";
    waster.drawString(Rome,30,x+240);
    
    ofSetColor(pink);
    string Copenhagen = "Copenhagen";
    waster.drawString(Copenhagen,30,x+270);
    
    ofSetColor(rose);
    string RiodeJaneiro = "Rio de Janeiro";
    waster.drawString(RiodeJaneiro,30,x+300);
    
    
    ofSetColor(255);
    string space = "           ' spacebar '";
    waster2.drawString(space,30,x-70);
    
    ofSetColor(255);
    string one = "           ' 1 '";
    waster2.drawString(one,30,x-50);
    
    ofSetColor(255);
    string zero = "           ' 0 '";
    waster2.drawString(zero,30,x-30);

    ofSetColor(red);
    string a = "             ' a '";
    waster.drawString(a,30,x);
    
    ofSetColor(orange);
    string b = "             ' b '";
    waster.drawString(b,30,x+30);
    
    ofSetColor(yellow);
    string c = "             ' c '";
    waster.drawString(c,30,x+60);
    
    ofSetColor(lightgreen);
    string d = "             ' d '";
    waster.drawString(d,30,x+90);
    
    ofSetColor(green);
    string e = "             ' e '";
    waster.drawString(e,30,x+120);
    
    ofSetColor(lightblue);
    string f = "             ' f '";
    waster.drawString(f,30,x+150);
    
    ofSetColor(blue);
    string g = "             ' g '";
    waster.drawString(g,30,x+180);
    
    ofSetColor(navy);
    string h = "             ' h '";
    waster.drawString(h,30,x+210);
    
    ofSetColor(purple);
    string i = "             ' i '";
    waster.drawString(i,30,x+240);
    
    ofSetColor(pink);
    string j = "             ' j '";
    waster.drawString(j,30,x+270);
    
    ofSetColor(rose);
    string k = "             ' k '";
    waster.drawString(k,30,x+300);
    
    tokyo.draw();
    
    if(nyk){
        newyork.draw();
    }
    
    if(los){
        losangels.draw();
    }
    
    if(hon){
        honolulu.draw();
    }
    
    if(syd){
        sydney.draw();
    }

    if(sha){
        shanghai.draw();
    }

    if(sing){
        singapole.draw();
    }

    if(par){
        paris.draw();
    }

    if(lon){
        london.draw();
    }

    if(rom){
        rome.draw();
    }

    if(cop){
        copenhagen.draw();
    }

    if(rio){
        riodejaneiro.draw();
    }
    
    ofSetColor(255);
    string city = "City:\n\n";
    city += "Country:\n\n";
    city += "Time:\n\n";
    city += "Time difference:\n\n";
    city += "Flight time:\n\n";
    city += "Weather:\n\n";
    city += "Temperature:\n\n";
    city += "Exchange:";
    waster.drawString(city, ofGetWidth()-250, 250);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' '){
        ofToggleFullscreen();
    }
    
    if(key == '1'){
        came = true;
    }else{
        came = false;
    }
    
    if(key == 'a'){
        nyk = true;
    }else{
        nyk = false;
    }
        
    if(key == 'b'){
        los = true;
    }else{
        los = false;
    }
    
    if(key == 'c'){
        hon = true;
    }else{
        hon = false;
    }
    
    if(key == 'd'){
        syd = true;
    }else{
        syd = false;
    }

    if(key == 'e'){
        sha = true;
    }else{
        sha = false;
    }

    if(key == 'f'){
        sing = true;
    }else{
        sing = false;
    }

    if(key == 'g'){
        par = true;
    }else{
        par = false;
    }

    if(key == 'h'){
        lon = true;
    }else{
        lon = false;
    }

    if(key == 'i'){
        rom = true;
    }else{
        rom = false;
    }

    if(key == 'j'){
        cop = true;
    }else{
        cop = false;
    }

    if(key == 'k'){
        rio = true;
    }else{
        rio = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
