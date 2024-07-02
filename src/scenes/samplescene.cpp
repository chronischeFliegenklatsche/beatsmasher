#include <smash.h>
#include "prefabs/fallingBlock.cpp"

class SampleScene : public smash::Scene {

public:
    SampleScene()
    {
        instantiate(std::make_shared<FallingBlock>());
    }
    ~SampleScene() = default;



};