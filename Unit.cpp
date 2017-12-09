#include "Unit.h"

Unit::Unit(int dimsize) {
	//-dim/2 < x < dim/2
	//-dim/2 < y < dim/2
	//0 < z < dim
	this->location.set(ofRandom(dimsize) - (dimsize * 0.5), ofRandom(dimsize) - (dimsize * 0.5), ofRandom(dimsize));
	this->velocity.set(ofRandom(-5, 5)*2, ofRandom(-5, 5)*2, ofRandom(-5, 5)*2);
	this->orient = ofRandom(4);
	this->blocksize = ofRandom(900) + 400;
}
void Unit::update(int dimsize) {
	this->location += this->velocity;
	if ((this->location.x < dimsize * -0.5) || (this->location.x > dimsize * 0.5)) {
		this->location.x -= this->velocity.x;
		this->velocity.x *= -1;
	}
	if ((this->location.y < dimsize * -0.5) || (this->location.y > dimsize * 0.5)) {
		this->location.y -= this->velocity.y;
		this->velocity.y *= -1;
	}
	if ((this->location.z < 0) || (this->location.z > dimsize)) {
		this->location.z -= this->velocity.z;
		this->velocity.z *= -1;
	}
	this->ball.setPosition(this->location);
}
void Unit::draw() {
	//ball
	ofSetColor(this->ballcolor);
	this->ball.draw();
	//stick
	ofSetColor(this->stickcolor);
	ofSetLineWidth(this->stickweight);
	ofVec3f mystart;
	ofVec3f myend;
	if (this->orient == 0) {
		//north
		mystart = this->location - ofVec3f(0, 0, this->sticklen + this->ball.getRadius());
		myend = this->location + ofVec3f(0, 0, this->blocksize + this->sticklen);
	}
	else if (this->orient == 1) {
		//east
		mystart = this->location + ofVec3f(this->sticklen + this->ball.getRadius(), 0, 0);
		myend = this->location - ofVec3f(this->blocksize + this->sticklen, 0, 0);
	}
	else if (this->orient == 2) {
		//south
		mystart = this->location + ofVec3f(0, 0, this->sticklen + this->ball.getRadius());
		myend = this->location - ofVec3f(0, 0, this->blocksize + this->sticklen);
	}
	else if (this->orient == 3) {
		//west
		mystart = this->location - ofVec3f(this->sticklen + this->ball.getRadius(), 0, 0);
		myend = this->location + ofVec3f(this->blocksize + this->sticklen, 0, 0);
	}
	ofDrawLine(mystart, myend);
	//block
}
void Unit::setStickInUnit(ofColor col, int alp, int slen, int swei) {
	this->stickcolor = ofColor(col, alp);
	this->sticklen = slen;
	this->stickweight = swei;
}
void Unit::setBallInUnit(ofColor col, int alp, int siz) {
	this->ballcolor = ofColor(col, alp);
	this->ball.setRadius(ofRandom(siz) + siz);
}
void Unit::setBlockcolor(ofColor col, int alp) {
	this->blockcolor = ofColor(col, alp);
}