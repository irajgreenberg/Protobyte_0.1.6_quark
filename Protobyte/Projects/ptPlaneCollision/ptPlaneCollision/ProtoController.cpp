/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	pt = Vec3(getWidth() / 2, getHeight() / 2, 0);

	// construct plane
	float t = -PI / 4.0;
	float r = 60.0f;
	for (int i = 0; i < 4; i++) {
		float x = cos(t)*r;
		float y = sin(t)*r;
		planePts[i].x = x;
		planePts[i].y = y;
		planePts[i].z = 0;
		t += TWO_PI / 4;
	}

	// rot around y
	t = 45 * PI / 180.0;
	for (int i = 0; i < 4; i++) {
		float z = cos(t)*planePts[i].z - sin(t)*planePts[i].x;
		float x = sin(t)*planePts[i].z + cos(t)*planePts[i].x;
		planePts[i].x = x;
		planePts[i].z = z;
	}
}

void ProtoController::run() {
}

void ProtoController::display() {
	arcBallBegin();
	stroke(0);
	fill(1, 1, 0);
	ellipse(0, 0, 10, 10);
	noStroke();
	beginShape();
	for (int i = 0; i < 4; i++) {
		vertex(planePts[i].x, planePts[i].y, planePts[i].z);
	}
	endShape(CLOSE);
	arcBallEnd();
}

// Key and Mouse Events
void ProtoController::keyPressed() {
}

void ProtoController::mousePressed() {
}

void ProtoController::mouseRightPressed() {
}

void ProtoController::mouseReleased() {
}

void ProtoController::mouseRightReleased() {
}

void ProtoController::mouseMoved() {
}

void ProtoController::mouseDragged() {
}

// Window Events
void ProtoController::onResized() {
}

void ProtoController::onClosed() {
}