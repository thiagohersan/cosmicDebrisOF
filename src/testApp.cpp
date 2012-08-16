#include "testApp.h"

// return true if it sets up a serial communication port
bool testApp::setupSerial(){
	vector<ofSerialDeviceInfo> serialList = mySerial.getDeviceList();
	for(int i=0; i<serialList.size(); i++){
		string thisDevicePath = serialList.at(i).getDevicePath();
		string thisDeviceName = serialList.at(i).getDeviceName();
		int thisDeviceID = serialList.at(i).getDeviceID();
		//printf("%s, at %s, has ID %d\n", thisDeviceName.c_str(), thisDevicePath.c_str(), thisDeviceID);
		
		// find a usb port
		if((thisDeviceName.find("usb") != string::npos) || (thisDeviceName.find("USB") != string::npos) || (thisDeviceName.find("Usb") != string::npos)){
			mySerial.setup(thisDeviceID, 19200);
			return true;
		}
	}
	// did not find a usb port
	return false;
}

bool testApp::readSerial(){
	// read 4 bytes at a time
	//   use while()?
	if((!autoPilot) && (mySerial.available() >= 4)) {
		// read 4 bytes
		unsigned char tmpSerialBuf[4];
		mySerial.readBytes(tmpSerialBuf, 4);
		// check hello signal
		if(tmpSerialBuf[0] == 0xab){
			// load event args and notify
			//     gotta notify, come up in the spot looking extra fly
			//     for the day I die, I'mma touch the sky
			static serialEventArgs mySerialEventArgs;
			mySerialEventArgs.type_ = tmpSerialBuf[1];
			mySerialEventArgs.id_ = tmpSerialBuf[2];
			mySerialEventArgs.value_ = tmpSerialBuf[3];
			
			ofNotifyEvent(serialEvent, mySerialEventArgs, this);
			return true;
		}
	}
	return false;
}

//--------------------------------------------------------------
void testApp::setup(){
	// determine autoPilot and Serial port
	autoPilot = !setupSerial();
	// add a listener for the Canvas object
	ofAddListener(serialEvent, &c, &Canvas::onSerialEvent);
	
	// screen setup
	ofSetCircleResolution(100);
	ofSetVerticalSync(true);
	// other setup
	ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void testApp::update(){
	// read serial
	this->readSerial();
	
	// autopilot
	d.setType((ofGetFrameNum()/300));
	d.setSize(0.5 + (ofNoise(ofGetFrameNum()/1000.0, ofGetFrameNum()/500.0)-0.5));
	d.setSize(0.2); // just touching

	///
	m.setType(0);
	m.setSize(0.1);	// just touching
	//m.setSize(0.5 + (ofNoise(ofGetFrameNum()/1000.0, ofGetFrameNum()/500.0)-0.5));
	
	// test
	if(ofGetFrameNum()%100 == 0){
		printf("%d:= %f\n",d.getType(),ofGetFrameRate());
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0,0,0);
	// autopilot
	float hue = ofMap(ofNoise(ofGetFrameNum()/500.0, ofGetFrameNum()/2000.0), 0,1, 0,255);
	ofColor cc = ofColor::fromHsb(hue, 255, 255);
	// test
	for(int i=100; i<ofGetHeight(); i+=200){
		for(int j=100; j<ofGetWidth(); j+=200){
			//d.draw(j,i, ofRandom(5.0), cc);
			m.draw(j,i, ofRandom(5), cc);
		}
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	if((key <= '9') && (key >= '0')){
		unsigned char tmpDigit = (key-'0')&0xff;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}