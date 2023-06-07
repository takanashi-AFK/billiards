#include "TestScene.h"
#include "Ball.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
//コンストラク
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(0, 50, 0));
	Camera::SetTarget(XMFLOAT3(0, 0, 0));

		for (int i = 0; i < 9; i++) {
			Ball* b = Instantiate <Ball>(this);
			b->SetNumber(i + 1);//ここでボール指定 1~9まで
			b->SetPosition((i - 4) * 1.4, 0, (i - 4) * 1.4);
		}


}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
	
}

//開放
void TestScene::Release()
{
}
