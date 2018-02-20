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
	for (int i = 0; i < 9; i++) {
		_stringVibrations[i] = PI / random(.75, 2.25);
		_strumDampings[i] = random(.68, .75);
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				float x = -dim.w / 2 + (beadW * 2 + gap)*i;
				float y = -dim.h / 2 + (beadH * 2 + gap)*j;
				float z = -dim.d / 2 + (beadD * 2 + gap)*k;
				_vecs[i][j][k] = Vec3(x, z, y); // get strummed
				_initVecs[i][j][k] = Vec3(x, z, y); // captuer original position
				_initScales[i][j][k] = Vec3(1);
				_scales[i][j][k] = Vec3(1);
				_rots[i][j][k] = 0.0f;
				_initRots[i][j][k] = 0.0f;
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
		_scales[row][column][i] = _initScales[row][column][i] + Vec3(abs(cos(_theta[i])*_strumForce[i]*.03), abs(sin(_theta[i])*_strumForce[i] * .03), abs(sin(_theta[i])*_strumForce[i]*.03));
		_theta[i] += _stringVibrations[i];
		_rots[row][column][i] = _initRots[row][column][i] + cos(_theta[i])*_strumForce[i] * .03;
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

			app->stroke(1.0);

			Spline3 string;
			std::vector<Vec3> pts;
			for (int k = 0; k < 9; k++) {
				app->push();

				// bead connections
				app->translate(_vecs[i][j][k].x, _vecs[i][j][k].y, _vecs[i][j][k].z);
				app->scale(_scales[i][j][k].x, _scales[i][j][k].y, _scales[i][j][k].z);
				app->rotate(_rots[i][j][k], Vec3(1, 1, 0));
				pts.push_back(_vecs[i][j][k]);
				if (k == 8) {
					pts.push_back(_vecs[i][j][k]);
				}
				
				// toroids
				app->rotate(PI / 4, Vec3(0, 1, 0));
		
				geom->display();

				app->pop();
			}
			string = Spline3(pts, 2, false, .5);
			string.display();

			app->pop();
		}
		_strumForce[i] *= _strumDampings[i];
	}
	strumForce *= strumDamping;
}