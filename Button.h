#pragma once
#include "Engine/GameObject.h"

class Button : public GameObject {
public:
	Button(GameObject* parent);
	~Button();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	bool Finished(); // Buttonが終わったらtrue
	void SetImage(std::string normal, std::string pushed);
	void SetPosition(int x, int y);
	void Push(bool pushed);
	bool MouseInArea(XMFLOAT3 mousePos);
	void SetMovePosition(int toX, int toY, float seconds);
	float easeIncubic(float x);

	/// <summary>
	/// 動いてるならtrue
	/// </summary>
	/// <returns></returns>
	bool IsMoving();

	/// <summary>
	/// 強制的に移動を終了させる
	/// </summary>
	void ForceMoveEnd();
private:
	int hImage;
	int hPush;
	bool pushed;
	XMFLOAT3 center;
	XMFLOAT3 size;

	XMFLOAT3 startPos;//移動開始X座標
	XMFLOAT3 endPos;//移動終了X座標
	float totaltime;//移動時間
	float currentTime; //現在の時間

};