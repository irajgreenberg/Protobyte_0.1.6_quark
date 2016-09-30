#include "ProtoController.h"

void ProtoController::init() {
}

void ProtoController::run() {
}

void ProtoController::display() {
<<<<<<< HEAD
	//setLight(0, Vec3(sin(radians(getFrameCount()*.25f)) * 390, 0, 200), { 1, 1, 1 });

	translate(0, 0, 0);
	arcBallBegin();
	push();
	translate(0, 0, -200);
	scale(2.5);
	rotate(getFrameCount()*.6*PI / 180, { .75f, 1, .25f });
	tube.display(WIREFRAME, 6.0f);
	pop();

	push();
	rotate(getFrameCount()*.6*PI / 180, { .75f, -0.5f, .25f });
	//t.display();
	pop();

	push();
	translate(-300, 50, 50);
	scale(0.75f);
	rotate(getFrameCount()*.6*PI / 180, { -.75f, 0.5f, -.25f });
	//t.display();
	pop();

	push();
	translate(-300, 50, 300);
	scale(1.75f);
	rotate(getFrameCount()*.6*PI / 180, { -.75f, 0.5f, -.25f });
	//t.display();
	pop();

	push();
	translate(0, -50, 600);
	scale(2.25f);
	rotate(getFrameCount()*.9*PI / 180, { -.75f, 0.5f, -.25f });
	//t.display();
	pop();

	push();
	translate(0, 0, -500);
	scale({ 1024*2, 768*2, 1 });
	plane.display();
	pop();

	arcBallEnd();
=======
	//noFill();
	beginArcBall();
	fill(1, .5, .5);
	noStroke();
	scale(100);
//	rect(0, 0, 1, 1, CENTER);
	gear(20, .85, 1);
	endArcBall();
>>>>>>> 33b20e0fda1a7b90809d47645e382985c0862696
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