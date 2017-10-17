#include "ofApp.h"

//--------------------------------------------------------------
ofApp::~ofApp() {
	for (int i = this->particles.size() - 1; i > -1; i--) {
		delete this->particles[i];
		this->particles.erase(this->particles.begin() + i);
	}
}

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableSmoothing();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

	for (int i = 0; i < 512; i++) {
		this->particles.push_back(new Particle());
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (Particle* p : this->particles) {
		p->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	for (Particle* p : this->particles) {
		p->draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}