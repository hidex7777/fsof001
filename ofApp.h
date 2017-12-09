#pragma once

#include "ofMain.h"
#include "Unit.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void reset();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void floorboxSet(int dimsize);
	void floorboxDraw();
	//settings
	//background
	int dimensionsize = 2000;
	ofColor bgc = ofColor(241, 241, 241);//Gy9.5
	//floor
	ofColor bxc = ofColor(255, 255, 255);//W
	int floorboxalpha = 100;
	int floorboxsize = 100;
	vector<ofVec3f> boxpos;
	ofBoxPrimitive box;
	//ball
	ofColor ballcolor = ofColor(166, 29, 57);//dp2
	int ballalpha = 180;
	int ballsize = 100;
	//stick
	ofColor stickcolor = ofColor(0, 0, 0);//Bk
	int stickalpha = 160;
	int sticklen = 200;
	int stickweight = 2;
	//block
	int blockweight = 2;
	int blockstep = 25;
	int blockalpha = 160;

	//unit
	int unit_num = 9;
	vector<shared_ptr<Unit>> units;
	
	ofCamera cam;
	//ofEasyCam cam;
	ofLight light;
	ofImage img;
};
