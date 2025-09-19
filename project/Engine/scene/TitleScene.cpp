#include "TitleScene.h"

void TitleScene::Initialize() {
	sprite = new Sprite();
	sprite->Initialize("monsterBall.png");

	sprite->SetPosition({ 64,64 });
	sprite->SetSize({ 128,128 });

	camera = new Camera();
	camera->SetTranslate({0,0,-30});

	Object3dCommon::GetInstance()->SetDefaultCamera(camera);
	GLTFCommon::GetInstance()->SetDefaultCamera(camera);

	ModelManager::GetInstance()->LoadModel("TwoMesh", ".obj");
	ModelManager::GetInstance()->LoadModel("TwoMesh_Anime", ".gltf",true,false);

	twoMesh = new Object_glTF();
	twoMesh->Initialize();
	twoMesh->SetModelFile("TwoMesh_Anime.gltf");

	TextureManager::GetInstance()->LoadTexture("resource/rostock_laage_airport_4k.dds");

	twoMesh->SetEnvironment("resource/rostock_laage_airport_4k.dds");


	wt.Initialize();
}

void TitleScene::Update() {
	sprite->Update();

	camera->Update();
	twoMesh->Update(wt);

	if (Input::GetInstance()->TriggerKey(DIK_1)) {
		sceneNo = Game;
	}

	wt.UpdateMatrix();
}

void TitleScene::Draw() {
	SpriteCommon::GetInstance()->Command();

	sprite->Draw();

	Object3dCommon::GetInstance()->Command();

	GLTFCommon::GetInstance()->Command();
	twoMesh->Draw();
}

void TitleScene::Finalize() {
	delete sprite;
	delete camera;
	delete twoMesh;
}