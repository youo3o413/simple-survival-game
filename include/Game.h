#pragma once
#include "GameObject.h"
#include <memory>
#include <vector>

class Game {
private:
    std::vector<std::unique_ptr<GameObject>> objects;

public:
    void init();
    void update();
    void draw() const;
};
