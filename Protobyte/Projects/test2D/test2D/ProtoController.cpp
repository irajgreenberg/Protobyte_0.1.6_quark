/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	t = Toroid(8, 8, 20.25, 4.35);
	

	

	//tube = Tube(path, 18, 12,


}

void ProtoController::run() {
}

void ProtoController::display() {
	beginArcBall();
	
	//line(100, 100, 100, 110, 110, 110);
	std::vector<Vec3> pts;
	float theta = 0;
	for (int i = 0; i < 30; i++) {
		float r = random(14, 30);
		pts.push_back(Vec3f(sin(theta) * r, -60 + i * 4, cos(theta) * r));
		theta += TWO_PI * 4 / 30;
	}
	s = Spline3(pts, 3, false, 1.0);
	s.display();
	t.display();
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