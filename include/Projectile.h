#pragma once
#include "GameObject.h"

class Projectile : public GameObject {
private:
    Vector2 direction;
    float speed;

public:
    Projectile(Vector2 pos, Vector2 dir);

    void update() override;
    void draw() const override;

    bool isOutOfScreen() const;
};