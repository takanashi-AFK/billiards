#include "TestScene.h"
#include "Ball.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
#include "Player.h"
//�R���X�g���N
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(0, 50, 0));
	Camera::SetTarget(XMFLOAT3(0, 0, 0));

		for (int i = 0; i < 9; i++) {
			Ball* b = Instantiate <Ball>(this);
			b->SetNumber(i + 1);//�����Ń{�[���w�� 1~9�܂�
			b->SetPosition((i - 4) * 1.4, 0, (i - 4) * 1.4);
		}
		Player * p = Instantiate<Player>(this);
		Ball* b = Instantiate<Ball>(this);
		b->SetNumber(0);
		p->SetMyBall(b); 

}

//�X�V
void TestScene::Update()
{
	//�߂肱�݂͂���
	std::list <Ball*>balls = FindGameObjects<Ball>();//�S���̃{�[���̃��X�g
	for (auto itr1 = balls.begin(); itr1 != balls.end();itr1++){//�n���h�{�[���������ɓ������Ă��邩�A���X�g�̍Ō�܂ő{��
		for (auto itr2 = itr1; itr2 != balls.end(); itr2++) {//��������̃v���O���������� ��������ɂ��������甼���ɂ�����
			if (itr1 == itr2)
				continue;
			//�����Ɣ�ׂđ傫���ق��Ƃ���Ȃ��Ƃ��Ȃ� ���ĕ��������Ĕ����ɂ���
			//itr1��itr2�̍��W�����āA�͂���

			XMVECTOR distance = (*itr1)->GetPosition() - (*itr2)->GetPosition();
			if (Length(distance) < 1.0f * 2.0) {//�d�Ȃ��Ă���
				float depth = 1.0 * 2.0 - Length(distance);//�߂荞��ł��
				//�߂荞�ݗʂ̔������ړ�
				distance = XMVector3Normalize(distance) * depth / 2.0f;
				(*itr1)->SetPosition((*itr1)->GetPosition() + distance);
				(*itr2)->SetPosition((*itr2)->GetPosition() + distance*(-1.0));//��ʂƔ��Ε����ɂЂ��͂����Ȃ��Ⴂ���Ȃ�����A�x�N�g���𔽑Ε�����
			}
		}
	}
}

//�`��
void TestScene::Draw()
{
	
}

//�J��
void TestScene::Release()
{
}
