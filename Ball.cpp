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
	if (len < 0.0f) len = 0.0f;
	velocity_ = XMVector3Normalize(velocity_) * len;//vector�̕��������ق�������P�ʉ�

	std::list<Ball*>all = FindGameObjects<Ball>();
	for (std::list <Ball*>::iterator itr = all.begin(); itr != all.end(); itr++) {
		if (*itr == this) continue;
		XMFLOAT3 next = transform_.position_ + velocity_;//�����̈ړ���
		XMFLOAT3 other = (*itr)->GetNextPosition();		 //����̈ړ���
		if (/*next��other������������*/true);

	}

	XMFLOAT3 next = transform_.position_ + velocity_;
	if (next.x >= 35.0f) {
		XMVECTOR n = XMVectorSet(-1, 0, 0, 0);//�E�̕ǂ̖@��(������1)
		n = n * -1;//(�t�ɂ��āA�ǂɌ������x�N�g��)
		XMVECTOR ipvec = XMVector3Dot(velocity_, n);//�M�x�N�g���Ƌt�@���x�N�g���̓��ς��v�Z����
		float ip = XMVectorGetX(ipvec);//�ǂ�����power
		XMVECTOR push = n * ipvec;//�ǂ������x�N�g��
		XMVECTOR th = velocity_ - push;//�ǂɉ����Ă�x�N�g��

		push *= -1;//�ǂ̏_�炩��
		velocity_ = push + th;
		/*XMFLOAT3 f;

			XMStoreFloat3(&f,velocity_);
			f.x *= -1;
		velocity_ = XMLoadFloat3(&f)*/;
	}
	if (next.z >= 19.0f) {
		XMVECTOR n = XMVectorSet(0, 0, 1, 0);//�E�̕ǂ̖@��(������1)
		n = n * -1;//(�t�ɂ��āA�ǂɌ������x�N�g��)
		XMVECTOR ipvec = XMVector3Dot(velocity_, n);//�M�x�N�g���Ƌt�@���x�N�g���̓��ς��v�Z����
		float ip = XMVectorGetX(ipvec);//�ǂ�����power
		XMVECTOR push = n * ipvec;//�ǂ������x�N�g��
		XMVECTOR th = velocity_ - push;//�ǂɉ����Ă�x�N�g��

		push *= -1;//�ǂ̏_�炩��
		velocity_ = push + th;
		/*XMFLOAT3 f;

			XMStoreFloat3(&f,velocity_);
			f.x *= -1;
		velocity_ = XMLoadFloat3(&f)*/;
	}
	if (next.x <= -35.0f) {
		XMVECTOR n = XMVectorSet(1, 0, 0, 0);//�E�̕ǂ̖@��(������1)
		n = n * -1;//(�t�ɂ��āA�ǂɌ������x�N�g��)
		XMVECTOR ipvec = XMVector3Dot(velocity_, n);//�M�x�N�g���Ƌt�@���x�N�g���̓��ς��v�Z����
		float ip = XMVectorGetX(ipvec);//�ǂ�����power
		XMVECTOR push = n * ipvec;//�ǂ������x�N�g��
		XMVECTOR th = velocity_ - push;//�ǂɉ����Ă�x�N�g��

		push *= -1;//�ǂ̏_�炩��
		velocity_ = push + th;
		/*XMFLOAT3 f;

			XMStoreFloat3(&f,velocity_);
			f.x *= -1;
		velocity_ = XMLoadFloat3(&f)*/;
	}
	if (next.z <= -19.0f) {
		XMVECTOR n = XMVectorSet(0, 0, -1, 0);//�E�̕ǂ̖@��(������1)
		n = n * -1;//(�t�ɂ��āA�ǂɌ������x�N�g��)
		XMVECTOR ipvec = XMVector3Dot(velocity_, n);//�M�x�N�g���Ƌt�@���x�N�g���̓��ς��v�Z����
		float ip = XMVectorGetX(ipvec);//�ǂ�����power
		XMVECTOR push = n * ipvec;//�ǂ������x�N�g��
		XMVECTOR th = velocity_ - push;//�ǂɉ����Ă�x�N�g��

		push *= -1;//�ǂ̏_�炩��
		velocity_ = push + th;
		/*XMFLOAT3 f;

			XMStoreFloat3(&f,velocity_);
			f.x *= -1;
		velocity_ = XMLoadFloat3(&f)*/;
	}

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
