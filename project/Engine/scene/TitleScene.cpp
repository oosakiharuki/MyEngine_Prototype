#include "TitleScene.h"

void TitleScene::Initialize() {
	sprite = new Sprite();
	sprite->Initialize("monsterBall.png");

	sprite->SetPosition({ 64,64 });
	sprite->SetSize({ 128,128 });

	camera = new Camera();
	camera->SetTranslate({0,0,-30});

	Object3dCommon::GetInstance()->SetDefaultCamera(camera);

	ModelManager::GetInstance()->LoadModel("TwoMesh", ".obj");

	twoMesh = new Object3d();
	twoMesh->Initialize();
	twoMesh->SetModelFile("TwoMesh.obj");

	wt.Initialize();
}

void TitleScene::Update() {
	sprite->Update();

	camera->Update();
	twoMesh->Update();

	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		sceneNo = Game;
	}

	wt.UpdateMatrix();
}

void TitleScene::Draw() {
	SpriteCommon::GetInstance()->Command();

	sprite->Draw();

	Object3dCommon::GetInstance()->Command();
	twoMesh->Draw(wt);
}

void TitleScene::Finalize() {
	delete sprite;
	delete camera;
	delete twoMesh;
}