#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() { delete model_; }

void GameScene::Initialize() {
	textureHandle_ = TextureManager::Load("Yoshi.jpg");
	model_ = Model::Create();
	worldTransform_.Initialize();
	camera_.Initialize();
}

void GameScene::Update() {}
void GameScene::Draw() {
	// DirectXCommonのインスタンスを取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 描画前処理
	Model::PreDraw(dxCommon->GetCommandList());
	// 描画
	model_->Draw(worldTransform_, camera_, textureHandle_);
	// 描画後処理
	Model::PostDraw();
}
