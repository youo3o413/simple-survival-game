#include "Game.h"
#include "GameObjectFactory.h"
#include "raylib.h"

void Game::init() {
    objects.push_back(GameObjectFactory::createObject("player", {380, 200}));
    objects.push_back(GameObjectFactory::createObject("enemy", {100, 100}));
    objects.push_back(GameObjectFactory::createObject("enemy", {650, 300}));
}

void Game::update() {
    for (auto& object : objects) {
        object->update();
    }
}

void Game::draw() const {
    DrawText("Use W A S D to move the player", 20, 20, 20, DARKGRAY);

    for (const auto& object : objects) {
        object->draw();
    }
}
