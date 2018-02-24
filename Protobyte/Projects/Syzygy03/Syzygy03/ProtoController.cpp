/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	setBackground({ 0, 0, 0, 1.0f });
	oscObj = new ProtoOSC();  // on heap
	oscObj->receive(12002);

	lt0Radius = 1500.0f;

	abacusW = 2400;
	abacusH = 1400;
	abacusD = 2500;
	beadGap = 80;
	float beadW = (abacusW - beadGap * 8) / 18;
	float beadH = (abacusH - beadGap * 8) / 18;
	float beadD = (abacusD - beadGap * 8) / 18;

	i = new ProtoIcosahedron(Vec3(), Vec3(), Dim3(130), Col4(.02f, .02f, .09f, 1), "white.jpg", { 1, 1 });
	//i->setTextureScale({ 1, 1 });
	i->setDiffuseMaterial({ 1, 1, 1 });
	i->setAmbientMaterial(0.15f);
	i->setBumpMap("white.jpg", .95f);
	i->setSpecularMaterial({ 1, 1, .95f });
	i->setShininess(20);

	///const Vec3& pos, const Dim3f& size, int detail, const std::string& textureImageURL, Registration reg
	//c = new ProtoCylinder({},{20, 50, 20}, 32, Col4(.02f, .02f, .09f, 1), "shipPlate_yellow.jpg", ProtoCylinder::LEFT);
	//c->setDiffuseMaterial({ 1, 1, 1 });
	//c->setAmbientMaterial(0.15f);
	//c->setBumpMap("corroded.jpg", .95f);
	//c->setSpecularMaterial({ 1, 1, .95f });
	//c->setShininess(20);


	//t = new Toroid(Vec3(), Vec3(), Dim3(), Col4(.095f, .01f, .02f, 1.0f), 32, 32, beadW / 6, beadW / 4 * .245, "metalic.jpg", Vec2(.25f, .125f)); 
	t = new Toroid(Vec3(), Vec3(), Dim3(), Col4(.2f, .01f, .15f, 1.0f), 32, 32, beadW / 6, beadW / 4 * .245, "shipPlate_yellow.jpg", Vec2(.25f, .125f));
	t->setDiffuseMaterial({ 1, 1, 1 });
	t->setAmbientMaterial(0.15f);
	t->setBumpMap("corroded_red.jpg", .95f);
	t->setSpecularMaterial({ 1, 1, .75f });
	t->setShininess(12);

	s = new ProtoSphere(Vec3(), Vec3(), Dim3(30), Col4(.02f, .02f, .09f, 1), "ship_plate_rainbow.jpg", 1, 32, 32);
	s->setTextureScale({ 1, 1 });
	s->setDiffuseMaterial({ 1, 1, 1 });
	s->setAmbientMaterial(0.15f);
	s->setBumpMap("corroded.jpg", .95f);
	s->setSpecularMaterial({ 1, 1, .95f });
	s->setShininess(20);

	b = new ProtoBlock(Vec3(), Vec3(), Dim3(20), Col4(.01f, .09f, .02f, 1.0f), "metalic.jpg");
	b->setTextureScale({ 1, 1 });
	b->setDiffuseMaterial({ 1, 1, 1 });
	b->setAmbientMaterial(0.15f);
	b->setBumpMap("corroded.jpg", .95f);
	b->setSpecularMaterial({ 1, 1, .95f });
	b->setShininess(5);

	harp = new NonusHarp(this, {}, {}, { abacusW, abacusH, abacusD }, beadGap, b);
	
	_x = 150;
	_y = 1500;
	_z = -5500;
	//_z = -2400;
	tranSpdInterval = .05f;
	rotSpdInterval = .01f;
	killDamping = .95f;
}

void ProtoController::run() {

}

