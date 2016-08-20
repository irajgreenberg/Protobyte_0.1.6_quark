/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"




void ProtoController::init() {
	shadowsOn();
	
	setSpecular({ 1, 1, 1, 1 });
	setShininess(8);
	p = Plane({ 0 }, { 0 }, { 500, 500 }, { .5f, .5f, .5f, 1 }, 1, 1);
	p.setTextureScale({.2f, .2f});
	p.setDiffuseMap("ornateTile.jpg");
	p.setBumpMap("ornateTile.jpg", .2f);

	b = ProtoBlock(Vec3f(0, 0, 0), Vec3f(0, 0, 0), Dim3f(1), Col4f( .5f, .5f, .5f, 1 ) );
}

void ProtoController::run() {
}

void ProtoController::display() {
	setLight(0, { -10, 300, 0 }, { 1, 1, 1 });
	beginArcBall();
	push();
	translate(0, -200, 0);
	rotate(-PI / 2, { 1, 0, 0 });
	scale({3000,  5000, 1});
	p.display();
	pop();
	//printModelMatrix();
	translate(0, -getFrameCount(), 0); 
	scale(20, 50, 10);
	b.display();
	
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