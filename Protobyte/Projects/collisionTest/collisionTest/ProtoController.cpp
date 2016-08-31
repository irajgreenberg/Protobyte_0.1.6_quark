/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	shadowsOn();
	plane = Plane({ 0 }, { 0 }, { 0 }, { .5f, .5f, .5f, 1 }, 1, 1, "dirt.jpg");
	plane.setDiffuseMaterial({ 1, 1, 1, 1 });
	plane.setBumpMap("dirt.jpg", .55);
	plane.setTextureScale({ .5f, .5f });
	plane.setSpecularMaterial({ 1, 1, 1 });
	plane.setShininess(60);

	const int BLOCK_COUNT = 10;

	for (size_t i = 0; i < BLOCK_COUNT; ++i) {
		//blocks.push_back(Block({ -getWidth() / 2.0f + random(getWidth() ), random(-100, 100), random(-200, -800) }, { 0, 0, 0 }, { 50, 50, 50 }, Col4f(.5f, .5f,.5f, 1), "metal_blue.jpg", { 1, 1 }));

		blocks.push_back(Block({ random(-getWidth()/4.0f, getWidth()/4.0f), random(-300, 300), 25 }, { 0, 0, 0 }, { 25, 25, 25 }, Col4f(.5f, .5f, .5f, 1), "metal_blue.jpg", { 1, 1 }));

		blocks.at(i).setDiffuseMaterial({ 1, 1, 1, 1 });
		blocks.at(i).setBumpMap("metal_blue.jpg", .55);
		blocks.at(i).setTextureScale({ 1, 1 });
		blocks.at(i).setSpecularMaterial({ 1, 1, 1 });
		blocks.at(i).setShininess(31);
	}



}

void ProtoController::run() {
}

void ProtoController::display() {
	//setLight(0, {sin(radians(getFrameCount())*.25f)*20, sin(radians(-getFrameCount())*.125f) * 20, 100 }, { 1, 1, 1});
	setLight(0, { 0, 0, 10 }, { 1, 1, 1 });
	translate(0, 0, -50);
	//rotate(PI/2.0f, { 1, 0, 0 });

	beginArcBall();
	push();
	translate(0, 0, -12.5f);
	for (size_t i = 0; i < blocks.size(); ++i) {
		blocks.at(i).display();
	}
	pop();

	push();
	scale(400, 200, 1);
	plane.display();
	pop();

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