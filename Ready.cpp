#include <cmath>
#include "Ready.h"

namespace {
	float startX;//�ړ��J�nX���W
	float endX;//�ړ��I��X���W
	float totaltime;//�ړ�����
	float currentTime; //���݂̎���
	int seq_line;//���܂Ȃɂ��Ă邩
	float seq_time;//�V�[�P���X�����s���Ă��鎞��
	enum ACT
	{
		A_SLIDEIN = 1,
		A_WAIT,
		A_SLIDEOUT,
		A_END
	};
	struct Sequence {
		float time;//����
		ACT action;//��邱��
		float param;//�K�v�Ȓl
	};
	Sequence tbl[] = {
		{0.0f,A_SLIDEIN	, 5.0f},//0�b�n�_��5.0����X���C�h�C��
		{3.0f,A_WAIT	, 0.0f},//1�b�҂���
		{4.0f,A_SLIDEOUT,-5.0f},//4�b�n�_��-5.0�փX���C�h�A�E�g
		{5.0f,A_END		, 0.0f}
	};
	ACT currentAction;//�����s���Ă���A�N�V����
	bool canMove;//�ړ��ł��邩
}
//�R���X�g���N
Ready::Ready(GameObject* parent)
	: GameObject(parent, "Ready"),hImage_(-1)
{
	seq_line = -1;
	seq_time = 0.0f;
	canMove = false;
}

//������
void Ready::Initialize()
{
	hImage_ = Image::Load("Ready.png");

	startX = 2.0f;
	endX = 0;
	totaltime = 3.0f;
	currentTime = 0.0f;
}


float easeInCubic(float x)
{
	return x * x * x;
}
//�X�V
void Ready::Update()
{
	seq_time += 1.0f / 60.0f;
	if (seq_time >= tbl[seq_line + 1].time)
	{
		seq_line++;
		switch (tbl[seq_line].action) {
		case A_END:
			KillMe();
			break;
		case A_SLIDEIN:
			startX = tbl[seq_line].param;
			endX = 0;
			totaltime = tbl[seq_line+1].time-seq_time;
			currentTime = 0.0f;
			break;
		case A_WAIT:
			startX = transform_.position_.x;
			endX = transform_.position_.x;
			totaltime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		case A_SLIDEOUT:
			canMove = true;
			startX = transform_.position_.x;
			endX = tbl[seq_line].time - seq_time - 2;
			totaltime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		}
		
	}
	currentTime += 1.0f/60.0f;
	if (currentTime > totaltime)
		currentTime = totaltime;

	float t = currentTime / totaltime;
	float val = easeInCubic(t);

	transform_.position_.x = val * (endX - startX) + startX;
}

//�`��
void Ready::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

//�J��
void Ready::Release()
{
}

bool Ready::Finished()
{
	return canMove;
}
