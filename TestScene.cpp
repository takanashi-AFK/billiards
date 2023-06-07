#include "TestScene.h"
#include "Ball.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
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


}

//�X�V
void TestScene::Update()
{
}

//�`��
void TestScene::Draw()
{
	
}

//�J��
void TestScene::Release()
{
}
