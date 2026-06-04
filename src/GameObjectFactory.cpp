#include "GameObjectFactory.h"

std::unique_ptr<GameObject> GameObjectFactory::createObject(const std::string& type, Vector2 position) {
    if (type == "player") {
        return std::make_unique<Player>(position);
    }

    if (type == "enemy") {
        return std::make_unique<Enemy>(position);
    }

    return std::make_unique<GameObject>(position, 30, RED, "Object");
}