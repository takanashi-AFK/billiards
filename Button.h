#pragma once
#include "Engine/GameObject.h"
#include"Engine/Image.h"
#include "Engine/Text.h"


//�e�X�g�V�[�����Ǘ�����N���X
class Button : public GameObject
{
private:
	int hFoodButtonUpPict_;
	int hFoodButtonDownPict_;
	int hBackButtonUpPict_;
	int hBackButtonDownPict_;
	bool isPushNow;
	XMFLOAT3 MousePos;
	XMFLOAT3 center;


	Transform Food;
	Transform Back;
	Text* pText;
	Text* pText1;
	RECT FDRect;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Button(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	/// <summary>
	/// �񎟌����W����3�������W�ɂ����
	/// </summary>
	void SetPosition(int x,int y);

	bool MouseInArea(XMFLOAT3 mousepos);

	bool Push(bool now) { isPushNow = now; }

	void SetImage(std::string ButtonName,std::string ButtonImage);


};