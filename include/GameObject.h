#pragma once
#include "raylib.h"
#include <string>

class GameObject {
protected:
    Vector2 position;
    float size;
    Color color;
    std::string name;

    int hp;
    bool dead;

public:
    GameObject(Vector2 pos, float s, Color c, std::string n);
    virtual ~GameObject() = default;

    virtual void update();
    virtual void draw() const;

    Vector2 getPosition() const;
    std::string getName() const;

    float getSize() const;
    int getHP() const;

    void takeDamage(int damage);
    bool isDead() const;
};