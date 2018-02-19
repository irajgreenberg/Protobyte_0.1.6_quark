
/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/


#ifndef PROTO_NONUSHARP_H
#define PROTO_NONUSHARP_H

#include <iostream>
#include "ProtoGeom3.h"
#include "ProtoBaseApp.h"
#include "ProtoContext.h"
#include "ProtoOSC.h"
#include <array>

namespace ijg {


	class NonusHarp {

	private:
		void _init();

		Vec3 _initVecs[9][9][9]; 
		Vec3 _vecs[9][9][9];
		Vec3 _spd[9][9][9];
		float _rotAng[9][9][9];
		float _rots[9][9][9];

		// to vibrate an entire string
		float _theta[9];
		//float _strumForce[9];
		std::array<float, 9> _strumForce;

		// fields
		Vec3 pos;
		Vec3 rot;
		Dim3 dim;
		float gap;
		ProtoGeom3* geom;
		ProtoBaseApp* app;
		float theta = 0;
		float strumForce = 0.0;
		float stringVibration = PI/2.75f;
		float strumDamping = .98;

	public:
		//Toroid* t;
		NonusHarp();
		NonusHarp(ProtoBaseApp* app, Vec3 pos, Vec3 rot, Dim3 dim, float gap, ProtoGeom3* geom);
		void vibrate(int row, int column, int layer);
		void vibrate(int row, int column);
		//void vibrate(int row);
		void strike(float strumForce);
		void strike(std::array<float, 9>);

		void display();

	};
}
#endif /* PROTO_NONUSHARP_H */