/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#ifndef __PROTOCONTROLLER_H__
#define __PROTOCONTROLLER_H__

#include <iostream>
#include "ProtoBaseApp.h"

using namespace ijg;

class ProtoController : public ProtoBaseApp {
	struct B_Ellipse {
		int x, y, xSpeed, ySpeed;
		B_Ellipse() {}

		B_Ellipse(int x, int y, int xSpeed, int ySpeed):
		x(x), y(y), xSpeed(xSpeed), ySpeed(ySpeed) {
		}
	};

	B_Ellipse e1;

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
