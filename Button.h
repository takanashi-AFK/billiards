#pragma once
#include "Engine/GameObject.h"

class Button : public GameObject {
public:
	Button(GameObject* parent);
	~Button();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	bool Finished(); // Button���I�������true
	void SetImage(std::string normal, std::string pushed);
	void SetPosition(int x, int y);
	void Push(bool pushed);
	bool MouseInArea(XMFLOAT3 mousePos);
	void SetMovePosition(int toX, int toY, float seconds);
	float easeIncubic(float x);

	/// <summary>
	/// �����Ă�Ȃ�true
	/// </summary>
	/// <returns></returns>
	bool IsMoving();

	/// <summary>
	/// �����I�Ɉړ����I��������
	/// </summary>
	void ForceMoveEnd();
private:
	int hImage;
	int hPush;
	bool pushed;
	XMFLOAT3 center;
	XMFLOAT3 size;

	XMFLOAT3 startPos;//�ړ��J�nX���W
	XMFLOAT3 endPos;//�ړ��I��X���W
	float totaltime;//�ړ�����
	float currentTime; //���݂̎���

};