#pragma once
#include "KamataEngine.h"

class Player {
public:
	// 初期化
	void Initialize(KamataEngine:: Model*model_,uint32_t textureHandle_,KamataEngine::Camera*camera);
	// 更新
	void Update();
	// 描画
	void Draw();

private:
	KamataEngine ::WorldTransform worldTransform_;
	KamataEngine ::Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;
	KamataEngine::Camera* camera_= nullptr ;
};