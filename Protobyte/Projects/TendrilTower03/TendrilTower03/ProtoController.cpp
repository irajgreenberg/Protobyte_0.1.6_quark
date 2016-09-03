/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	setBackground({ .125f, .125f, .125f, 1.0f });
	shadowsOn();
	setShadowSharpness(512, 512);


	plane = ProtoPlane({}, {}, Dim2f(0, 0), Col4f(1), 1, 1, "linen.jpg");
	plane.setDiffuseMaterial({ 1, 1, 1, 1 });
	//plane.setBumpMap("woodPlank.jpg", .55);
	plane.loadBumpMapTexture("crinkled_paper_normal.jpg");
	plane.setTextureScale({ .5f, .5f });
	plane.setSpecularMaterial({ 1, 1, 1 });
	plane.setShininess(5);


	std::vector<Vec3> pts;
	float ht = 65.0f;
	float theta = 0;
	int ptCount = 8;
	for (int i = 0; i < ptCount; i++) {
		float r = 6 + random(3, 8);
		pts.push_back(Vec3f(sin(theta) * r, -ht / 2.0 + ht / ptCount*i*1.25f, cos(theta) * random(r, r + .25)));
		theta += TWO_PI / ptCount*1.5;
	}
	Spline3 path(pts, 6, false, 1.0);

	//tendrils.push_back(Tube(path, 18, 16, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(random(.325, .435), random(.456, 2.875)), 1), true, "humanSkin01.jpg"));

	tendrils.push_back(Tube(path, 18, 16, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.001, 1.65f), 1), true, "humanSkin02.jpg"));
	tendrils.at(0).setPerturbation({ .08f, .04f, .06f });
	tendrils.at(0).setDiffuseMaterial({ 1.0f, 1, 1 });
	tendrils.at(0).setAmbientMaterial(0.15f);
	tendrils.at(0).setBumpMap("humanSkin02.jpg", 1.2f);
	//tube.loadBumpMapTexture("vascular3_normal2.jpg");
	tendrils.at(0).setTextureScale({ .25f, 0.08f });
	tendrils.at(0).setSpecularMaterial({ 1, 1, 1 });
	tendrils.at(0).setShininess(95);

	

	// create darts
	// use organism ht
	const int DART_COUNT = 40;
	const int rots = 6, waves = 3;
	float r1 = 80, r2 = ht;
	float th1 = 0, th2 = PI/2.0f;

	std::vector<Face3> faces = tendrils.at(0).getFaces();
	for (int i = 0; i < DART_COUNT; ++i) {
		darts.push_back({ sin(th1)*r1, sin(th2)*r2 , cos(th1)*r1 });
		Vec3 ds = darts.at(i);
		ds.normalize();
		ds *= 10;
		dartsSpd.push_back({ ds.x, ds.y, ds.y });
		th1 += TWO_PI / DART_COUNT * rots;
		th2 += PI / DART_COUNT *.9f;
	}
	//throw darts
	for (int i = 0; i < DART_COUNT; ++i) {
		//if (fabs(dartsSpd.at(i).mag()) > 1) {
		for (int j = 0; j < faces.size(); ++j) {
				while (darts.at(i).dist(faces.at(j).getCentroid()) > 90) {
					darts.at(i) *= .98f;
				}
			}
		//}
	}

	path = Spline3(darts, 3, false, 1.0);

	tendrils.push_back(Tube(path, 4, 5, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, Tup2(.1f, .2), 3), true, "metal_flaky_blue.jpg"));
	tendrils.at(1).setDiffuseMaterial({ 1.0f, 1, 1 });
	tendrils.at(1).setAmbientMaterial(0.35f);
	tendrils.at(1).setBumpMap("metal_flaky_blue.jpg", .95f);
	tendrils.at(1).setTextureScale({ 1, 0.001f });
	tendrils.at(1).setSpecularMaterial({ 1, 1, 1 });
	tendrils.at(1).setShininess(10);

}

void ProtoController::run() {
}

void ProtoController::display() {
	setLight(0, Vec3(sin(radians(getFrameCount()*.25f)) * 2, 0, 10), { 1, 1, 1 });
	beginArcBall();
	push();
	translate(0, 0, -500);
	scale({ 1920 / 3.0f, 1080 / 3.0f, 1 });
	//plane.display();
	pop();

	push();
	translate(0, 0, -150);
	push();

	rotate(getFrameCount()*PI / 180 * .25f, { .25f, 1, .15f });
	push();
	scale(.97f);
	tendrils.at(0).display();
	pop();
	tendrils.at(0).display(WIREFRAME, 3);
	tendrils.at(1).display();
	pop();
	rotate(-getFrameCount()*PI / 1080, { 0, 1, 0 });
	//tendrils.at(2).display();
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