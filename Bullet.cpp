#include "Bullet.h"


Bullet::Bullet() {
	for (int i = 0; i < 5; ++i) {
		x_[i] = 0;
		y_[i] = 0;
		radius_[i] = 10;
		speed_[i] = 10;
		isShot_[i] = false;
	}
	time_ = 0;
}

void Bullet::Update() {

	for (int i = 0; i < 5; ++i) {
		if (isShot_[i] == 1) {
			y_[i] -= speed_[i];

			if (radius_[i] + y_[i] <= -10.0f) {
				isShot_[i] = false;
			}
		}
	}
}

void Bullet::Draw() {

	//for (int i = 0; i < 5; i++) {
	//	if (isShot_[i] == 1) {
	//		Novice::DrawEllipse(x_[i], y_[i], radius_[i], radius_[i], 0.0f, WHITE, kFillModeSolid);
	//	}
	//}

}