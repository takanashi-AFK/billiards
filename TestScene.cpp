#include "TestScene.h"
#include "Ball.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
#include "Player.h"
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
		Player * p = Instantiate<Player>(this);
		Ball* b = Instantiate<Ball>(this);
		b->SetNumber(0);
		p->SetMyBall(b); 

}

//更新
void TestScene::Update()
{
	//めりこみはがし
	std::list <Ball*>balls = FindGameObjects<Ball>();//全部のボールのリスト
	for (auto itr1 = balls.begin(); itr1 != balls.end();itr1++){//ハンドボールが何かに当たっているか、リストの最後まで捜索
		for (auto itr2 = itr1; itr2 != balls.end(); itr2++) {//総当たりのプログラムを書く 総当たりにしたいから半分にしたい
			if (itr1 == itr2)
				continue;
			//自分と比べて大きいほうとじゃないとやらない って文を書いて半分にする
			//itr1とitr2の座標を見て、はがす

			XMVECTOR distance = (*itr1)->GetPosition() - (*itr2)->GetPosition();
			if (Length(distance) < 1.0f * 2.0) {//重なってたら
				float depth = 1.0 * 2.0 - Length(distance);//めり込んでる量
				//めり込み量の半分ずつ移動
				distance = XMVector3Normalize(distance) * depth / 2.0f;
				(*itr1)->SetPosition((*itr1)->GetPosition() + distance);
				(*itr2)->SetPosition((*itr2)->GetPosition() + distance*(-1.0));//手玉と反対方向にひきはがさなきゃいけないから、ベクトルを反対方向に
			}
		}
	}
}

//描画
void TestScene::Draw()
{
	
}

//開放
void TestScene::Release()
{
}
