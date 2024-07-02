#ifndef _MOVE_CPP
#define _MOVE_CPP

#include <smash.h>

class Move : public smash::BehaviourScript
{
    smash::Vector2 m_direction = smash::Vector2::right();
    float m_speed  = 5.0f;
public:

    Move() = default;
    Move(int updateIndex) : BehaviourScript(updateIndex) {}
    Move(smash::Vector2 direction, float speed) : m_direction(direction), m_speed(speed) {}
    Move(int updateIndex, smash::Vector2 direction, float speed) : BehaviourScript(updateIndex), m_direction(direction), m_speed(speed) {}

    void update(double deltaTime) override
    {
    
        auto transform = (smash::Transform*)getComponent("Transform");
        if (transform)
        {
            transform->translate(m_direction.normalized() * m_speed * (float)deltaTime);
        }
    }

    std::string getTypeName() const override
    {
        return "Move";
    }
};

#endif