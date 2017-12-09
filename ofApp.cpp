#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(bgc);
	ofSetWindowTitle("FukushimaSphere oF 001");
	ofEnableAlphaBlending();
	ofEnableDepthTest();
	floorboxSet(dimensionsize);
	//unit.new unit_num=9
	//this->cam.setPosition(ofVec3f(0, dimensionsize * 1.5, dimensionsize));
	this->cam.setPosition(ofVec3f(0, 0, dimensionsize));
	//cam.lookAt(ofVec3f(dimensionsize / 2, dimensionsize * 0.75, dimensionsize * 0.25));
	//cam.lookAt(ofVec3f(0, -1, 0), ofVec3f(0, 0, 1));
	//this->cam.setDistance(dimensionsize);
	
	this->light.setSpotlight();
	this->light.setPosition(ofVec3f(dimensionsize * 0.5, dimensionsize, 0));
	this->light.setSpotConcentration(5);
	this->light.setAmbientColor(ofFloatColor(0.9, 0.9, 0.9,0.5));
	this->light.setDiffuseColor(ofFloatColor(0.9,0.9,0.9));
	this->light.setSpecularColor(ofFloatColor(0.8,0.8,0.8));
	this->light.enable();

	for (int i = 0; i < unit_num; i++) {
		this->units.push_back(shared_ptr<Unit>(new Unit(dimensionsize)));
		this->units[i]->setStickInUnit(stickcolor, stickalpha, sticklen, stickweight);
		this->units[i]->setBallInUnit(ballcolor, ballalpha, ballsize);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	this->light.setOrientation(ofVec3f(-90, 0,  0));
	for (int i = 0; i < this->units.size(); i++) {
		this->units[i]->update(dimensionsize);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//cam.cameraToWorld(ofVec3f(1000, 2000, 2500));
	this->cam.begin();
	ofRotateY(ofGetFrameNum());
	floorboxDraw();
	for (int i = 0; i < this->units.size(); i++) {
		this->units[i]->draw();
	}
	//this->light.draw();
	this->cam.end();
	
}
void ofApp::floorboxDraw() {
	ofSetColor(bxc, floorboxalpha);
	for (int i = 0; i < boxpos.size(); i++) {
		ofPushMatrix();
		ofTranslate(boxpos[i]);
		this->box.set(floorboxsize);
		this->box.draw();
		ofPopMatrix();
	}
}
void ofApp::floorboxSet(int dimsize) {
	for (int z = -1 * dimsize * 0.5; z < dimsize * 0.5; z += floorboxsize) {
		for (int x = -1 * dimsize * 0.5; x < dimsize * 0.5; x += floorboxsize) {
			//this->boxpos.push_back(ofVec3f(x, dimsize, z));
			this->boxpos.push_back(ofVec3f(x, -1 * dimsize * 0.5, z));
		}
	}
}
void ofApp::reset() {
	this->units.clear();
	for (int i = 0; i < unit_num; i++) {
		this->units.push_back(shared_ptr<Unit>(new Unit(dimensionsize)));
		this->units[i]->setStickInUnit(stickcolor, stickalpha, sticklen, stickweight);
		this->units[i]->setBallInUnit(ballcolor, ballalpha, ballsize);
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'x') {
		string now = ofGetTimestampString("%Y%m%d%H%M%S");
		this->img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		this->img.saveImage("of" + now + ".jpg");
	}
	else if (key == 'r') {
		this->reset();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
