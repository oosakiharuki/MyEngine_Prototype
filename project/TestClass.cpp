#include "TestClass.h"
#include "TextureManager.h"
#include "ImGuiManager.h"
#include "Input.h"

using namespace MyMath;

TestClass::TestClass(){}

TestClass::~TestClass() {
	delete object_;
	delete object2_;
}

void TestClass::Init() {
	worldTransform_.Initialize();
	worldTransform2_.Initialize();

	object_ = new Object3d();
	object_->Initialize();
	object_->SetModelFile("terrain");
	worldTransform_.scale_ = { 0.5f,0.5f,0.5f };

	object2_ = new Object3d();
	object2_->Initialize();
	object2_->SetModelFile("sphere");
}

void TestClass::Update() {

	onLight = false;

#ifdef _DEBUG

	ImGui::Begin("TestModel");

	ImGui::InputFloat3("VertexModel", &worldTransform_.translation_.x);
	ImGui::SliderFloat3("SliderVertexModel", &worldTransform_.translation_.x, -5.0f, 5.0f);

	ImGui::InputFloat3("RotateModel", &worldTransform_.rotation_.x);
	ImGui::SliderFloat3("SliderRotateModel", &worldTransform_.rotation_.x, -10.0f, 10.0f);

	ImGui::InputFloat3("ScaleModel", &worldTransform_.scale_.x);
	ImGui::SliderFloat3("SliderScaleModel", &worldTransform_.scale_.x, 0.5f, 5.0f);

	ImGui::End();

	ImGui::Begin("TestModel2");

	ImGui::InputFloat3("VertexModel", &worldTransform2_.translation_.x);
	ImGui::SliderFloat3("SliderVertexModel", &worldTransform2_.translation_.x, -5.0f, 5.0f);

	ImGui::InputFloat3("RotateModel", &worldTransform2_.rotation_.x);
	ImGui::SliderFloat3("SliderRotateModel", &worldTransform2_.rotation_.x, -10.0f, 10.0f);

	ImGui::InputFloat3("ScaleModel", &worldTransform2_.scale_.x);
	ImGui::SliderFloat3("SliderScaleModel", &worldTransform2_.scale_.x, 0.5f, 5.0f);

	ImGui::End();

#endif // _DEBUG

	object_->LightSwitch(onLight);
	object2_->LightSwitch(onLight);

	worldTransform_.rotation_.y += 0.005f;

	worldTransform_.UpdateMatrix();
	worldTransform2_.UpdateMatrix();
}


void TestClass::Draw() {
	object_->Draw(worldTransform_);
	object2_->Draw(worldTransform2_);
}
