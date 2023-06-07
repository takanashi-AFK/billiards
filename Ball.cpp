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
	if (len < 0.0f) len = 0.0f;
	velocity_ = XMVector3Normalize(velocity_) * len;//vectorの方向だけほしいから単位化

	std::list<Ball*>all = FindGameObjects<Ball>();
	for (std::list <Ball*>::iterator itr = all.begin(); itr != all.end(); itr++) {
		if (*itr == this) continue;
		XMFLOAT3 next = transform_.position_ + velocity_;//自分の移動先
		XMFLOAT3 other = (*itr)->GetNextPosition();		 //相手の移動先
		if (/*nextとotherが当たったら*/true);

	}

	XMFLOAT3 next = transform_.position_ + velocity_;
	if (next.x >= 35.0f) {
		XMVECTOR n = XMVectorSet(-1, 0, 0, 0);//右の壁の法線(長さが1)
		n = n * -1;//(逆にして、壁に向かうベクトル)
		XMVECTOR ipvec = XMVector3Dot(velocity_, n);//信仰ベクトルと逆法線ベクトルの内積を計算する
		float ip = XMVectorGetX(ipvec);//壁を押すpower
		XMVECTOR push = n * ipvec;//壁を押すベクトル
		XMVECTOR th = velocity_ - push;//壁に沿ってるベクトル

		push *= -1;//壁の柔らかさ
		velocity_ = push + th;
		/*XMFLOAT3 f;

			XMStoreFloat3(&f,velocity_);
			f.x *= -1;
		velocity_ = XMLoadFloat3(&f)*/;
	}
	if (next.z >= 19.0f) {
		XMVECTOR n = XMVectorSet(0, 0, 1, 0);//右の壁の法線(長さが1)
		n = n * -1;//(逆にして、壁に向かうベクトル)
		XMVECTOR ipvec = XMVector3Dot(velocity_, n);//信仰ベクトルと逆法線ベクトルの内積を計算する
		float ip = XMVectorGetX(ipvec);//壁を押すpower
		XMVECTOR push = n * ipvec;//壁を押すベクトル
		XMVECTOR th = velocity_ - push;//壁に沿ってるベクトル

		push *= -1;//壁の柔らかさ
		velocity_ = push + th;
		/*XMFLOAT3 f;

			XMStoreFloat3(&f,velocity_);
			f.x *= -1;
		velocity_ = XMLoadFloat3(&f)*/;
	}
	if (next.x <= -35.0f) {
		XMVECTOR n = XMVectorSet(1, 0, 0, 0);//右の壁の法線(長さが1)
		n = n * -1;//(逆にして、壁に向かうベクトル)
		XMVECTOR ipvec = XMVector3Dot(velocity_, n);//信仰ベクトルと逆法線ベクトルの内積を計算する
		float ip = XMVectorGetX(ipvec);//壁を押すpower
		XMVECTOR push = n * ipvec;//壁を押すベクトル
		XMVECTOR th = velocity_ - push;//壁に沿ってるベクトル

		push *= -1;//壁の柔らかさ
		velocity_ = push + th;
		/*XMFLOAT3 f;

			XMStoreFloat3(&f,velocity_);
			f.x *= -1;
		velocity_ = XMLoadFloat3(&f)*/;
	}
	if (next.z <= -19.0f) {
		XMVECTOR n = XMVectorSet(0, 0, -1, 0);//右の壁の法線(長さが1)
		n = n * -1;//(逆にして、壁に向かうベクトル)
		XMVECTOR ipvec = XMVector3Dot(velocity_, n);//信仰ベクトルと逆法線ベクトルの内積を計算する
		float ip = XMVectorGetX(ipvec);//壁を押すpower
		XMVECTOR push = n * ipvec;//壁を押すベクトル
		XMVECTOR th = velocity_ - push;//壁に沿ってるベクトル

		push *= -1;//壁の柔らかさ
		velocity_ = push + th;
		/*XMFLOAT3 f;

			XMStoreFloat3(&f,velocity_);
			f.x *= -1;
		velocity_ = XMLoadFloat3(&f)*/;
	}

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
