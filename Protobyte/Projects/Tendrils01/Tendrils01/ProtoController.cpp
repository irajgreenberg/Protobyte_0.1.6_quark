#include "ProtoController.h"

void ProtoController::init() {
}

void ProtoController::run() {
}

void ProtoController::display() {
	//noFill();
	beginArcBall();
	fill(1, .5, .5);
	noStroke();
	scale(100);
//	rect(0, 0, 1, 1, CENTER);
	gear(20, 0.85, 1);
	endArcBall();
}

// Key and Mouse Events
void ProtoController::keyPressed() {
}

void ProtoController::mousePressed() {
	GLSLInfo(&shader3D);
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