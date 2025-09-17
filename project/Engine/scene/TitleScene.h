#pragma once
#include "Sprite.h"
#include "Object3d.h"
#include "Object_glTF.h"
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
	Object_glTF* twoMesh;
	WorldTransform wt;
	Camera* camera;
};