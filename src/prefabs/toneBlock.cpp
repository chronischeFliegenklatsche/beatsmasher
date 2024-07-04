#ifndef _TEST_BLOCK_CPP
#define _TEST_BLOCK_CPP

#include <smash.h>
#include "../shaders/dynamicRectFrag.cpp"
#include "../types/tone.cpp"
#include "../scripts/toneBlockLogic.cpp"

class ToneBlock : public smash::GameObject
{
public:
    ToneBlock(Tone tone)
    {
        // Initialize transform
        auto transform = std::make_shared<smash::Transform>(1.0f, 1.0f, 5.0f, 5.0f);

        // Initialize shaders
        auto baseShader = std::make_shared<DynamicRectFragment>();

        // Initialize shader attributes
        auto shaderAttributes = std::make_shared<smash::ShaderAttributes>();
        shaderAttributes->setPointer("p_Position", &transform->getPositionRef());
        shaderAttributes->setPointer("p_Scale", &transform->getScaleRef());

        // Initialize shader renderer
        auto shadRenderer = std::make_shared<smash::ShaderRenderer>();
        shadRenderer->setShaderAttributes(shaderAttributes);
        shadRenderer->getShaderProgram().addShader(baseShader);

        // Intialize tone source
        auto toneSource = std::make_shared<smash::ToneSource>();
        toneSource->setNote(NOTE_A);
        toneSource->setOctave(4);
        toneSource->setDuration(tone.duration);
        toneSource->setSpeakerIndex(0);

        // Initialize tone block logic
        auto toneBlockLogic = std::make_shared<ToneBlockLogic>();

        // Add components
        addComponent(transform);
        addComponent(shadRenderer);
        addComponent(toneSource);
        addComponent(toneBlockLogic);
    }
    ~ToneBlock() = default;
};

#endif