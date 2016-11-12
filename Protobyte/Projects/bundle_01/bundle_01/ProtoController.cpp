/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	shadowsOn();
	setShadowSharpness(256, 256);
	int ptCount{ 90 };
	std::vector<Vec3> pts;
	float theta{ 0 }, phi{ 0 };
	for (int i = 0; i <ptCount; i++) {
		float r = random(14, 30);
		r = 100;
		float x = sin(theta) * (r-i);
		float y = 0;
		float z = cos(theta) * (r-i);
		float tx = x;
		float ty = cos(phi)*y - sin(phi)*z;
		float tz = sin(phi)*y + cos(phi)*z;
		pts.push_back(Vec3f(tx, ty, tz));
		phi += TWO_PI/ (ptCount*random(.15, 1));
		theta += TWO_PI / ptCount*random(12, 18);
	}
	Spline3 path(pts, 5, true, 1.0);

	tube = Tube(path, 4, 4, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.5, 1.9), 24), false, "gold01.jpg");
	tube.setDiffuseMaterial({ 1.0f, 1, 1 });
	tube.setAmbientMaterial(0.15f);
	tube.setBumpMap("gold01.jpg", .65f);
	//tube.loadBumpMapTexture("vascular3_normal2.jpg");
	tube.setTextureScale({ 1, 0.03f });
	tube.setSpecularMaterial({ 1, 1, 1 });
	tube.setShininess(5);

	tube2 = Tube(path, 4, 4, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.5, 1.9), 24), false, "gold01.jpg");
	tube2.setDiffuseMaterial({ 1.0f, 1, 1 });
	tube2.setAmbientMaterial(0.15f);
	tube2.setBumpMap("gold01.jpg", .65f);
	//tube.loadBumpMapTexture("vascular3_normal2.jpg");
	tube2.setTextureScale({ 1, 0.03f });
	tube2.setSpecularMaterial({ 1, 1, 1 });
	tube2.setShininess(5);
}

void ProtoController::run() {
}

void ProtoController::display() {
	beginArcBall();
	tube.display();
	push();
	rotate(PI / 2, { 0, .5, .5 });
	tube2.display();
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