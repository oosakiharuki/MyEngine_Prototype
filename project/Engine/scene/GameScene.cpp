#include "GameScene.h"

using namespace MyMath;

void GameScene::Initialize() {
	
	ModelManager::GetInstance()->LoadModel("terrain");
	ModelManager::GetInstance()->LoadModel("sphere");
	ModelManager::GetInstance()->LoadModel("playerHead");
	ModelManager::GetInstance()->LoadModel("enemy");


	camera = new Camera();

	//levelediter = new Levelediter();
	levelediter.LoadLevelediter();

	cameraRotate = levelediter.GetLevelData()->cameraInit.rotation;
	cameraTranslate = levelediter.GetLevelData()->cameraInit.translation;
	
	camera->SetRotate(cameraRotate);
	camera->SetTranslate(cameraTranslate);

	Object3dCommon::GetInstance()->SetDefaultCamera(camera);
	ParticleCommon::GetInstance()->SetDefaultCamera(camera);


	player_ = new Player();
	player_->Initialize();

	//プレイヤー配置データがあるときプレイヤーを配置
	if (!levelediter.GetLevelData()->players.empty()) {
		auto& playerData = levelediter.GetLevelData()->players[0];
		player_->SetTranslate(playerData.translation);
		player_->SetRotate(playerData.rotation);
		player_->SetAABB(playerData.colliderAABB);
	}


	if (!levelediter.GetLevelData()->spawnEnemies.empty()) {
		for (auto& enemyData : levelediter.GetLevelData()->spawnEnemies) {
			Enemy* enemy = new Enemy();
			enemy->Initialize();
			enemy->SetTranslate(enemyData.translation);
			enemy->SetRotate(enemyData.rotation);
			enemy->SetAABB(enemyData.colliderAABB);
			enemies.push_back(enemy);
		}
	}


}

void GameScene::Update() {

	if (Input::GetInstance()->PushKey(DIK_0)) {
		OutputDebugStringA("Hit 0\n");
	}

	if (Input::GetInstance()->TriggerKey(DIK_1)) {
		OutputDebugStringA("Hit 1\n");
	}

	//今回はしない
	//if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
	//	sceneNo = Title;
	//}

	camera->Update();

	player_->Update();

	for (auto& enemy : enemies) {
		enemy->Update();

		if (IsCollisionAABB(player_->GetAABB(), enemy->GetAABB())) {
			enemy->IsHit();
		}
	}


#ifdef  USE_IMGUI

	ImGui::Begin("camera");
	ImGui::Text("ImGuiText");

	//カメラ
	ImGui::InputFloat3("cameraTranslate", &cameraTranslate.x);
	ImGui::SliderFloat3("cameraTranslateSlider", &cameraTranslate.x, -30.0f, 30.0f);

	ImGui::InputFloat3("cameraRotate", &cameraRotate.x);
	ImGui::SliderFloat("cameraRotateX", &cameraRotate.x, -360.0f, 360.0f);
	ImGui::SliderFloat("cameraRotateY", &cameraRotate.y, -360.0f, 360.0f);
	ImGui::SliderFloat("cameraRotateZ", &cameraRotate.z, -360.0f, 360.0f);
	camera->SetRotate(cameraRotate);
	camera->SetTranslate(cameraTranslate);

	ImGui::End();

#endif //  USE_IMGUI
}

void GameScene::Draw() {

	//モデル描画処理
	Object3dCommon::GetInstance()->Command();

	player_->Draw();
	for (auto& enemy : enemies) {
		enemy->Draw();
	}

	//パーティクル描画処理
	ParticleCommon::GetInstance()->Command();


	//スプライト描画処理(UI用)
	SpriteCommon::GetInstance()->Command();

}

void GameScene::Finalize() {
	delete camera;
	delete player_;
	for (auto& enemy : enemies) {
		delete enemy;
	}
}
