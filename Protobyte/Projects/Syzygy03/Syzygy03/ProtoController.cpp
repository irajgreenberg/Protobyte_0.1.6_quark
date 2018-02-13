/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	setBackground({ .125f, .125f, .125f, 1.0f });


	abacusW = 1800;
	abacusH = 1800;
	abacusD = 1200;
	beadGap = 40;

	float beadW = (abacusW - beadGap * 8) / 18;
	float beadH = (abacusH - beadGap * 8) / 18;
	float beadD = (abacusD - beadGap * 8) / 18;
	t = Toroid(Vec3(), Vec3(), Dim3(), Col4(.20, .155, .25, 1), 32, 32, beadW / 2, beadW / 2 *.145, "metal_plate.jpg", Vec2(.65, 1));
	t.setDiffuseMaterial({ 1.0f, 1, 1 });
	t.setAmbientMaterial(0.15f);
	t.setBumpMap("metal_plate.jpg", 1.2f);
	t.setSpecularMaterial({ 1, 1, 1 });
	t.setShininess(5);
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			for (int k = 0; k<9; k++) {
				float x = -abacusW / 2 + (beadW*2 + beadGap)*i;
				float y = -abacusH / 2 + (beadH*2 + beadGap)*j;
				float z = -abacusD / 2 + (beadD*2 + beadGap)*k;
				vecs[i][j][k] = Vec3(x, z, y);
				rots[i][j][k] = random(PI/100);
			}
		}
	}
}

void ProtoController::run() {
}

void ProtoController::display() {
	beginArcBall();
	push();
	translate(0, 0, -1500);
	rotate(getFrameCount()*PI/180*5, Vec3(0, .5, 0
	));
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			push();
			//beginShape(LINES);
			stroke(1.0);

			Spline3 string;
			std::vector<Vec3> pts;
			for (int k = 0; k < 9; k++) {
				push();

				// bead connections
				


				translate(vecs[i][j][k].x, vecs[i][j][k].y, vecs[i][j][k].z);

				pts.push_back(vecs[i][j][k]);
				if (k == 8) {
					pts.push_back(vecs[i][j][k]);
				}
				//rotate(rotAng[i][j][k], Vec3(.2, .3, .15));
				
				if (j==0 && k == 2) {
					//scale(Vec3(1.0+abs(sin(getFrameCount()*16*PI / 180)*2)));
				}
				
				
		
				// toroids
				rotate(PI/4, Vec3(0, 1, 0));
				t.display();

				pop();
				rotAng[i][j][k] += rots[i][j][k];
			}
			string = Spline3(pts, 1, false, .5);
			string.display();
			//endShape();
			pop();
		}
	}
	
	pop();
	endArcBall();
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