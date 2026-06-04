#include "Game.h"
#include "GameObjectFactory.h"
#include "Enemy.h"
#include "Projectile.h"
#include "raylib.h"
#include <cmath>
#include <algorithm>

void Game::init() {
    spawnTimer = 0.0f;
    spawnInterval = 2.0f;
    attackTimer = 0.0f;
    attackInterval = 0.7f;

    survivalTime = 0.0f;
    killCount = 0;
    playerHP = 10;
    gameOver = false;

    objects.push_back(GameObjectFactory::createObject("player", {380, 200}));
    objects.push_back(GameObjectFactory::createObject("enemy", {100, 100}));
    objects.push_back(GameObjectFactory::createObject("enemy", {650, 300}));
}

bool Game::checkCollision(GameObject* a, GameObject* b) const {
    Rectangle rectA = {a->getPosition().x, a->getPosition().y, a->getSize(), a->getSize()};
    Rectangle rectB = {b->getPosition().x, b->getPosition().y, b->getSize(), b->getSize()};
    return CheckCollisionRecs(rectA, rectB);
}

void Game::update() {
    if (gameOver) return;

    survivalTime += GetFrameTime();
    spawnTimer += GetFrameTime();
    attackTimer += GetFrameTime();

    if (spawnTimer >= spawnInterval) {
        spawnTimer = 0.0f;

        int side = GetRandomValue(0, 3);
        Vector2 pos;

        if (side == 0) pos = {0, (float)GetRandomValue(0, 450)};
        else if (side == 1) pos = {800, (float)GetRandomValue(0, 450)};
        else if (side == 2) pos = {(float)GetRandomValue(0, 800), 0};
        else pos = {(float)GetRandomValue(0, 800), 450};

        objects.push_back(GameObjectFactory::createObject("enemy", pos));
    }

    Vector2 playerPosition = objects[0]->getPosition();

    if (attackTimer >= attackInterval) {
        attackTimer = 0.0f;

        Enemy* nearestEnemy = nullptr;
        float nearestDistance = 999999.0f;

        for (auto& object : objects) {
            Enemy* enemy = dynamic_cast<Enemy*>(object.get());

            if (enemy != nullptr && !enemy->isDead()) {
                Vector2 enemyPosition = enemy->getPosition();
                float dx = enemyPosition.x - playerPosition.x;
                float dy = enemyPosition.y - playerPosition.y;
                float distance = std::sqrt(dx * dx + dy * dy);

                if (distance < nearestDistance) {
                    nearestDistance = distance;
                    nearestEnemy = enemy;
                }
            }
        }

        if (nearestEnemy != nullptr) {
            Vector2 enemyPosition = nearestEnemy->getPosition();
            Vector2 direction = {
                enemyPosition.x - playerPosition.x,
                enemyPosition.y - playerPosition.y
            };

            objects.push_back(std::make_unique<Projectile>(playerPosition, direction));
        }
    }

    for (auto& object : objects) {
        Enemy* enemy = dynamic_cast<Enemy*>(object.get());

        if (enemy != nullptr) {
            enemy->updateToward(playerPosition);
        } else {
            object->update();
        }
    }

    for (auto& projectileObject : objects) {
        Projectile* projectile = dynamic_cast<Projectile*>(projectileObject.get());
        if (projectile == nullptr || projectile->isDead()) continue;

        for (auto& enemyObject : objects) {
            Enemy* enemy = dynamic_cast<Enemy*>(enemyObject.get());
            if (enemy == nullptr || enemy->isDead()) continue;

            if (checkCollision(projectile, enemy)) {
                projectile->takeDamage(1);
                enemy->takeDamage(1);

                if (enemy->isDead()) {
                    killCount++;
                }
                break;
            }
        }
    }

    GameObject* player = objects[0].get();

    for (auto& object : objects) {
        Enemy* enemy = dynamic_cast<Enemy*>(object.get());

        if (enemy != nullptr && !enemy->isDead()) {
            if (checkCollision(player, enemy)) {
                enemy->takeDamage(10);
                playerHP--;

                if (playerHP <= 0) {
                    gameOver = true;
                }
            }
        }
    }

    objects.erase(
        std::remove_if(objects.begin() + 1, objects.end(),
            [](const std::unique_ptr<GameObject>& object) {
                Projectile* projectile = dynamic_cast<Projectile*>(object.get());

                if (projectile != nullptr && projectile->isOutOfScreen()) {
                    return true;
                }

                return object->isDead();
            }),
        objects.end()
    );
}

void Game::draw() const {
    DrawText("Use W A S D to move the player", 20, 20, 20, DARKGRAY);

    DrawText(TextFormat("HP: %d", playerHP), 20, 50, 20, RED);
    DrawText(TextFormat("Time: %.1f", survivalTime), 20, 80, 20, DARKGRAY);
    DrawText(TextFormat("Kills: %d", killCount), 20, 110, 20, DARKGREEN);

    for (const auto& object : objects) {
        object->draw();
    }

    if (gameOver) {
        DrawText("GAME OVER", 280, 190, 50, RED);
    }
}