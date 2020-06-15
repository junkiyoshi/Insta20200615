#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 30;
	int radius_max = span * 0.48;
	int radius_min = span * 0.05;

	for (int x = span * 0.5; x <= ofGetWidth() - span * 0.5; x += span) {

		for (int y = span * 0.5; y <= ofGetHeight() - span * 0.5; y += span) {

			auto noise_value = ofNoise(x * 0.005 + ofGetFrameNum() * 0.015);
			auto noise_y = ofMap(noise_value, 0, 1, 0, ofGetHeight());

			auto location = glm::vec2(x, y);
			auto noise_location = glm::vec2(x, noise_y);
			auto distance = glm::distance(location, noise_location);

			if (distance < 120) {

				ofDrawCircle(location, ofMap(distance, 0, 120, radius_max, radius_min));
			}
			else {

				ofDrawCircle(location, radius_min);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
