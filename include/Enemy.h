#pragma once
#include "GameObject.h"

class Enemy : public GameObject {
private:
    float speed;

public:
    Enemy(Vector2 pos);

    void updateToward(Vector2 playerPosition);
    void draw() const override;
};