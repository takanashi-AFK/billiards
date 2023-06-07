#pragma once
#include "Engine/GameObject.h"
#include<string>

//�e�X�g�V�[�����Ǘ�����N���X
class Ball : public GameObject
{
	int hModel_;
	int number_;
	

	std::string fileName_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Ball(GameObject* parent);
	~Ball();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;


	/// <summary>
	/// �{�[���ԍ����w�肷��֐� �n���h�{�[����0
	/// </summary>
	void SetNumber(int _no);
};