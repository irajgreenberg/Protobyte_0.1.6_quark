/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	background(1.0f, 0, 0);
	//setLight(0, { 0, 0, 600 }, { 1, 1, 1 });
	shadowsOn();
	setShadowSharpness(256, 256);
	
	int pathCount = 15;
	int pathVertexCount = 10;
	for (int h = 0; h <pathCount; h++) {
		std::vector<Vec3> pts;
		float x = 0;
		float y = 0;
		float z = 0;
		float xBoost = random(.45, 8);
		float yBoost = random(.15, .75);
		float zBoost = random(-.5, .5);
		for (int i = 0; i < pathVertexCount; i++) {
			pts.push_back(Vec3f(x + i * xBoost, y-i*i*yBoost, z+i*i*zBoost));
		}
		paths.push_back(Spline3(pts, 5, false, 1.0));

		tubes.push_back(Tube(paths.at(h), 18, 12, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.195, .2), 27), false, "lime2.jpg"));
		tubes.at(h).setPerturbation({ .002f, .002f, .002f });
		tubes.at(h).setDiffuseMaterial({ 1.0f, 1, 1 });
		tubes.at(h).setAmbientMaterial(0.15f);
		tubes.at(h).setBumpMap("pink2.jpg", .25f);
		tubes.at(h).setTextureScale({ 1, 0.1f });
		tubes.at(h).setSpecularMaterial({ .75f, .115f, .025f });
		tubes.at(h).setShininess(30);
	}
}

void ProtoController::run() {
}

void ProtoController::display() {
	arcBallBegin();
	translate(-100, 100, 100);
	scale(1);
	for (int h = 0; h < paths.size(); h++) {
		tubes.at(h).display();
	}
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