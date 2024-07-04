#ifndef _TONE_BLOCK_LOGIC_CPP
#define _TONE_BLOCK_LOGIC_CPP

#include <smash.h>

class ToneBlockLogic : public smash::BehaviourScript
{
public:
    static constexpr float s_fallSpeed = 10.0f;
    ToneBlockLogic() = default;
    ~ToneBlockLogic() = default;

    void update(double deltaTime) override
    {
        // Get the transform component
        auto transform = (smash::Transform*)getComponent("Transform");
        if (transform)
        {
            // Let the tone block fall
            transform->translate(smash::Vector2::right() * s_fallSpeed * (float)deltaTime);

            // Check for border cross
            if (transform->getPosition().x + transform->getScale().x >= 64.0f)
            {
                // Get the tone source
                auto toneSource = (smash::ToneSource*)getComponent("ToneSource");
                if (toneSource)
                {
                    // Play the tone

                    toneSource->play();
                }
            }
        }
    }   

    std::string getTypeName() const override
    {
        return "ToneBlockLogic";
    }
};

#endif