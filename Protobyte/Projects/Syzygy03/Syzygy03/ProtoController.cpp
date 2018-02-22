/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	setBackground({ .025f, .025f, .045f, 1.0f });
	oscObj = new ProtoOSC();  // on heap
	oscObj->receive(12002);

	abacusW = 2400;
	abacusH = 1400;
	abacusD = 2500;
	beadGap = 80;
	float beadW = (abacusW - beadGap * 8) / 18;
	float beadH = (abacusH - beadGap * 8) / 18;
	float beadD = (abacusD - beadGap * 8) / 18;
	t = new Toroid(Vec3(), Vec3(), Dim3(), Col4(.02f, .01f, .05f, 1.0f), 32, 32, beadW / 6, beadW / 4 * .245, "metalic.jpg", Vec2(.25f, .125f));
	//Toroid* t = new Toroid(Vec3(), Vec3(), Dim3(), Col4(.2, .15, 0, .95), 32, 32, beadW / 6, beadW / 4 * .245, "leather2.jpg", Vec2(.2, .2));
	s = new ProtoSphere(Vec3(), Vec3(), Dim3(30), Col4(.02f, .02f, .02f, 1), "street_reflection.jpg", 1, 32, 32);
	s->setDiffuseMaterial({ 1, 1, 1 });
	s->setAmbientMaterial(0.15f);
	s->setBumpMap("white.jpg", .95f);
	s->setSpecularMaterial({ 1, 1, .95f });
	s->setShininess(12); 
	
	
	t->setDiffuseMaterial({ 1, 1, 1 });
	t->setAmbientMaterial(0.15f);
	t->setBumpMap("corroded_red.jpg", .95f);
	t->setSpecularMaterial({ 1, 1, .95f });
	t->setShininess(12); 
	harp = new NonusHarp(this, {}, {}, { abacusW, abacusH, abacusD }, beadGap, t);

}

void ProtoController::run() {
	
}

void ProtoController::display() {
	setLight(0, Vec3(sin(radians(getFrameCount()*1.0f)) * -2000, cos(radians(getFrameCount()*1.0f)) * 2000, 100), { 1, .75f, 1 });
	setLight(1, Vec3(cos(radians(getFrameCount()*1.0f)) * 1000,  500, sin(radians(getFrameCount()*1.0f)) * -2000), { 1, 1, 1 });
	//trace(oscObj->getMsg());
	beginArcBall();
	push();
	translate(0, 0, -1920);
	//translate(100, 0, sin(getFrameCount()*3*PI/180)*-2400);
	//translate(100, 0, 800);
	//rotate(PI/4, Vec3(0, 1, 0));
	//rotate(getFrameCount()*PI/180*5, Vec3(.75, .85, .95));
	harp->display();
	//harp->vibrate(0, oscObj->getMsg().a3);
	harp->vibrate();
	harp->strike(oscObj->getMsg().amp*100, oscObj->getMsg().id);
	//harp->strike({ 130, 180, 200, 100, 80, 100, 50, 100, 100 });
	//harp->strike(oscObj->getMsg().a3, oscObj->getMsg().amp);
	pop();
	endArcBall();
}

// Key and Mouse Events
void ProtoController::keyPressed() {
	
}

void ProtoController::mousePressed() {
	//t->setShininess(1);
	//t->setColor({.1f, .3f, .1f, 1.0f});
	harp->setGeom(s);
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