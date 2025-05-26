#pragma once
#include "KamataEngine.h"
#include "MapChipField.h"
#include "Player.h"
#include "Skydome.h"
#include <vector>

using namespace KamataEngine;

class GameScene {

	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Camera camera_;
	Player* player_ = nullptr;

	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

	KamataEngine::Model* modelSkydome_ = nullptr;

	KamataEngine::Model* modelPlayer_ = nullptr;

	SkyDome* skydome_ = nullptr;

private:
	uint32_t textureHandle_ = 0;
	KamataEngine::Model* modelBlock_;
	DebugCamera* debugCamera_ = nullptr;
	bool isDebugCameraActive_ = false;
	// マップチップフィールド
	MapChipField* mapChipField_;

public:
	// 初期化
	void Initialize();
	~GameScene();
	// 更新
	void Update();
	// 描画
	void Draw();

	void GenerateBloacks();
};