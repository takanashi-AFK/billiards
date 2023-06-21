#include "Player.h"
#include"Engine/Input.h"
#include"Ball.h"
#include "Engine/Model.h"

/*
�}�E�X�ŕ������w��AL�N���b�N�Ŋm��
L�N���b�N�������ŐL�яk�݂���Q�[�W��power_�̒l��������
�ł�
*/
Player::Player(GameObject* parent)
{
	direction_ = 0.0f;
	power_ = 0.1f;

	hModel_ = Model::Load("1.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.2,0.2,0.2 };
	transform_.position_ = XMFLOAT3(10,10,1 );
	inflatable_ = true;
}

Player::~Player()
{
}

void Player::Update()
{
		MousePos_.x = Input::GetMousePosition().x/85;
		direction_ = MousePos_.x;
		
		if (Input::IsMouseButton(0)) {
		
			if (power_ >= 1.5f)
			{
				powpow_ = -0.01f;
			}

			if (power_ <= 0.1f)
			{
				powpow_ = 0.01;
			}
			power_ += powpow_;
			transform_.scale_ = { power_,power_,power_ };

			if (Input::IsMouseButton(1))
			{
				power_ = 0;
			}
		}


		//power�ɕt�������Q�[�W�ق�����
		if (Input::IsMouseButtonUp(0)){
			XMVECTOR base = XMVectorSet(0, 0, power_, 0);//��]���Ă��Ȃ��Ƃ��Ɉړ�����x�N�g��
			XMMATRIX yrot = XMMatrixRotationY(direction_);//��]�s��������
			XMVECTOR v = XMVector3Transform(base, yrot);//���̉�]�Ńx�N�g���̌�����ς���

			myBall_->AddForce(v);//�J�X��̈ړ��x�N�g��

			power_ = 0.1f;
			transform_.scale_ = { 0.2,0.2,0.2};
			
			if (Length(v) != 0)//�������Ă���
			{
				//������~
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