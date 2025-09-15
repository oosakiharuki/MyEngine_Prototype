#pragma once
#include "Sprite.h"
#include "Object3d.h"
#include "Framework.h"
#include "IScene.h"

class TitleScene : public IScene{
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;
private:
	Sprite* sprite;
	Object3d* twoMesh;
	WorldTransform wt;
	Camera* camera;
};