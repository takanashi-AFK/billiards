#pragma once
#include "Engine/GameObject.h"
#include<string>

class Ball;
class Player : public GameObject
{
private:
	Ball* myBall_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent) ;
	~Player() ;


	//�X�V
	void Update() override;

	//�`��
	void Draw() override;


	//Player�����삷��ʂ̎擾
	void SetMyBall(Ball* _ball) {myBall_ = _ball;};
};