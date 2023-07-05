#include "Player.h"
#include"Engine/Input.h"
#include"Ball.h"
#include "Engine/Model.h"

namespace {
	const float GAUGE_TIME = 0.5;//ゲージが0から満タンになるまでの時間
}

/*
マウスで方向を指定
Lクリック長押しで伸び縮みするゲージ的なものでpower_の値をいじる
どっちの方向に飛んでいくか、もっとわかりやすく棒をのばしたさある
打つ
*/
Player::Player(GameObject* parent)
{
	direction_ = 0.0f;
	power_ = 0.1f;

	hModel_ = Model::Load("1.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.2,0.2,0.2 };
	transform_.position_ = XMFLOAT3(10,10,1 );

}

Player::~Player()
{
}

void Player::Update()
{
		MousePos_.x = Input::GetMousePosition().x/85;
		direction_ = MousePos_.x;
		
		//if (Input::IsMouseButton(0)) {
		//
		//	if (power_ >= 1.5f)
		//	{
		//		powpow_ += -0.01f;
		//	}

		//	if (power_ <= 0.1f)
		//	{
		//		powpow_ += 0.01;
		//	}
		//	power_ += powpow_;
		//	transform_.scale_ = { power_/2,power_/2,power_/2 };
		//	if (Input::IsMouseButton(1))
		//	{
		//		power_ = 0;
		//	}
		//}

		if (Input::IsMouseButton(0)) {

			Gauge* pGauge = (Gauge*)FindObject("Gauge");
			if (flag)
			{
				pGauge->AddValue(Gauge::Max/GAUGE_TIME/60.0f);
				if (pGauge->GetValue() >= Gauge::Min)
				{
					flag = false;
				}
			}
			if (!flag)
			{
				pGauge->AddValue(-Gauge::Max/GAUGE_TIME/60.0f);
				if (pGauge->GetValue() >= Gauge::Max)
				{
					flag = true;
				}
			}
		}

		if (Input::IsMouseButtonUp(0)){
			XMVECTOR base = XMVectorSet(0, 0, power_, 0);//回転していないときに移動するベクトル
			XMMATRIX yrot = XMMatrixRotationY(direction_);//回転行列を作って
			XMVECTOR v = XMVector3Transform(base, yrot);//その回転でベクトルの向きを変える

			myBall_->AddForce(v);//開店後の移動ベクトル

			power_ = 0.1f;
			transform_.scale_ = { 0.2,0.2,0.2};
			
			if (Length(v) != 0)//うごいてたら
			{
				//操作を停止
			}
		}


	
	

	//if (Input::IsKey())
	//{
	//	direction_ -= 0.1f;
	//transform_.rotate_.y = direction_ * 100;
	//}
	//if (Input::IsKey(DIK_D))
	//{
	//	direction_ += 0.1f;
	//	transform_.rotate_.y = direction_*100;
	//}

}

void Player::Draw()
{
	XMVECTOR base = XMVectorSet(0, 0, 1.2f, 0);
	XMMATRIX yrot = XMMatrixRotationY(direction_);
	XMVECTOR v = XMVector3Transform(base, yrot);

	transform_.position_ = myBall_->GetPosition() + v;

	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}