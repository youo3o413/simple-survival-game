#include "GameObjectFactory.h"

std::unique_ptr<GameObject> GameObjectFactory::createObject(const std::string& type, Vector2 position) {
    if (type == "player") {
        return std::make_unique<Player>(position);
    }

    return std::make_unique<GameObject>(position, 30, RED, "Object");
}
