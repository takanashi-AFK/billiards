#pragma once
#include "Engine/GameObject.h"
#include"Engine/Image.h"


//�e�X�g�V�[�����Ǘ�����N���X
class Ready : public GameObject
{
private:
	int hImage_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Ready(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	bool Finished();
};