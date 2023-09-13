#include "TitleScene.h"
#include "Engine/Camera.h"
#include "Engine/Sprite.h"
#include "Engine/Input.h"
#include "Button.h"
#include "Engine/SceneManager.h"
//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

//初期化
void TitleScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(0, 50, 0));
	Camera::SetTarget(XMFLOAT3(0, 0, 0));


	start = Instantiate<Button>(this);
	start->SetImage("Button/GiveUp", "Button/GiveDown");
	start->SetPosition(1920, 360 - 100);
	start->SetMovePosition(640, 360 - 100, 1.0f);
	start->SetScale(0.5, 0.5, 0.5);
	back = Instantiate<Button>(this);
	back->SetImage("Button/BackUp", "Button/BackDown");
	back->SetScale(0.5, 0.5, 0.5);
	back->SetPosition(1920, 360 + 100);
	back->SetMovePosition(640, 360 + 100, 1.0f);
}

//更新
void TitleScene::Update()
{
	if (Input::IsMouseButtonDown(0)) {
		//うごいてるならstop
		bool moving = false;
		if (start->IsMoving())
		{
			start->ForceMoveEnd();
			moving = true;
		}
		if (back->IsMoving())
		{
			back->ForceMoveEnd();
			moving = true;
		}
		if (!moving)
		{
			if (selected == START) {
				SceneManager* scene = dynamic_cast<SceneManager*>(FindObject("SceneManager"));
				scene->ChangeScene(SCENE_ID_TEST);
			}

		}
	}
	XMFLOAT3 pos = Input::GetMousePosition();
	if (start->MouseInArea(pos)) {
		start->Push(true);
		back->Push(false);
		selected = START;
	}
	else if (back->MouseInArea(pos)) {
		back->Push(true);
		start->Push(false);
		selected = BACK;
	}
	else {
		start->Push(false);
		back->Push(false);
		selected = NONE;
	}
}

//描画
void TitleScene::Draw()
{
}

//開放
void TitleScene::Release()
{
}
