#include "GameScene.h"

void GameScene::Initialize() {
	
	ModelManager::GetInstance()->LoadModel("terrain");
	ModelManager::GetInstance()->LoadModel("sphere");


	camera = new Camera();
	//Vector3 cameraRotate = { 1.4f,0.0f,0.0f };
	//Vector3 cameraTranslate = { 0.0f,30.0f,-8.0f };
	cameraRotate = { 0.3f,0.0f,0.0f };
	cameraTranslate = { 0.0f,5.0f,-16.0f };

	camera->SetRotate(cameraRotate);
	camera->SetTranslate(cameraTranslate);
	
	Object3dCommon::GetInstance()->SetDefaultCamera(camera);
	ParticleCommon::GetInstance()->SetDefaultCamera(camera);

 	testClass = new TestClass();
 	testClass->Init();

	spriteUI = new Sprite();
	spriteUI->Initialize("uvChecker.png");
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

	testClass->Update();

	camera->Update();

	spriteUI->SetPosition({ 10,10 });
	spriteUI->SetSize(Vector2(128, 128));
	spriteUI->Update();

#ifdef  USE_IMGUI

	//ここにテキストを入れられる

	//開発用UIの処理
	//ImGui::ShowDemoWindow();

	ImGui::Begin("camera");
	ImGui::Text("ImGuiText");

	//カメラ
	ImGui::SliderFloat3("cameraTranslate", &cameraTranslate.x, -30.0f, 30.0f);

	ImGui::SliderFloat("cameraRotateX", &cameraRotate.x, -10.0f, 10.0f);
	ImGui::SliderFloat("cameraRotateY", &cameraRotate.y, -10.0f, 10.0f);
	ImGui::SliderFloat("cameraRotateZ", &cameraRotate.z, -10.0f, 10.0f);
	camera->SetRotate(cameraRotate);
	camera->SetTranslate(cameraTranslate);

	ImGui::End();

#ifdef _DEBUG

	ImGui::Begin("TestTexture");

	ImGui::InputFloat2("VertexModel", &position.x);
	ImGui::SliderFloat2("SliderVertexModel", &position.x, 0.0f, 600.0f);

	ImGui::End();
	spriteUI->SetPosition(position);
#endif // _DEBUG
#endif //  USE_IMGUI
}

void GameScene::Draw() {

	//モデル描画処理
	Object3dCommon::GetInstance()->Command();

	testClass->Draw();

	//パーティクル描画処理
	ParticleCommon::GetInstance()->Command();

	//particle->Draw();
	//particle2->Draw();

	//スプライト描画処理(UI用)
	SpriteCommon::GetInstance()->Command();

	spriteUI->Draw();
}
void GameScene::Finalize() {
	
	delete camera;
	delete testClass;

	delete spriteUI;
}
