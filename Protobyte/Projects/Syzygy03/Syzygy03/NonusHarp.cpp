#include "NonusHarp.h"

using namespace ijg;

NonusHarp::NonusHarp() {
	_init();
}

NonusHarp::NonusHarp(ProtoBaseApp* app, Vec3 pos, Vec3 rot, Dim3 dim, float gap, ProtoGeom3* geom) :
	app(app), pos(pos), rot(rot), dim(dim), gap(gap), geom(geom) {
	_init();
}



void NonusHarp::_init() {

	float beadW = (dim.w - gap * 8) / 18;
	float beadH = (dim.h - gap * 8) / 18;
	float beadD = (dim.d - gap * 8) / 18;
	geom->setDiffuseMaterial({ 1.0f, 1, 1 });
	geom->setAmbientMaterial(0.15f);
	geom->setBumpMap("metal_plate.jpg", 1.2f);
	geom->setSpecularMaterial({ 1, 1, 1 });
	geom->setShininess(5);
	for (int i = 0; i < 9; i++) {
		_stringVibrations[i] = PI / random(.75, 2.25);
		_strumDampings[i] = random(.65, .85);
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				float x = -dim.w / 2 + (beadW * 2 + gap)*i;
				float y = -dim.h / 2 + (beadH * 2 + gap)*j;
				float z = -dim.d / 2 + (beadD * 2 + gap)*k;
				_vecs[i][j][k] = Vec3(x, z, y); // get strummed
				_initVecs[i][j][k] = Vec3(x, z, y); // captuer original position
				_rots[i][j][k] = random(PI / 100);
			}
		}
	}
}

void NonusHarp::vibrate(int row, int column, int layer) {
	_spd[row][column][layer] = Vec3(cos(theta)*strumForce, 0, 0);
	_vecs[row][column][layer] = _initVecs[row][column][layer] + _spd[row][column][layer];
	theta += stringVibration;
}

void NonusHarp::vibrate(int row, int column) {
	for (int i = 0; i < 9; i++) {
		_spd[row][column][i] = Vec3(cos(_theta[i])*_strumForce[i], sin(_theta[i])*_strumForce[i], 0);
		_vecs[row][column][i] = _initVecs[row][column][i] + _spd[row][column][i];
		_theta[i] += _stringVibrations[i];
	}
}

//strike individual node
void NonusHarp::strike(float strumForce) {
	// single node
	this->strumForce = strumForce;
	
	// entire string
	for (int i = 0; i < 9; i++) {
		this->_strumForce[i] = strumForce;
	}
}

//strike entire string
void NonusHarp::strike(std::array<float, 9> strumForce) {
	this->_strumForce = strumForce;
}

void NonusHarp::display() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			app->push();
			//beginShape(LINES);
			app->stroke(1.0);

			Spline3 string;
			std::vector<Vec3> pts;
			for (int k = 0; k < 9; k++) {
				app->push();

				// bead connections
				app->translate(_vecs[i][j][k].x, _vecs[i][j][k].y, _vecs[i][j][k].z);

				pts.push_back(_vecs[i][j][k]);
				if (k == 8) {
					pts.push_back(_vecs[i][j][k]);
				}
				//rotate(rotAng[i][j][k], Vec3(.2, .3, .15));

				if (j == 0 && k == 2) {
					//scale(Vec3(1.0+abs(sin(getFrameCount()*16*PI / 180)*2)));
				}



				// toroids
				app->rotate(PI / 4, Vec3(0, 1, 0));
				geom->display();

				app->pop();
				_rotAng[i][j][k] += _rots[i][j][k];

				
			}
			string = Spline3(pts, 1, false, .5);
			string.display();
			//endShape();
			app->pop();
		}
		_strumForce[i] *= _strumDampings[i];
	}
	strumForce *= strumDamping;
}