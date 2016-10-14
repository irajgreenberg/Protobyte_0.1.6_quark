/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"



void ProtoController::init() {
	float theta = 0.0;
	for (int i = 0; i < PTS; i++) {
		if (i % 2 == 0){
			vecs[i] = Vec3(cos(theta) * 100, sin(theta) * 100, 0);
			theta += TWO_PI / PTS;
		} else {
			vecs[i] = Vec3(cos(theta) * 200, sin(theta) * 200, 0);
			theta += TWO_PI / PTS;
		}

		// y-rot
		//c-s
		//s+c
		float _z = cos(PI / 3)*vecs[i].z - sin(PI / 3)*vecs[i].x;
		float _y = vecs[i].y;
		float _x = sin(PI / 3)*vecs[i].z + cos(PI / 3)*vecs[i].x;
		vecs[i] = Vec3(_x, _y, _z);
		
		
	}
}

void ProtoController::run() {
}

void ProtoController::display() {
	beginArcBall();
	{
		beginShape();
		for (int i = 0; i < PTS; i++) {
			vertex(vecs[i]);
		}
		endShape(CLOSE);
	}
	endArcBall();
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