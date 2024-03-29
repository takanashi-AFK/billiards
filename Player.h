#pragma once
#include "Engine/GameObject.h"
#include<string>
#include "Gauge.h"

class Ball;
class Player : public GameObject
{
private:
	Ball* myBall_;
	float direction_;//向き(Y回転の角度 ラジアン)
	float power_;//power
	int hModel_;
	float powpow_ = 0.01;
	XMFLOAT3 MousePos_;
	bool flag= true;
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