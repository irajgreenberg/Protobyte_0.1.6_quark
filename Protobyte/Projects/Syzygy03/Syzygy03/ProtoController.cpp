/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	setBackground({ .125f, .125f, .125f, 1.0f });
	oscObj.receive(7000);

	abacusW = 2400;
	abacusH = 1800;
	abacusD = 1200;
	beadGap = 80;
	float beadW = (abacusW - beadGap * 8) / 18;
	float beadH = (abacusH - beadGap * 8) / 18;
	float beadD = (abacusD - beadGap * 8) / 18;
	Toroid* t = new Toroid(Vec3(), Vec3(), Dim3(), Col4(.20, .155, .25, 1), 32, 32, beadW / 2, beadW / 2 * .145, "metal_plate.jpg", Vec2(.65, 1));
	t->setDiffuseMaterial({ 1.0f, 1, 1 });
	t->setAmbientMaterial(0.15f);
	t->setBumpMap("metal_plate.jpg", 1.2f);
	t->setSpecularMaterial({ 1, 1, 1 });
	t->setShininess(5); 
	harp = new NonusHarp(this, {}, {}, { abacusW, abacusH, abacusD }, beadGap, t);

}

void ProtoController::run() {
	
}

void ProtoController::display() {
	beginArcBall();
	push();
	//translate(0, 0, -1900+getFrameCount());
	translate(0, 0, -1900);
	//rotate(getFrameCount()*PI/180*.125, Vec3(0, .5, 0));
	harp->display();
	harp->vibrate(0, 8);
	pop();
	endArcBall();
}

// Key and Mouse Events
void ProtoController::keyPressed() {
}

void ProtoController::mousePressed() {
	harp->strike({130, 180, 200, 100, 80, 100, 50, 100, 100});
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