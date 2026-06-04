#include "Player.h"

Player::Player(Vector2 pos)
    : GameObject(pos, 40, BLUE, "Player"), speed(4.0f) {}

void Player::update() {
    if (IsKeyDown(KEY_W)) position.y -= speed;
    if (IsKeyDown(KEY_S)) position.y += speed;
    if (IsKeyDown(KEY_A)) position.x -= speed;
    if (IsKeyDown(KEY_D)) position.x += speed;

    if (position.x < 0) position.x = 0;
    if (position.y < 0) position.y = 0;
    if (position.x + size > 800) position.x = 800 - size;
    if (position.y + size > 450) position.y = 450 - size;
}

void Player::draw() const {
    DrawRectangleV(position, {size, size}, color);
    DrawText("Player", position.x - 5, position.y - 20, 14, BLACK);
}