#pragma once
#include "GameObject.h"

class Player : public GameObject {
private:
    float speed;

public:
    Player(Vector2 pos);
    void update() override;
    void draw() const override;
};