void ProtoController::display() {
	//setLight(0, Vec3(sin(getFrameCount()*PI/180.0f*2)* lt0Radius, 900, cos(getFrameCount()*PI / 180.0f*2)* lt0Radius), { 1, .70f, 1 });
	//setLight(1, Vec3(0, sin(getFrameCount()*PI / 180.0f * 20)* lt0Radius, cos(getFrameCount()*PI / 180.0f * 20)* lt0Radius), { 1, .75f, 1 });
	setLight(0, Vec3(sin(getFrameCount()*PI / 180.0f * 2)* lt0Radius, 900, cos(getFrameCount()*PI / 180.0f * 2)* lt0Radius), { 1, .70f, 1 });
	//setLight(1, Vec3(sin(getFrameCount()*PI / 180.0f * 20)* lt0Radius, 900, cos(getFrameCount()*PI / 180.0f * 20)* lt0Radius), { 1, .75f, 1 });
	setLight(2, Vec3(600, cos(radians(getFrameCount()*2.0f)) * -1500, sin(radians(getFrameCount()*2.0f)) * 100), { 1, .75f, .75f });

	setLight(3, Vec3(sin(getFrameCount()*PI / 180.0f * 2)* lt0Radius, cos(getFrameCount()*PI / 180.0f * 2)* lt0Radius, 900), { 1, .5f, 0 });

	// add light

	beginArcBall();
	push();

	translate(_x, _y, _z);


	// x-axis 
	rotate(_xR*PI / 180, Vec3(1, 0, 0));

	// y-axis
	rotate(_yR*PI / 180, Vec3(0, 1, 0));

	// z-axis
	rotate(_zR*PI / 180, Vec3(0, 0, 1));

	scale(.65);
	harp->display();

	harp->vibrate();
	harp->strike(oscObj->getMsg().amp * 100, oscObj->getMsg().id);

	pop();
	endArcBall();

	// translation values
	_x += _spdX;
	_y += _spdY;
	_z += _spdZ;

	// rotation values
	_xR += _spdRotX;
	_yR += _spdRotY;
	_zR += _spdRotZ;


}

// Key and Mouse Events
void ProtoController::keyPressed() {

	// reset and kill
	if (key == 82){
		_x = 0.0;
		_y = 1500;
		_z = -5500;
		_xR = 0;
		_yR = 0;
		_zR = 0;
		_spdX = 0;
		_spdY = 0;
		_spdZ = 0;
		_spdRotX = 0;
		_spdRotY = 0;
		_spdRotZ = 0;
	}

	// safety switch
	if (key == 75) {
		_spdX *= .95;
		_spdY *= .95;
		_spdZ *= .95;
		_spdRotX *= .95;
		_spdRotY *= .95;
		_spdRotZ *= .95;
	}

	// interactive controls
	switch (key) {
		trace(key);
	case 49:
		harp->setGeom(b);
		break;
	case 50:
		harp->setGeom(s);
		break;
	case 51:
		harp->setGeom(t);
		break;
	default:
		break;
	}

	switch (key) {
	case 262:
		_spdX+= tranSpdInterval;
		break;
	case 263:
		_spdX -= tranSpdInterval;
		break;
	default:
		break;
	}

	switch (key) {
	case 264:
		_spdY -= tranSpdInterval;
		break;
	case 265:
		_spdY += tranSpdInterval;
		break;
	default:
		break;
	}

	// z-axis
	switch (key) {
	case 81:
		_spdZ -= tranSpdInterval;
		break;
	case 65:
		_spdZ += tranSpdInterval;
		break;
	default:
		break;
	}


	// rotations
	switch (key) {
	case 46:
		_spdRotX += rotSpdInterval;
		break;
	case 47:
		_spdRotX -= rotSpdInterval;
		break;
	default:
		break;
	}

	switch (key) {
	case 59:
		_spdRotY -= rotSpdInterval;
		break;
	case 39:
		_spdRotY += rotSpdInterval;
		break;
	default:
		break;
	}

	switch (key) {
	case 91:
		_spdRotZ += rotSpdInterval;
		break;
	case 93:
		_spdRotZ -= rotSpdInterval;
		break;
	default:
		break;
	}
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