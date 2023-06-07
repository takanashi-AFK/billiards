#include "Ball.h"
#include"Engine/Model.h"
#include<string>
//コンストラクタ
Ball::Ball(GameObject* parent)
	: GameObject(parent, "Ball"),hModel_(-1)
{
}

Ball::~Ball()
{
	if (hModel_ > 0)
		Model::Release(hModel_);
}


//初期化
void Ball::Initialize()
{
	
}

//更新
void Ball::Update()
{
}

//描画
void Ball::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Ball::Release()
{
}

void Ball::SetNumber(int _no)
{
	number_ = _no;
	std::to_string(number_);
	fileName_ = (number_+".fbx");
	hModel_ = Model::Load(fileName_);//ここで指定することでモデルの差し替えが簡単になる
	assert(hModel_ >= 0);
}
