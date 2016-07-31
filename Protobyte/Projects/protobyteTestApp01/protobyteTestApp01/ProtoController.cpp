#include "ProtoController.h"

void ProtoController::init() {
	setLight(0, {-10, 10, 200 }, { 1, 1, 1 });
	shadowsOn();
	std::vector<Vec3> pts;
	float theta = 0;
	for (int i = 0; i < 30; i++){
		pts.push_back(Vec3f(sin(theta) * 20, -60 + i * 4, cos(theta) * 20));
		theta += TWO_PI*4/30;
	}
	Spline3 path(pts, 3, false, 1.0);

	tube = Tube(path, 12, 12, false, "ship_plate_rainbow.jpg");
	tube.setDiffuseMaterial({ 1, 1, 1, 1 });
	tube.setDiffuseMap("ship_plate_rainbow.jpg");
	tube.setBumpMap("ship_plate_rainbow.jpg");
	tube.setTextureScale({ 1.0f, 0.15f });
	tube.setSpecularMaterial({ 1, 1, 1, 1 });
	tube.setShininess(10);

	plane = ProtoPlane({}, {}, Dim2f(1000, 800), Col4f(.8, .7, .7, 1), 1, 1, "paper02.jpg");
	plane.setDiffuseMaterial({ 1, 1, 1, 1 });
	plane.setBumpMap("ship_plate_rainbow.jpg");
	plane.setTextureScale({ 1.0f, 0.15f });
	plane.setSpecularMaterial({ 1, 1, 1, 1 });
	plane.setShininess(10);
}

void ProtoController::run() {
}

void ProtoController::display() {
	
	setLight(0, { float(sin(getFrameCount()*PI/180)*600), 0, float(cos(getFrameCount()*PI / 180)*600) }, { 1, 1, 1 });
	translate(0, 0, -100);
	
	
	arcBallBegin();
	push();
	scale(2);
	tube.display();
	pop();

	push();
	translate(0, 0, -400);
	scale(2000);
	plane.display();
	pop();

	/*push();
	translate(float(sin(getFrameCount()*PI / 180) * 50), 0, float(cos(getFrameCount()*PI / 180) * 50));
	ellipse(0, 0, 30, 30);
	pop();*/
	
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