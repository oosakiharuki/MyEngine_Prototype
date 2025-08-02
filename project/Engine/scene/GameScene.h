#pragma once

#include "Sprite.h"
#include "Object3d.h"
#include "Particle.h" 
#include "Audio.h"
#include "MyMath.h"
#include "Framework.h"
#include "IScene.h"

#include "Levelediter.h"
#include "Player.h"
#include "Enemy.h"

class GameScene : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;
private:
	
	XINPUT_STATE state,preState;

	Camera* camera = nullptr;
	Vector3 cameraRotate = { 0.0f,0.0f,0.0f };
	Vector3 cameraTranslate = { 0.0f,0.0f,-15.0f };

	Levelediter levelediter;
	Player* player_ = nullptr;
	std::vector<Enemy*> enemies;
};