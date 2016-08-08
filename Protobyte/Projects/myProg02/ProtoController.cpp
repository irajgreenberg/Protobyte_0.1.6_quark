#include "ProtoController.h"

void ProtoController::init() {
	setLight(0, { 0, 0, 0 }, { 1, 1, 1 });
	shadowsOn();
	std::vector<Vec3> pts;
	float theta = 0;
	for (int i = 0; i < 30; i++) {
		pts.push_back(Vec3f(sin(theta) * 20, -60 + i * 4, cos(theta) * 20));
		theta += TWO_PI * 4 / 30;
	}
	Spline3 path(pts, 3, false, 1.0);

	tube = Tube(path, 18, 12, false, "vascular3.jpg");
	tube.setDiffuseMaterial({ 1.0f, 0.85f, 0.8f });
	tube.setAmbientMaterial(.3f);
	tube.loadBumpMapTexture("vascular3_normal2.jpg");
	tube.setTextureScale({ 0.25f, 0.05f });
	tube.setSpecularMaterial(1);
	tube.setShininess(8);

	plane = ProtoPlane({}, {}, Dim2f(0,0), Col4f(1), 1, 1, "corroded_red.jpg");
	plane.setDiffuseMaterial({ 1, 1, 1, 1 });
	plane.loadBumpMapTexture("corroded_red_normal.jpg");
	plane.setTextureScale({ .25f, .25f });
	plane.setSpecularMaterial(1);
	plane.setShininess(25);
}

void ProtoController::run() {
}

void ProtoController::display() {

	setLight(0, { float(sin(getFrameCount()*PI / 180) * 3500) , -150, 1000}, { 1, 1, 1 });

	//setLight(0, Vec3(0, 0, 0), { 1, 1, 1 });

	translate(0, 0, -900);


	arcBallBegin();
	push();
	translate(0, 0, 300);
	scale(4.75);
	//rotate(getFrameCount()*.6*PI / 180, { 0, 1, 0 });
	tube.display();
	tube.displayTBN();
	pop();

	push();
	translate(0, 0, -1000);
	scale({ 3000, 2500, 1 });
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