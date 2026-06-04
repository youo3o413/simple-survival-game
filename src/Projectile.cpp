#include "Projectile.h"
#include <cmath>

Projectile::Projectile(Vector2 pos, Vector2 dir)
    : GameObject(pos, 10, BLACK, "Projectile"),
      direction(dir),
      speed(6.0f) {
    hp = 1;

    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }
}

void Projectile::update() {
    position.x += direction.x * speed;
    position.y += direction.y * speed;
}

void Projectile::draw() const {
    DrawCircleV(position, size, color);
}

bool Projectile::isOutOfScreen() const {
    return position.x < 0 || position.x > 800 ||
           position.y < 0 || position.y > 450;
}