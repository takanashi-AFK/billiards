#include <cmath>
#include "Ready.h"

namespace {
	float startX;//移動開始X座標
	float endX;//移動終了X座標
	float totaltime;//移動時間
	float currentTime; //現在の時間
	int seq_line;//いまなにしてるか
	float seq_time;//シーケンスを実行している時間
	enum ACT
	{
		A_SLIDEIN = 1,
		A_WAIT,
		A_SLIDEOUT,
		A_END
	};
	struct Sequence {
		float time;//時間
		ACT action;//やること
		float param;//必要な値
	};
	Sequence tbl[] = {
		{0.0f,A_SLIDEIN	, 5.0f},//0秒地点で5.0からスライドイン
		{3.0f,A_WAIT	, 0.0f},//1秒待って
		{4.0f,A_SLIDEOUT,-5.0f},//4秒地点で-5.0へスライドアウト
		{5.0f,A_END		, 0.0f}
	};
	ACT currentAction;//今実行しているアクション
	bool canMove;//移動できるか
}
//コンストラク
Ready::Ready(GameObject* parent)
	: GameObject(parent, "Ready"),hImage_(-1)
{
	seq_line = -1;
	seq_time = 0.0f;
	canMove = false;
}

//初期化
void Ready::Initialize()
{
	hImage_ = Image::Load("Ready.png");

	startX = 2.0f;
	endX = 0;
	totaltime = 3.0f;
	currentTime = 0.0f;
}


float easeInCubic(float x)
{
	return x * x * x;
}
//更新
void Ready::Update()
{
	seq_time += 1.0f / 60.0f;
	if (seq_time >= tbl[seq_line + 1].time)
	{
		seq_line++;
		switch (tbl[seq_line].action) {
		case A_END:
			KillMe();
			break;
		case A_SLIDEIN:
			startX = tbl[seq_line].param;
			endX = 0;
			totaltime = tbl[seq_line+1].time-seq_time;
			currentTime = 0.0f;
			break;
		case A_WAIT:
			startX = transform_.position_.x;
			endX = transform_.position_.x;
			totaltime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		case A_SLIDEOUT:
			canMove = true;
			startX = transform_.position_.x;
			endX = tbl[seq_line].time - seq_time - 2;
			totaltime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		}
		
	}
	currentTime += 1.0f/60.0f;
	if (currentTime > totaltime)
		currentTime = totaltime;

	float t = currentTime / totaltime;
	float val = easeInCubic(t);

	transform_.position_.x = val * (endX - startX) + startX;
}

//描画
void Ready::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

//開放
void Ready::Release()
{
}

bool Ready::Finished()
{
	return canMove;
}
