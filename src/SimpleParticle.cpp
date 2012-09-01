
#include "SimpleParticle.h"

SimpleParticle::SimpleParticle(){
	//ofPoint loc, vel, acc;	
	myColor = ofColor(0xFFFFFFFF);
	myRadius = 30;
	velVal = ofRandom(-2,2);
	
	//////
	pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	vel.set(0,0);
	acc.set(0,0);
}

ofVec2f SimpleParticle::getPos() {
    return pos;
}

// setters
void SimpleParticle::setColor(ofColor c) {
    myColor = c;
}
void SimpleParticle::setAlpha(float a) {
	myColor = ofColor(myColor,a);
}
void SimpleParticle::setRadius(float r) {
	myRadius = r;
}
void SimpleParticle::setVel(float vv) {
	velVal = ofClamp(vv, -3, 3);
}



bool SimpleParticle::isDead() {
    // if out of bounds... or speed = 0
    if ((pos.x-myRadius>ofGetWidth()) || (pos.x+myRadius<0) || (pos.y-myRadius>ofGetHeight()) || (pos.y+myRadius<0) || (vel.squareLength() < 0.25)) {
		return true;
    }
    return false;
}

void SimpleParticle::setTarget(ofVec2f tv) {
    // unit vector towards target??
    vel = pos - tv;
    if (vel.squareLength() > 1) {
		vel.normalize();
    }
    vel *= velVal;
}


void SimpleParticle::update() {
    vel += acc;
    pos += vel;
}
void SimpleParticle::draw() {
	ofPushMatrix();
	ofTranslate(pos);
	ofSetColor(myColor);
	ofFill();
	ofCircle(pos, myRadius);
	ofNoFill();
	ofCircle(pos, myRadius);
	ofPopMatrix();
}
