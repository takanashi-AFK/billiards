#include "Ball.h"
#include"Engine/Model.h"
#include<string>
//コンストラクタ
Ball::Ball(GameObject* parent)
	: GameObject(parent, "Ball"),hModel_(-1)
{
	velocity_ = XMVectorSet(0,0,0,0);//速度ベクトル 毎fこれずつ進んでく
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
	XMVECTOR lenVec = XMVector3Length(velocity_);//長さ取得
	float len = XMVectorGetX(lenVec);
	len -= 0.001f;//長さから毎f0.001ずつ引いて減速する
	velocity_ = XMVector3Normalize(velocity_) * len;//vectorの方向だけほしいから単位化
	transform_.position_ += velocity_;
	
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
	fileName_ = (_no+".fbx");
	hModel_ = Model::Load("1.fbx");//ここで指定することでモデルの差し替えが簡単になる
	assert(hModel_ >= 0);
}

void Ball::AddForce(XMVECTOR f)
{
	velocity_+= f;

}
