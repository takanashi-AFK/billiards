#pragma once
#include "Engine/GameObject.h"
#include<string>

//テストシーンを管理するクラス
class Ball : public GameObject
{
	int hModel_;
	int number_;
	XMVECTOR velocity_;

	std::string fileName_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Ball(GameObject* parent);
	~Ball();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	XMFLOAT3 GetNextPosition() { return GetPosition() + velocity_; }


	/// <summary>
	/// ボール番号を指定する関数 ハンドボールは0
	/// </summary>
	void SetNumber(int _no);

	/// <summary>
	/// ボールに力を加える
	/// </summary>
	void AddForce(XMVECTOR f);


	XMVECTOR GetVelocity() { return velocity_; }
};