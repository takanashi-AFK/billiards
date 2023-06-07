#include "Player.h"
#include"Engine/Input.h"
#include"Ball.h"
Player::Player(GameObject* parent)
{
}

Player::~Player()
{
}

void Player::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		myBall_->AddForce(XMVectorSet(0.1f, 0, 0.1f, 0));
	}
}

void Player::Draw()
{

}