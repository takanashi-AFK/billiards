#include "Button.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include"Engine/Direct3D.h"
Button::Button(GameObject* parent)
{
}

void Button::Initialize()
{
	hFoodButtonUpPict_ = Image::Load("Button/GiveUp.png");
	hFoodButtonDownPict_ = Image::Load("Button/GiveDown.png");

	hBackButtonUpPict_ = Image::Load("Button/BackUp.png");
	hBackButtonDownPict_ = Image::Load("Button/BackDown.png");
	Food.position_.x = -0.5;



	Back.position_.x = 0.5;


	pText = new Text;
	pText->Initialize();
	pText1 = new Text;
	pText1->Initialize();
}

void Button::Update()
{
	if (Input::IsMouseButton(0))
		Image::SetAlpha(hFoodButtonUpPict_, 0);
	else
		Image::SetAlpha(hFoodButtonUpPict_, 255);

	if (Input::IsMouseButton(0))
		Image::SetAlpha(hBackButtonUpPict_, 0);
	else
		Image::SetAlpha(hBackButtonUpPict_, 255);

	MousePos = Input::GetMousePosition();
}

void Button::Draw()
{

	Image::SetTransform(hFoodButtonDownPict_, Food);
	Image::Draw(hFoodButtonDownPict_);

	Image::SetTransform(hFoodButtonUpPict_, Food);
	Image::Draw(hFoodButtonUpPict_);

	Image::SetTransform(hBackButtonDownPict_, Back);
	Image::Draw(hBackButtonDownPict_);

	Image::SetTransform(hBackButtonUpPict_, Back);
	Image::Draw(hBackButtonUpPict_);

	int x, y;
	x = Image::GetSize(hBackButtonUpPict_).x;
	y = Image::GetSize(hBackButtonUpPict_).y;

	SetPosition(x, y);

	pText->Draw(1000, 500, x);
	pText1->Draw(1200, 500, y);
}

void Button::Release()
{
}

void Button::SetPosition(int x, int y)
{
	transform_.position_.x = (float)(x - Direct3D::screenWidth_ / 2) / Direct3D::screenWidth_;
	transform_.position_.y = -(float)(y - Direct3D::screenHeight_ / 2)/(Direct3D::screenHeight_ / 2);
	center = XMFLOAT3(x, y, 0);
}

//まうすぽす取る
//ボタンを２個インスタンス作る
//