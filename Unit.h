#pragma once
#include "ofMain.h"

class Unit {
public:
	Unit(int dimsize);
	~Unit() {};
	void update(int dimsize);
	void draw();
	void setStickInUnit(ofColor col, int alp, int slen, int swei);
	void setBallInUnit(ofColor col, int alp, int siz);
	void setBlockcolor(ofColor col, int alp);
private:
	//center of ball
	ofVec3f location;
	ofVec3f velocity;
	//0 north, 1 east, 2 south, 3 west
	int orient;

	ofSpherePrimitive ball;
	ofColor ballcolor;

	ofColor stickcolor;
	int sticklen;
	int stickweight;

	ofColor blockcolor;
	int blocksize;
};