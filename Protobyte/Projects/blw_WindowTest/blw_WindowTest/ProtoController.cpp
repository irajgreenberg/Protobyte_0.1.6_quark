/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::ellipse1() {
	fill(1.0, 0.0, 0.0);
	noStroke();
	ellipse(e1.x, e1.y, 10, 10);

	e1.x += e1.xSpeed;
	e1.y += e1.ySpeed;

	if (e1.x >= getWidth() / 2) {
		e1.xSpeed *= -1;
	} else if (e1.x <= -(getWidth() / 2)) {
		e1.xSpeed *= -1;
	}

	if (e1.y >= getHeight() / 2) {
		e1.ySpeed *= -1;
	} else if (e1.y <= -(getHeight() / 2)) {
		e1.ySpeed *= -1;
	}
}

void ProtoController::ellipse2() {
	fill(0.0, 0.0, 1.0);
	noStroke();
	ellipse(e2.x, e2.y, 10, 10);

	e2.x += e2.xSpeed;
	e2.y += e2.ySpeed;

	if (e2.x >= getWidth() / 2) {
		e2.xSpeed *= -1;
	} else if (e2.x <= -(getWidth() / 2)) {
		e2.xSpeed *= -1;
	}

	if (e2.y >= getHeight() / 2) {
		e2.ySpeed *= -1;
	} else if (e2.y <= -(getHeight() / 2)) {
		e2.ySpeed *= -1;
	}
}

void ProtoController::init() {
	e1 = BLW::Ellipse(0, 0, 0.1, 0);
	e2 = BLW::Ellipse(0, 0, 0, 0.1);
	println(getWidth());
	println(getHeight());
}

void ProtoController::run() {
}

void ProtoController::display() {
	ellipse1();
	ellipse2();
	stroke(0);
	strokeWeight(5);
	line(-getWidth() / 2, getHeight() / 2, getWidth() / 2, getHeight() / 2);
	line(-getWidth() / 2, getHeight() / 2, -getWidth() / 2 + 0.1, -getHeight() / 2);
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