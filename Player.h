#pragma once
#include "Engine/GameObject.h"
#include<string>

class Ball;
class Player : public GameObject
{
private:
	Ball* myBall_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent) ;
	~Player() ;


	//更新
	void Update() override;

	//描画
	void Draw() override;


	//Playerが操作する玉の取得
	void SetMyBall(Ball* _ball) {myBall_ = _ball;};
};