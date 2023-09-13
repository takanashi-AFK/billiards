#pragma once
#include "Engine/GameObject.h"
#include"Engine/Image.h"
#include "Engine/Text.h"


//テストシーンを管理するクラス
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
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Button(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	/// <summary>
	/// 二次元座標から3次元座標にするよ
	/// </summary>
	void SetPosition(int x,int y);

	bool MouseInArea(XMFLOAT3 mousepos);

	bool Push(bool now) { isPushNow = now; }

	void SetImage(std::string ButtonName,std::string ButtonImage);


};