/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	black3 = ProtoColor3<float>(0.0f);
	white3 = ProtoColor3f(1.0f);
	red3 = Col3f(1.0f, 0.0f, 0.0f);
	green3 = Col3(0.0f, 1.0f, 0.0f);
	blue3 = Col3(0.0f, 0.0f, 1.0f);

	black4 = ProtoColor4<float>(0.0f);
	white4 = ProtoColor4f(1.0f);
	red4 = toCol4f(red3);
	green4 = Col4(0.0f, 1.0f, 0.0f, 0.5f);
	blue4 = Col4(0.0f, 0.0f, 1.0f, 0.5f);
}

void ProtoController::run() {
}

void ProtoController::display() {
	setBackground(0.5f);
	strokeWeight(3.0f);
	fill(blue4);
	ellipse(50, 50, 100);
	fill(1.0f, 1.0f, 0.0f, 0.5f);
	ellipse(100);
	fill(toCol4f(green3));
	ellipse(50, -50, 100);
	noFill();
	ellipse(-50, -50, 100);
	fill(red4);
	ellipse(-50, 50, 100);
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