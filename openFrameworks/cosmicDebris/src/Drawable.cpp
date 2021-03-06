/*
 *  Drawable.cpp
 *  cosmicDebrisOF
 *
 *  Created by admin on 8/15/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Drawable.h"

Drawable::Drawable(){
	mySize = 0.0;
	myType = TYPE_CIRCLE;
	myColor = ofColor(0,0,0);
}
Drawable::~Drawable(){
}

// for setting the type of the object
void Drawable::setType(int type){
	myType = type%TYPE_SIZE;
}

// set the size (relative to [0,1])
void Drawable::setSize(float size){
	mySize = size;
}
// set the color of the shape
void Drawable::setColor(ofColor color){
	myColor = color;
}
// get drawable type
int Drawable::getType(){
	return myType;
}

// x,y are the center coordinates
// x,y,v are in pixels
void Drawable::draw(float x, float y){
	this->draw(x,y,0);
}
void Drawable::draw(float x, float y, float v){
	float rad = 0;
	float alpha = 255.0;
	switch (myType) {
		case TYPE_CIRCLE:
			// turn into pixels
			rad = ofMap(mySize, 0,1, 20,400);
			alpha = (mySize<0.25)?255.0:(ofMap(mySize,0.25,1,255,0));
			ofSetColor(ofColor(myColor,alpha));
			ofFill();
			ofCircle(x+ofRandom(-v,v), y+ofRandom(-v,v), rad);
			break;
		case TYPE_SQUARE:
			// turn into pixels
			rad = ofMap(mySize, 0,1, 25,400);
			alpha = (mySize<0.3)?255.0:(ofMap(mySize,0.3,1,255,0));
			ofSetColor(ofColor(myColor,alpha));
			ofFill();
			ofRect(x+ofRandom(-v,v), y-ofRandom(-v,v), 2*rad, 2*rad);
			break;
		case TYPE_HOR_RECT:
			// turn into pixels
			rad = ofMap(mySize, 0,1, 25,400);
			alpha = (mySize<0.3)?255.0:(ofMap(mySize,0.3,1,255,0));
			ofSetColor(ofColor(myColor,alpha));
			ofFill();
			ofRect(x+ofRandom(-v,v), y+ofRandom(-v,v), 2*rad, rad);
			break;
		case TYPE_VER_RECT:
			// turn into pixels
			rad = ofMap(mySize, 0,1, 25,400);
			alpha = (mySize<0.3)?255.0:(ofMap(mySize,0.3,1,255,0));
			ofSetColor(ofColor(myColor,alpha));
			ofFill();
			ofRect(x+ofRandom(-v,v), y+ofRandom(-v,v), rad, 2*rad);
			break;
		case TYPE_CROSS: {
			// turn into pixels
			rad = ofMap(mySize, 0,1, 25,400);
			alpha = (mySize<0.2)?255.0:(ofMap(mySize,0.2,1,255,0));
			ofSetColor(ofColor(myColor,alpha));
			ofFill();
			float rx = ofRandom(-v,v);
			float ry = ofRandom(-v,v);
			ofRect(x+rx, y+ry, rad, 2*rad);
			ofRect(x+rx, y+ry, 2*rad, rad);
		}
			break;
		default:
			// don't draw anything
			break;
	}
}