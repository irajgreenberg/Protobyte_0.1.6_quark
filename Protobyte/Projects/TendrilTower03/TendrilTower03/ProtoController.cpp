/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {

	shadowsOn();
	setShadowSharpness(512, 512);
	std::vector<Vec3> pts;
	float theta = 0;
	for (int i = 0; i < 30; i++) {
		float r = random(2, 4);
		pts.push_back(Vec3f(sin(theta) * r, -60 + i * 4, cos(theta + random(PI/130.0)) * r*.25));
		theta += TWO_PI * 4 / 30;
	}
	Spline3 path(pts, 3, false, 1.0);

	tendrils.push_back(Tube(path, 18, 12, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.35, .51), 10), true, "gold01.jpg"));
	tendrils.at(0).setDiffuseMaterial({ 1.0f, 1, 1 });
	tendrils.at(0).setAmbientMaterial(0.15f);
	tendrils.at(0).setBumpMap("gold01.jpg", .95f);
	//tube.loadBumpMapTexture("vascular3_normal2.jpg");
	tendrils.at(0).setTextureScale({ 1, 0.1f });
	tendrils.at(0).setSpecularMaterial({ 1, 1, 1 });
	tendrils.at(0).setShininess(5);

	plane = ProtoPlane({}, {}, Dim2f(0, 0), Col4f(1), 1, 1, "linen.jpg");
	plane.setDiffuseMaterial({ 1, 1, 1, 1 });
	//plane.setBumpMap("woodPlank.jpg", .55);
	plane.loadBumpMapTexture("crinkled_paper_normal.jpg");
	plane.setTextureScale({ .5f, .5f });
	plane.setSpecularMaterial({ 1, 1, 1 });
	plane.setShininess(15);

}

void ProtoController::run() {
}

void ProtoController::display() {

	setLight(0, Vec3(sin(radians(getFrameCount()*.25f)) * 90, 0, 200), { 1, 1, 1 });
	beginArcBall();
	push();
	translate(0, 0, -400);
	scale({1920, 1080, 1});
	plane.display();
	pop();
	
	push();
	translate(0, 0, -200);
	scale(3);
	rotate(getFrameCount()*PI / 180, { 0, 1, 0 });
	tendrils.at(0).display();
	pop();
	endArcball();

	
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