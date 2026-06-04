#include "GameObject.h"

GameObject::GameObject(Vector2 pos, float s, Color c, std::string n)
    : position(pos),
      size(s),
      color(c),
      name(n),
      hp(1),
      dead(false) {}

void GameObject::update() {}

void GameObject::draw() const {
    DrawRectangleV(position, {size, size}, color);
}

Vector2 GameObject::getPosition() const {
    return position;
}

std::string GameObject::getName() const {
    return name;
}

float GameObject::getSize() const {
    return size;
}

int GameObject::getHP() const {
    return hp;
}

void GameObject::takeDamage(int damage) {
    hp -= damage;

    if (hp <= 0) {
        dead = true;
    }
}

bool GameObject::isDead() const {
    return dead;
}