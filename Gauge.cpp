
#include "Engine/Image.h"
#include <cassert>
#include "Gauge.h"
Gauge::Gauge(GameObject* parent)
	: GameObject(parent, "Gauge"), hPictGauge_(-1), hPictFrame_(-1), nowHp_(0)
{
}


void Gauge::Initialize()
{
	hPictGauge_ = Image::Load("LifeGauge.png");
	assert(hPictGauge_ >= 0);
	hPictFrame_ = Image::Load("LifeFrame.png");
	assert(hPictFrame_ >= 0);

	ImageHeight_ = 64;
	ImageWidth_ = 512;
}

void Gauge::Update()
{

}

void Gauge::Draw()
{
	/*Transform transGauge = transform_;
	transform_.scale_.x = (float)animHp_ / (float)maxHp_;*/
	int left = ImageWidth_ / 2 - ImageWidth_ /2 * nowHp_;
	int width = ImageWidth_*nowHp_;

	Image::SetRect(hPictGauge_, left, 0, width, ImageHeight_);
	Image::SetTransform(hPictGauge_, transform_);
	Image::Draw(hPictGauge_);

	Image::SetTransform(hPictFrame_, transform_);
	Image::Draw(hPictFrame_);

}

void Gauge::Release()
{
}

void Gauge::SetPosition(float x, float y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

void Gauge::AddValue(float v)
{
	nowHp_ += v;
	if (nowHp_ < 0.0f) {
		nowHp_ = 0;
	}
	else if (nowHp_ > maxHp_) {
		nowHp_ = maxHp_;
	}
}

void Gauge::SetValue(float v)
{

	assert(v >= 0.0f && v <= 1.0f);
	nowHp_ = v;
	if (nowHp_ < 0.0f) {
		nowHp_ = 0;
	}
	else if (nowHp_ > maxHp_) {
		nowHp_ = maxHp_;
	}
}

float Gauge::GetValue()
{
	return nowHp_;
}
