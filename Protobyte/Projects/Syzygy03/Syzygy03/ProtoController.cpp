/*
Protobyte Library 0.1.6
Ira Greenberg 2016
*/

#include "ProtoController.h"

void ProtoController::init() {
	setBackground({ .125f, .125f, .125f, 1.0f });


	abacusW = 1800;
	abacusH = 1200;
	abacusD = 1800;
	beadGap = 40;

	float beadW = (abacusW - beadGap * 8) / 18;
	float beadH = (abacusH - beadGap * 8) / 18;
	float beadD = (abacusD - beadGap * 8) / 18;
	//t = Toroid(8, 8, beadW/2, beadW*.125);
	//int ringCount, int ringDetail, float ringRadius, float ringThickness, const std::string& textureImageURL, const Vec2f& textureScale)
	t = Toroid(Vec3(), Vec3(), Dim3(), Col4(.20, .155, .25, 1), 32, 32, beadW / 2, beadW / 2 *.125, "metal_plate.jpg", Vec2(.65, 1));
	t.setDiffuseMaterial({ 1.0f, 1, 1 });
	t.setAmbientMaterial(0.15f);
	t.setBumpMap("metal_plate.jpg", 1.2f);
	//t.loadBumpMapTexture("stone_normalMap.jpg");
	//t.setTextureScale({ .25f, 0.08f });
	t.setSpecularMaterial({ 1, 1, 1 });
	t.setShininess(5);
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			for (int k = 0; k<9; k++) {
				float x = -abacusW / 2 + (beadW*2 + beadGap)*i;
				float y = -abacusH / 2 + (beadH*2 + beadGap)*j;
				float z = -abacusD / 2 + (beadD*2 + beadGap)*k;
				vecs[i][j][k] = Vec3(x, y, z);
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
	translate(0, 0, -1300);
	rotate(getFrameCount()*PI/180*.2, Vec3(.0123, .125, .03));
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			push();
			
			for (int k = 0; k<9; k++){ 
				push();
				translate(vecs[i][j][k]);
				rotate(rotAng[i][j][k], Vec3(.2, .3, .15));
				if (j==0 && k == 2) {
					scale(Vec3(1.0+abs(sin(getFrameCount()*16*PI / 180)*2)));
				}
				t.display();
				pop();
				rotAng[i][j][k] += rots[i][j][k];
			}
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