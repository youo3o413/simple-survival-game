#include "Enemy.h"
#include <cmath>

Enemy::Enemy(Vector2 pos)
    : GameObject(pos, 30, RED, "Enemy"), speed(1.5f) {
    hp = 3;
}

void Enemy::updateToward(Vector2 playerPosition) {
    float dx = playerPosition.x - position.x;
    float dy = playerPosition.y - position.y;
    float length = std::sqrt(dx * dx + dy * dy);

    if (length > 0) {
        position.x += speed * dx / length;
        position.y += speed * dy / length;
    }
}

void Enemy::draw() const {
    DrawRectangleV(position, {size, size}, color);
    DrawText("Enemy", position.x - 5, position.y - 18, 12, DARKGRAY);
}