#include "ProtoController.h"

void ProtoController::init() {
	setLight(0, { -100, 100, 200 }, { 1, 1, 1 });
	shadowsOn();
	t = Toroid({ 0, 0, 0 }, { 0, 0, 0 }, { 1, 1, 1 }, { 1, 1, 1, .75f }, 12, 12, 125, 45);
	t.setDiffuseMap("ship_plate_rainbow.jpg");
	t.setBumpMap("ship_plate_rainbow.jpg");
	t.setTextureScale({ 0.5f, 0.35f });
	t.setSpecularMaterial({ 1, 1, 1, 1 });
	t.setShininess(9);
	//pcg = new ProtoGeomComposite();
	//pcg->init();

	plane = ProtoPlane({ 0 }, { 0 }, { 500, 500 }, { 1, 1, 1, 1 }, 1, 1);
	t.setSpecularMaterial({ 1, 1, 1, 1 });
	t.setShininess(9);
	plane.setDiffuseMap("ship_plate.jpg");
	plane.setTextureScale({ .2f, .2f });
	plane.setBumpMap("ship_plate.jpg");
	plane.setSpecularMaterial({ 1, 1, 1, 1 });
	plane.setShininess(39);
}

void ProtoController::run() {
}

void ProtoController::display() {
	arcBallBegin();
	plane.display();
	//pcg.display();
	t.display();
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