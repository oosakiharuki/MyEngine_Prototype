#pragma once

#include "Sprite.h"
#include "Object3d.h"
#include "particle.h" 
#include "Audio.h"
#include "MyMath.h"
#include "Framework.h"
#include "IScene.h"

#include "TestClass.h"

class GameScene : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;
private:


	Camera* camera = nullptr;
	Vector3 cameraRotate = { 0.0f,0.0f,0.0f };
	Vector3 cameraTranslate = { 0.0f,0.0f,-15.0f };

	//std::vector<Sprite*> sprites;
	//std::vector<Object3d*> objects;
	Sprite* spriteUI;
	Vector2 position = { 0,0 };

	//Particle* particle = nullptr;
	//Particle* particle2 = nullptr;

	//Audio* audio2 = nullptr;
	//int audioHandle2 = 0;


	////描画させるもの
	//bool IsSphere = true;
	//bool IsModel[2] = { true,true };
	//bool IsSprite = true;


	//ゲームループ終了(while文から抜ける)
	bool isRequst = false;

	XINPUT_STATE state,preState;

	//WorldTransform worldTransform;
	//WorldTransform worldTransform2;


	TestClass* testClass = nullptr;
};