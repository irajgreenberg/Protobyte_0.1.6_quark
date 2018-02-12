/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	setBackground({ .125f, .125f, .125f, 1.0f });
	shadowsOn();
	setShadowSharpness(512, 512);

	std::vector<Vec3> vecs;
	for (int i = 0; i < 25; i++) {
		vecs.push_back(Vec3(random(-200, 200), random(-200, 200), random(-200, 200)));
		trace(vecs.at(i));
	}
	s = Spline3(vecs, 8, 0, .5);
	t = Tube(s, 18, 16, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.001, 1.65f), 1), true, "humanSkin02.jpg");

	t.setPerturbation({ .08f, .04f, .06f });
	t.setDiffuseMaterial({ 1.0f, 1, 1 });
	t.setAmbientMaterial(0.15f);
	t.setBumpMap("humanSkin02.jpg", 1.2f);
	//tube.loadBumpMapTexture("vascular3_normal2.jpg");
	t.setTextureScale({ .25f, 0.08f });
	t.setSpecularMaterial({ 1, 1, 1 });
	t.setShininess(95);

}

void ProtoController::run() {
}

void ProtoController::display() {
	stroke(0);
	beginArcBall();
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