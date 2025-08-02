#pragma once
#include "WorldTransform.h"
#include "Object3d.h"
#include "MyMath.h"

#include "Levelediter.h"
#include "Player.h"
#include "Enemy.h"

class TestClass {
public:

	TestClass();
	~TestClass();

	void Init();
	void Update();
	void Draw();

private:
	WorldTransform worldTransform_;
	WorldTransform worldTransform2_;
	Object3d* object_ = nullptr;
	Object3d* object2_ = nullptr;
	Camera* camera_ = nullptr;
	bool onLight = false;

	Levelediter levelediter;
	Player* player_ = nullptr;
	Enemy* enemy_ = nullptr;
};
