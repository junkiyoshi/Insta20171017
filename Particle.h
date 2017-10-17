#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle();
	~Particle() {}

	void update();
	void draw();

private:
	ofVec2f location;
	float	step;

	float	body_size;
	ofColor body_color;
	float	alpha;
};