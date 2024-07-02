#ifndef _TONE_BLOCK_H
#define _TONE_BLOCK_H

#include <smash.h>
#include "../types/tone.cpp"
#include "../shaders/dynamicRectFrag.cpp"
#include "../scripts/move.cpp"

class ToneBlockGenerator;

class ToneBlock : public smash::GameObject
{
    Tone m_tone;
    ToneBlockGenerator *m_generator;
public:
    static constexpr float s_Speed = 5.0f;
    ToneBlock() : ToneBlock(Tone(0, 0, 0, 0), smash::Vector2(0, 0), 0) {}
    ToneBlock(smash::Vector2 position, float length) : ToneBlock(Tone(0, 0, 0, 0), position, length) {}
    ToneBlock(Tone tone, smash::Vector2 position, float length) : m_tone(tone), m_generator(nullptr)
    {
        // Initialize transform
        auto transform = std::make_shared<smash::Transform>(position, smash::Vector2(length, 4));   
        
        // Intialize move
        auto move = std::make_shared<Move>(smash::Vector2::right(), s_Speed);

        // Initialize shader renderer
        auto shadRenderer = std::make_shared<smash::ShaderRenderer>();
        
        // Initialize and add shaders
        shadRenderer->getShaderProgram().addShader(std::make_shared<DynamicRectFragment>());
        
        // Initialize and add shader attributes
        auto shaderAttr = std::make_shared<smash::ShaderAttributes>();
        shaderAttr->setPointer("p_Position", (void*)&(transform->getPositionRef()));
        shaderAttr->setPointer("p_Scale", (void*)&(transform->getScaleRef()));
        shadRenderer->setShaderAttributes(shaderAttr);
        
        // Add components
        addComponent(transform);
        addComponent(shadRenderer);
    }

    void setGeneratorForCallback(ToneBlockGenerator *generator)
    {
        m_generator = generator;
    }
};

#endif