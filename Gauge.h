#pragma once
#include "Engine/GameObject.h"


class Gauge : public GameObject
{
private:
	int hPictGauge_;
	int hPictFrame_;
	const float maxHp_ = 1.0f;
	float nowHp_;
	float animHp_;
	int ImageHeight_;
	int ImageWidth_;

public:
	static constexpr float Min = 0.0f;
	static constexpr float Max = 1.0f;
	Gauge(GameObject* parent);

	void Initialize() override;
	void Update() override;
	void Draw() override; 
	void Release() override;

	/// <summary>
	/// �ʒu���w�肷��
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void SetPosition(float x, float y);

	/// <summary>
	/// �l�������Z����
	/// </summary>
	/// <param name="v"></param>
	void AddValue(float v);

	/// <summary>
	/// �l�𒼐�set����
	/// </summary>
	void SetValue(float v);
	float GetValue();
};