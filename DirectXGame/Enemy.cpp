#include "Enemy.h"
#include "MapChipField.h"
#include "Math.h"
#include "UpData.h"
#include <algorithm>
#include <cassert>
#include <numbers>

using namespace KamataEngine;

void Enemy::Initialize(Model* model, Camera* camera, const Vector3& position) {

	assert(model);


	model_ = model;

	camera_ = camera;

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	
	worldTransform_.rotation_.y = std::numbers::pi_v<float> * 3.0f / 2.0f;

	
	velocity_ = {-kWalkSpeed, 0, 0};
	
	walkTimer = 0.0f;
}

void Enemy::UpDate() {

	// 02_09 16枚目 移動
	worldTransform_.translation_ += velocity_;

	// 02_09 20枚目
	walkTimer += 1.0f / 60.0f;

	// 02_09 23枚目 回転アニメーション
	// worldTransform_.rotation_.x = std::sin(std::numbers::pi_v<float> * 2.0f * walkTimer / kWalkMotionTime);

	float param = std::sin(std::numbers::pi_v<float> * 2.0f * walkTimer / kWalkMotionTime);

	float degree = kWalkMotionAngleStart + kWalkMotionAngleEnd * (param + 1.0f) / 2.0f;

	worldTransform_.rotation_.x = degree * (std::numbers::pi_v<float> / 180.0f);

	// 02_09 スライド8枚目 ワールド行列更新
	upData->WorldTransformUpData(worldTransform_);
}

// 02_09 スライド5枚目
void Enemy::Draw() {
	// 02_09 スライド9枚目  モデル描画
	model_->Draw(worldTransform_, *camera_);
}