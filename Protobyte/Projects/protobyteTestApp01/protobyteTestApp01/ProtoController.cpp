#include "ProtoController.h"

void ProtoController::init() {
	setLight(0, { -300, 0, 300 }, { 1, .4f, 1 });
	shadowsOn();
	// no longer need to call assignment op
	//t = Toroid({ 0, 0, 0 }, { 0, 0, 0 }, { 1, 1, 1 }, { 1, 1, 1, .75f }, 12, 12, 125, 45);
	t.setRingCount(16);
	t.setRingDetail(16);
	t.setRingThickness(30);
	t.setRingRadius(100);

	//t = Toroid(16, 16, 425, 145);
	t.setDiffuseMaterial({ 1, 1, 1, 1 });
	t.setDiffuseMap("ship_plate_rainbow.jpg");
	t.setBumpMap("ship_plate_rainbow.jpg");
	t.setTextureScale({ 0.05f, 0.15f });
	t.setSpecularMaterial({ 1, 1, 1, 1 });
	t.setShininess(9);

	//pcg = new ProtoGeomComposite();
	//pcg->init();

	//plane = ProtoPlane({ 0 }, { 0 }, { 500, 500 }, { 1, 1, 1, 1 }, 1, 1);
	//plane.setDiffuseMap("ship_plate.jpg");
	//plane.setTextureScale({ .2f, .2f });
	//plane.setBumpMap("ship_plate.jpg");
	//plane.setSpecularMaterial({ 1, 1, 1, 1 });
	//plane.setShininess(39);


	/*int roots = 1;
	std::string urls[] = { "corroded_red.jpg", "gold_foil.jpg", "bronze_fans.jpg", "rust02.jpg", "meat01.jpg" };
	std::vector<std::string> textureURLs;
	std::vector<Vec2f> textureScales;
	std::vector<ProtoColor4f> cols;
	for (int i = 0; i < roots; i++) {
		textureURLs.push_back(urls[int(random(5))]);
		textureScales.push_back({ random(1.2, 3), random(3.2, 7) });
		cols.push_back({ random(1.0), random(1.0), random(1.0) });
	}
	pBall = new ProtoRootBall({}, {}, { 1, 1, 1 }, cols, roots, 50, 9.4f, { 70.5f, 90.5f }, textureURLs, textureScales);*/
	//printModelMatrix();
	//printViewMatrix();
	//printModelViewMatrix();
	//printProjectionMatrix();
}

void ProtoController::run() {
}

void ProtoController::display() {
	//printViewMatrix();
	translate(0, 0, 0);
	arcBallBegin();
	push();
	//scale(2); 
	fill(.5, .1, .2);
	translate(0, 0, 0);
	//noStroke();
	lineWidth = 6;
	stroke(.85, .3, .9);
	//star(9, 350, 140);

	lineWidth = 3;
	fill(.2, .3, .8);
	int stride = 7;
	float theta = 0.0;
	int sides = 9;
	int pts = sides * 2;
	float outerRadius = 200;
	float innerRadius = 70;

	//noFill();
	beginShape();
	for (int i = 0; i < pts; i++) {
		if (i % 2 == 0) {
			// Required for outline
			curveVertex(cos(theta)*outerRadius, sin(theta)*outerRadius);
		}
		else {
			// Required for outline
			curveVertex(cos(theta)*innerRadius, sin(theta)*innerRadius);
		}
		theta += TWO_PI / pts;
	}

	endShape(CLOSE);
	//ellipse(100, 100, 50, 50);
	//rect(200, 200, 150, 300);
	pop();
	push();
	translate(100, 0, 0);
	rotate(getFrameCount()*PI/180.0f, { 1, .2f, 0 });
	//plane.display();
	t.display();
	pop();

	/*scale(495);
	pBall->display();*/
	
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