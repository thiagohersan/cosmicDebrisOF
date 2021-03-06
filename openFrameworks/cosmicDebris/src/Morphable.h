/*
 *
 */

#ifndef MORPHABLE_H
#define MORPHABLE_H

#include "Geometricable.h"

// number of points in a shape
#define NUM_OF_POINTS 12
// period for morphing between shapes
#define MORPH_PERIOD 6

class Morphable: public Geometricable {
	
public:
	Morphable();
	~Morphable();
	void update();
	void draw(float x, float y);
	void draw(float x, float y, float v);
	void setType(int type);
	void setSize(float size);
	void setColor(ofColor color);
	int getType();
	float getSize();
protected:
	enum TypeEnum {TYPE_CIRCLE, TYPE_SQUARE, TYPE_HOR_RECT, TYPE_VER_RECT, TYPE_CROSS, TYPE_KAHANE, TYPE_UNO, TYPE_SIZE};
	enum StateEnum {STATE_STEADY, STATE_MORPHING};
	float currSize, targetSize;
	int currType, targetType;
	ofColor currColor;
	int currState;
	unsigned int lastMorph;
	
	vector<ofPoint> currPoints, targetPoints;
	vector<ofPoint> currLeftBez, targetLeftBez, currRightBez, targetRightBez;
	
	void morphStep();
};

#endif

