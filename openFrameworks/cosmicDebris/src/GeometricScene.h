#ifndef GEOMETRICSCENE_H
#define GEOMETRICSCENE_H

#include "Scene.h"
#include "Morphable.h"

class GeometricScene: public Scene {
	
public:
	GeometricScene(unsigned char* aVals_, unsigned char* dVals_, int* dVal_);
	~GeometricScene();
	void update();
	void draw();
	void onSerialEvent(serialEventArgs &a);
protected:
	Morphable myMorphable;
	ofColor shapeColor, bgndColor;
	bool turnOn;
	// for random variations
	float varVar;
	float currLfoFreq, targetLfoFreq, overallVolume;
	void audioOut( float * output, int bufferSize, int nChannels, int deviceID, long unsigned long tickCount );
	void audioIn( float * input, int bufferSize, int nChannels, int deviceID, long unsigned long tickCount );
private:
	void audioOutFromIn( float * output, int bufferSize, int nChannels, int deviceID, long unsigned long tickCount );
	float * soundBuffer;
	unsigned long inCnt, outCnt;
    unsigned int whichImage;
    ofImage imageChu, imageCha;
	ofImage * myImage;
	unsigned char sineOn;
};

#endif
