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

	tube = Tube(path, 18, 12, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.25, .9), 27), true, "gold01.jpg");
	tube.setDiffuseMaterial({ 1.0f, 1, 1 });
	tube.setAmbientMaterial(0.15f);
	tube.setBumpMap("gold01.jpg", .65f);
	//tube.loadBumpMapTexture("vascular3_normal2.jpg");
	tube.setTextureScale({ 1, 0.1f });
	tube.setSpecularMaterial({1, 1, 1});
	tube.setShininess(5);


	plane = ProtoPlane({}, {}, Dim2f(0, 0), Col4f(1), 1, 1, "linen.jpg");
	plane.setDiffuseMaterial({ 1, 1, 1, 1 });
	//plane.setBumpMap("woodPlank.jpg", .55);
	plane.loadBumpMapTexture("crinkled_paper_normal.jpg");
	plane.setTextureScale({.5f, .5f});
	plane.setSpecularMaterial({ 1, 1, 1 });
	plane.setShininess(15);
}

void ProtoController::run() {
}

void ProtoController::display() {
	setLight(0, Vec3(+sin(radians(getFrameCount())) * 90, 0, 400), { 1, 1, 1 });
	translate(0, 0, -500);
	arcBallBegin();
	push();
	translate(0, 0, 400);
	scale(3.3);
	rotate(getFrameCount()*.6*PI / 180, { .75f, 1, .25f });
	tube.display();
	pop();

	push();
	translate(0, 0, -400);
	scale({ 3000, 1850, 1 });
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