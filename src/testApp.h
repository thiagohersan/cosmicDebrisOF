#ifndef TESTAPP_H
#define TESTAPP_H

#include "ofMain.h"
#include "StaticScene.h"
#include "Drawable.h"
#include "Morphable.h"
#include "SerialEventArgs.h"
#include "Canvas.h"

class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	// serial comm and other setup variable
	bool autoPilot;
	ofSerial mySerial;
	bool setupSerial();
	bool readSerial();

	ofEvent<serialEventArgs> serialEvent;
	Canvas c;
	
	Drawable d;
	Morphable m;
};

#endif

