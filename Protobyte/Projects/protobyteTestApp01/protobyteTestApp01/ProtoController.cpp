#include "ProtoController.h"

void ProtoController::init() {
	setLight(0, {-300, 100, 400 }, { 1, 1, 1 });
	shadowsOn();
	std::vector<Vec3> pts;
	float theta = 0;
	for (int i = 0; i < 30; i++){
		pts.push_back(Vec3f(sin(theta) * 20, -60 + i * 4, cos(theta) * 20));
		theta += TWO_PI*4/30;
	}
	Spline3 path(pts, 3, false, 1.0);

	tube = Tube(path, 18, 12, false, "vascular3.jpg");
	tube.setDiffuseMaterial({ 1, 1, 1, 1 });
	tube.setBumpMap("vascular3.jpg");
	//tube.loadBumpMapTexture("stone_normalMap.jpg");
	tube.setTextureScale({0.3f, 0.05f });
	tube.setSpecularMaterial({ 1, 1, 1, 1 });
	tube.setShininess(5);

	plane = ProtoPlane({}, {}, Dim2f(1000, 800), Col4f(1, 1, 1, 1), 1, 1, "vascular3.jpg");
	plane.setDiffuseMaterial({ 1, 1, 1, 1 });
	plane.loadBumpMapTexture("stone_normalMap.jpg");
	plane.setTextureScale({ 1.0f, 1.0f });
	plane.setSpecularMaterial({ 1, 1, 1, 1 });
	plane.setShininess(5);
}

void ProtoController::run() {
}

void ProtoController::display() {
	
	//setLight(0, { float(sin(getFrameCount()*PI/180)*600), 0, float(cos(getFrameCount()*PI / 180)*600) }, { 1, 1, 1 });
	translate(0, 0, -300);
	
	
	arcBallBegin();
	push();
	translate(0, 0, 300);
	scale(1.5);
	rotate(getFrameCount()*.2*PI / 180, { 0, 1, 0 });
	tube.display();
	tube.displayTBN();
	pop();

	push();
	translate(0, 0, -600);
	scale({3000, 2500, 1});
	plane.display();
	pop();

	/*push();
	translate(float(sin(getFrameCount()*PI / 180) * 50), 0, float(cos(getFrameCount()*PI / 180) * 50));
	ellipse(0, 0, 30, 30);
	pop();*/
/*	glUseProgram(0);
	 
	glLineWidth(2);
	glPointSize(20);
	glColor3f(.5, .5, 1.0);
	glBegin(GL_LINE);
	glVertex3f(0,0,0);
	glVertex3f(100, 100, 100);
	glEnd();

	glUseProgram(ProtoShader::getID_2()); */
	
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