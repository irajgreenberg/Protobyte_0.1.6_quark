#include "ProtoController.h"

void ProtoController::init() {
	//setLight(0, { 0, 0, 600 }, { 1, 1, 1 });
	shadowsOn();
	std::vector<Vec3> pts;
	float theta = 0;
	for (int i = 0; i < 30; i++) {
		float r = random(14, 30);
		pts.push_back(Vec3f(sin(theta) * r, -60 + i * 4, cos(theta) * r));
		theta += TWO_PI * 4 / 30;
	}
	Spline3 path(pts, 3, false, 1.0);

	tube = Tube(path, 18, 12, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.25, .9), 27), false, "metal_dirty02.jpg");
	tube.setDiffuseMaterial({ 1.0f, 1, 1 });
	tube.setAmbientMaterial(0.15f);
	tube.setBumpMap("goldGate.jpg", .45f);
	//tube.loadBumpMapTexture("vascular3_normal2.jpg");
	tube.setTextureScale({ 1, 0.1f });
	tube.setSpecularMaterial({.8f, .74f, .85f});
	tube.setShininess(33);


	plane = ProtoPlane({}, {}, Dim2f(0, 0), Col4f(1), 1, 1, "shipPlate.jpg");
	plane.setDiffuseMaterial({ 1, 1, 1, 1 });
	plane.setBumpMap("shipPlate.jpg", .35);
	//plane.loadBumpMapTexture("corroded_red_normal.jpg");
	plane.setTextureScale({ 1, 1 });
	plane.setSpecularMaterial({ 1, 1, .655f });
	plane.setShininess(25);
}

void ProtoController::run() {
}

void ProtoController::display() {

	//setLight(0, { float(sin(getFrameCount()*PI / 180) * random(1200)) , float(sin(getFrameCount() * PI / 180) * random(1200)), 1000}, { .75f+ random(.25f), .75, .75 });

	setLight(0, Vec3(-200, 100, 1500), { 1, 1, 1 });

	translate(0, 0, -100);


	arcBallBegin();
	push();
	translate(0, 0, 200);
	scale(1.75);
	rotate(getFrameCount()*.6*PI / 180, { .75f, 1, .25f });
	tube.display();
	tube.displayTBN();
	pop();

	push();
	translate(0, 0, 0);
	scale({ 1300, 1250, 1 });
	plane.display();
	pop();

	arcBallEnd();
}

// Key and Mouse Events
void ProtoController::keyPressed() {
}

void ProtoController::mousePressed() {
	GLSLInfo(&shader3D);
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