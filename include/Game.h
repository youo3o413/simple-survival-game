#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include <memory>
#include <vector>

class Game {
private:
    std::vector<std::unique_ptr<GameObject>> objects;

    float spawnTimer;
    float spawnInterval;

    float attackTimer;
    float attackInterval;

    float survivalTime;
    int killCount;
    int playerHP;
    bool gameOver;

    bool checkCollision(GameObject* a, GameObject* b) const;

public:
    void init();
    void update();
    void draw() const;
};