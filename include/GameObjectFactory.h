#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <memory>
#include <string>

class GameObjectFactory {
public:
    static std::unique_ptr<GameObject> createObject(const std::string& type, Vector2 position);
};