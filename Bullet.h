#pragma once

class Bullet {
public:
	int x_[5];
	int y_[5];
	int radius_[5];
	int speed_[5];
	int isShot_[5];
	int time_;

	Bullet();

	void Update();
	void Draw();
};
