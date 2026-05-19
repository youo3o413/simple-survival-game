#include "GameObject.h"

GameObject::GameObject(Vector2 pos, float s, Color c, std::string n)
    : position(pos), size(s), color(c), name(n) {}

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
