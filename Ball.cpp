#include "Ball.h"
#include"Engine/Model.h"
#include<string>
//�R���X�g���N�^
Ball::Ball(GameObject* parent)
	: GameObject(parent, "Ball"),hModel_(-1)
{
	velocity_ = XMVectorSet(0,0,0,0);//���x�x�N�g�� ��f���ꂸ�i��ł�
}

Ball::~Ball()
{
	if (hModel_ > 0)
		Model::Release(hModel_);
}


//������
void Ball::Initialize()
{
	
}

//�X�V
void Ball::Update()
{
	XMVECTOR lenVec = XMVector3Length(velocity_);//�����擾
	float len = XMVectorGetX(lenVec);
	len -= 0.001f;//�������疈f0.001�������Č�������
	velocity_ = XMVector3Normalize(velocity_) * len;//vector�̕��������ق�������P�ʉ�
	transform_.position_ += velocity_;
	
}

//�`��
void Ball::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Ball::Release()
{
}

void Ball::SetNumber(int _no)
{
	number_ = _no;
	fileName_ = (_no+".fbx");
	hModel_ = Model::Load("1.fbx");//�����Ŏw�肷�邱�ƂŃ��f���̍����ւ����ȒP�ɂȂ�
	assert(hModel_ >= 0);
}

void Ball::AddForce(XMVECTOR f)
{
	velocity_+= f;

}
