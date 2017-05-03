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

	ProtoColor3<float> black3;
	ProtoColor3f white3;
	Col3f red3;
	Col3 green3;
	ProtoColor3<float> blue3;

	ProtoColor4<float> black4;
	ProtoColor4f white4;
	Col4f red4;
	Col4 green4;
	ProtoColor4<float> blue4;

};

#endif //__PROTOCONTROLLER_H__
