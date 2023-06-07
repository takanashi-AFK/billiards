#include "Ball.h"
#include"Engine/Model.h"
#include<string>
//�R���X�g���N�^
Ball::Ball(GameObject* parent)
	: GameObject(parent, "Ball"),hModel_(-1)
{
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
	std::to_string(number_);
	fileName_ = (number_+".fbx");
	hModel_ = Model::Load(fileName_);//�����Ŏw�肷�邱�ƂŃ��f���̍����ւ����ȒP�ɂȂ�
	assert(hModel_ >= 0);
}
