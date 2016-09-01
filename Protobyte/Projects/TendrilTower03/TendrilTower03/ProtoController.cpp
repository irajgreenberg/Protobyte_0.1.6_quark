/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	setBackground({ .125f, .125f, .125f, 1.0f });
	shadowsOn();
	setShadowSharpness(512, 512);


	std::vector<Vec3> pts;
	float ht = 65.0f;
	float theta = 0;
	int ptCount = 8;
	for (int i = 0; i < ptCount; i++) {
		float r = 6+random(3, 8);
		pts.push_back(Vec3f(sin(theta) * r, -ht/2.0 + ht/ptCount*i*1.25f, cos(theta) * random(r, r+.25)));
		theta += TWO_PI / ptCount*1.5  ;
	}
	Spline3 path(pts, 6, false, 1.0);

	//tendrils.push_back(Tube(path, 18, 16, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(random(.325, .435), random(.456, 2.875)), 1), true, "humanSkin01.jpg"));

	tendrils.push_back(Tube(path, 18, 16, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.001, 1.65f), 1), true, "humanSkin02.jpg"));
	tendrils.at(0).setPerturbation({.08f, .04f, .06f});
	tendrils.at(0).setDiffuseMaterial({ 1.0f, 1, 1 });
	tendrils.at(0).setAmbientMaterial(0.15f);
	tendrils.at(0).setBumpMap("humanSkin02.jpg", 1.2f);
	//tube.loadBumpMapTexture("vascular3_normal2.jpg");
	tendrils.at(0).setTextureScale({ .25f, 0.08f });
	tendrils.at(0).setSpecularMaterial({ 1, 1, 1 });
	tendrils.at(0).setShininess(95);

	/*
	tendrils.push_back(Tube(path, 4, 12, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.55, .81), 20), true, "vascular3.jpg"));
	tendrils.at(1).setDiffuseMaterial({ 1.0f, 1, 1 });
	tendrils.at(1).setAmbientMaterial(0.35f);
	tendrils.at(1).setBumpMap("vascular3.jpg", .45f);
	tendrils.at(1).setTextureScale({ 1, 0.1f });
	tendrils.at(1).setSpecularMaterial({ 1, 1, 1 });
	tendrils.at(1).setShininess(67);
	*/

/*
	theta = 0;
	pts.clear();
	float ht = 300;
	int loops = 10;
	int ptCount = 100;
	for (int i = 0; i < ptCount; i++) {
		float r = 20+random(36, 50);
		pts.push_back(Vec3f(sin(theta) * r, -ht/2.0+ht/ptCount*i, cos(theta) * r));
		theta += TWO_PI / ptCount * loops;
	}
	path = Spline3(pts, 3, false, 1.0);

	tendrils.push_back(Tube(path, 4, 12, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(1.55, 3.21), 90), true, "vascular3.jpg"));
	tendrils.at(2).setDiffuseMaterial({ 1.0f, 1, 1 });
	tendrils.at(2).setAmbientMaterial(0.35f);
	tendrils.at(2).setBumpMap("vascular3.jpg", .95f);
	tendrils.at(2).setTextureScale({ 1, 0.03f });
	tendrils.at(2).setSpecularMaterial({ 1, 1, 1 });
	tendrils.at(2).setShininess(10)*/


	plane = ProtoPlane({}, {}, Dim2f(0, 0), Col4f(1), 1, 1, "linen.jpg");
	plane.setDiffuseMaterial({ 1, 1, 1, 1 });
	//plane.setBumpMap("woodPlank.jpg", .55);
	plane.loadBumpMapTexture("crinkled_paper_normal.jpg");
	plane.setTextureScale({ .5f, .5f });
	plane.setSpecularMaterial({ 1, 1, 1 });
	plane.setShininess(5);

}

void ProtoController::run() {
}

void ProtoController::display() {
	setLight(0, Vec3(sin(radians(getFrameCount()*.25f)) * 2, 0, 10), { 1, 1, 1 });
	beginArcBall();
	push();
	translate(0, 0, -500);
	scale({1920/3.0f, 1080/3.0f, 1});
	//plane.display();
	pop();
	
	push();
	translate(0, 0, -150);
	push();

	rotate(getFrameCount()*PI / 180*.25f, { .25f, 1, .15f });
	push();
	scale(.97f);
	tendrils.at(0).display();
	pop();
	tendrils.at(0).display(WIREFRAME, 3);
	pop();
	rotate(-getFrameCount()*PI / 1080, { 0, 1, 0 });
	//tendrils.at(2).display();
	pop();

	push();
	translate(0, 0, 150);
	scale(1.24);
	rotate(-getFrameCount()*PI / 180*.25f, {.75f, 1, .25f });
	//tendrils.at(1).display();
	pop();

	

	endArcball();

	
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