/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {

	setBackground({ 0, 0, 0, 1.0f });

	c = new Cylinder(Vec3(), Dim3(20, 300, 20), 32, Col4(.02f, .02f, .09f, 1), "metal_flaky_blue.jpg");
	c->setTextureScale({ 1, 1 });
	c->setDiffuseMaterial({ 1, 1, 1 });
	c->setAmbientMaterial(0.15f);
	c->setBumpMap("metal_flaky_blue.jpg", .95f);
	c->setSpecularMaterial({ 1, 1, .95f });
	c->setShininess(20);
}

void ProtoController::run() {
}

void ProtoController::display() {
	arcBallBegin();
	translate(0, 0, 0);
	//rotate(getFrameCount()*PI / 180.0f, {1, 0, 0});
	
	c->display();
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