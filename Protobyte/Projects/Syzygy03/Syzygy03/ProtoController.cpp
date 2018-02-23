/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	setBackground({ .025f, .025f, .045f, 1.0f });
	oscObj = new ProtoOSC();  // on heap
	oscObj->receive(12002);

	lt0Radius = 1500.0f;

	abacusW = 2400;
	abacusH = 1400;
	abacusD = 2500;
	beadGap = 80;
	float beadW = (abacusW - beadGap * 8) / 18;
	float beadH = (abacusH - beadGap * 8) / 18;
	float beadD = (abacusD - beadGap * 8) / 18;

	i = new ProtoIcosahedron(Vec3(), Vec3(), Dim3(30), Col4(.02f, .02f, .09f, 1), "ship_plate_rainbow.jpg", { 1, 1 });
	//i->setTextureScale({ 1, 1 });
	i->setDiffuseMaterial({ 1, 1, 1 });
	i->setAmbientMaterial(0.15f);
	i->setBumpMap("corroded.jpg", .95f);
	i->setSpecularMaterial({ 1, 1, .95f });
	i->setShininess(20);



	//t = new Toroid(Vec3(), Vec3(), Dim3(), Col4(.095f, .01f, .02f, 1.0f), 32, 32, beadW / 6, beadW / 4 * .245, "metalic.jpg", Vec2(.25f, .125f)); 
	t = new Toroid(Vec3(), Vec3(), Dim3(), Col4(.01f, .01f, .01f, 1.0f), 32, 32, beadW / 6, beadW / 4 * .245, "shipPlate_yellow.jpg", Vec2(.25f, .125f));
	t->setDiffuseMaterial({ 1, 1, 1 });
	t->setAmbientMaterial(0.15f);
	t->setBumpMap("corroded_red.jpg", .95f);
	t->setSpecularMaterial({ 1, 1, .95f });
	t->setShininess(12);

	s = new ProtoSphere(Vec3(), Vec3(), Dim3(30), Col4(.02f, .02f, .09f, 1), "ship_plate_rainbow.jpg", 1, 32, 32);
	s->setTextureScale({ 1, 1 });
	s->setDiffuseMaterial({ 1, 1, 1 });
	s->setAmbientMaterial(0.15f);
	s->setBumpMap("corroded.jpg", .95f);
	s->setSpecularMaterial({ 1, 1, .95f });
	s->setShininess(20);

	b = new ProtoBlock(Vec3(), Vec3(), Dim3(20), Col4(.01f, .07f, .02f, 1.0f), "metalic.jpg");
	b->setTextureScale({ 1, 1 });
	b->setDiffuseMaterial({ 1, 1, 1 });
	b->setAmbientMaterial(0.15f);
	b->setBumpMap("corroded.jpg", .95f);
	b->setSpecularMaterial({ 1, 1, .95f });
	b->setShininess(5);

	harp = new NonusHarp(this, {}, {}, { abacusW, abacusH, abacusD }, beadGap, b);

}

void ProtoController::run() {

}

void ProtoController::display() {
	//setLight(0, Vec3(sin(getFrameCount()*PI/180.0f*2)* lt0Radius, 900, cos(getFrameCount()*PI / 180.0f*2)* lt0Radius), { 1, .70f, 1 });
	//setLight(1, Vec3(0, sin(getFrameCount()*PI / 180.0f * 20)* lt0Radius, cos(getFrameCount()*PI / 180.0f * 20)* lt0Radius), { 1, .75f, 1 });
	setLight(0, Vec3(sin(getFrameCount()*PI / 180.0f * 2)* lt0Radius, 900, cos(getFrameCount()*PI / 180.0f * 2)* lt0Radius), { 1, .70f, 1 });
	//setLight(1, Vec3(sin(getFrameCount()*PI / 180.0f * 20)* lt0Radius, 900, cos(getFrameCount()*PI / 180.0f * 20)* lt0Radius), { 1, .75f, 1 });
	setLight(2, Vec3(600, cos(radians(getFrameCount()*2.0f)) * -1500, sin(radians(getFrameCount()*2.0f)) * 100), { 1, .75f, .75f });

	// add light

	//trace(oscObj->getMsg());
	beginArcBall();
	push();
	//translate(0, 0, -6020);
	translate(_x, _y, _z);
	//translate(100, 0, sin(getFrameCount()*3*PI/180)*-2400);
	//translate(100, 0, 800);
	//rotate(PI/4, Vec3(0, 1, 0));
	rotate(getFrameCount()*PI / 180 * .25, Vec3(0, 1, 0));
	harp->display();
	//harp->vibrate(0, oscObj->getMsg().a3);
	harp->vibrate();
	harp->strike(oscObj->getMsg().amp * 100, oscObj->getMsg().id);
	//harp->strike({ 130, 180, 200, 100, 80, 100, 50, 100, 100 });
	//harp->strike(oscObj->getMsg().a3, oscObj->getMsg().amp);
	pop();
	endArcBall();
	_x += _spdX;
	_y += _spdY;
	_z += _spdZ;
}

// Key and Mouse Events
void ProtoController::keyPressed() {
	
	// interactive controls
	switch (key) {
	case 49:
		harp->setGeom(b);
		break;
	case 50:
		harp->setGeom(s);
		break;
	case 51:
		harp->setGeom(t);
		break;
	default:
		harp->setGeom(b);
		break;
	}

	switch (key) {
	case 262:
		_spdX++;
		break;
	case 263:
		_spdX--;
		break;
	default:
		break;
	}

	switch (key) {
	case 264:
		_spdY--;
		break;
	case 265:
		_spdY++;
		break;
	default:
		break;
	}
	
	// z-axis
	switch(key) {
	case 81:
		_spdZ--;
		break;
	case 65:
		_spdZ++;
		break;
	default:
		break;
	}
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