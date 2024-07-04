#include <smash.h>
#include "prefabs/toneBlock.cpp"

class SampleScene : public smash::Scene {

public:
    SampleScene()
    {
        instantiate(std::make_shared<ToneBlock>(Tone(440.0f, 0.0f, 1.0f, 0)));
    }
    ~SampleScene() = default;



};