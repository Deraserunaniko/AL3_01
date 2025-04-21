#include "GameScene.h"
#include "Player.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	delete model_;
	delete player_;
}

void GameScene::Initialize() {
	// テクスチャを読み込む
	textureHandle_ = TextureManager::Load("Yoshi.jpg");
	// モデルの生成
	model_ = Model::Create();
	worldTransform_.Initialize();
	// カメラの初期化
	camera_.Initialize();
	// プレイヤーの生成
	player_ = new Player();
	// プレイヤーの初期化
	player_->Initialize(model_,textureHandle_,&camera_);
}

void GameScene::Update() { 
	//プレイヤーの更新
	player_->Update();
}
void GameScene::Draw() {
	// DirectXCommonのインスタンスを取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 描画前処理
	Model::PreDraw(dxCommon->GetCommandList());
	// 描画
	model_->Draw(worldTransform_, camera_, textureHandle_);
	// プレイヤーの描画
	player_->Draw();
	// 描画後処理
	Model::PostDraw();
	
}
