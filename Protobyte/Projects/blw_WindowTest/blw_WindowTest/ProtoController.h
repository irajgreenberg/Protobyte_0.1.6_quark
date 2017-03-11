/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#ifndef __PROTOCONTROLLER_H__
#define __PROTOCONTROLLER_H__

#include <iostream>
#include "ProtoBaseApp.h"

using namespace ijg;

namespace BLW {
	struct Ellipse {
		float x;
		float y;
		float xSpeed;
		float ySpeed;

		Ellipse(): x(0), y(0), xSpeed(0), ySpeed(0) {
		}

		Ellipse(float x, float y, float xSpeed, float ySpeed):
		x(x), y(y), xSpeed(xSpeed), ySpeed(ySpeed) {
		}
	};
}

class ProtoController : public ProtoBaseApp {
	BLW::Ellipse e1;
	BLW::Ellipse e2;

	void ellipse1();
	void ellipse2();

public:
	void init();
	void run();
	void display();

	// Key and Mouse Events
	void keyPressed();
	void mousePressed();
	void mouseRightPressed();
	void mouseReleased();
	void mouseRightReleased();
	void mouseMoved();
	void mouseDragged();

	// Window Events
	void onResized();
	void onClosed();

};

#endif //__PROTOCONTROLLER_H__
