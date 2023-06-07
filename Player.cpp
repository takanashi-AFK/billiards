#include "Player.h"
#include"Engine/Input.h"
#include"Ball.h"
#include "Engine/Model.h"
Player::Player(GameObject* parent)
{
	direction_ = 0.0f;
	power_ = 0.3f;

	hModel_ = Model::Load("1.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.2,0.2,0.2 };
	transform_.position_ = {0,0,1};
}

Player::~Player()
{
}

void Player::Update()
{

	if (Input::IsKey(DIK_A))
		direction_ -= 0.1f;

	if (Input::IsKey(DIK_D))
		direction_ += 0.1f;

	if (Input::IsKeyDown(DIK_SPACE))
	{

		XMVECTOR base = XMVectorSet(0, 0, power_, 0);//回転していないときに移動するベクトル
		XMMATRIX yrot = XMMatrixRotationY(direction_);//回転行列を作って
		XMVECTOR v = XMVector3Transform(base, yrot);//その回転でベクトルの向きを変える

		myBall_->AddForce(v);//開店後の移動ベクトル
	}
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