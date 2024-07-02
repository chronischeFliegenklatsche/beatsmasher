#define R1_PIN 25
#define G1_PIN 26
#define B1_PIN 27
#define R2_PIN 14
#define G2_PIN 12
#define B2_PIN 13
#define A_PIN 23
#define B_PIN 22
#define C_PIN 5
#define D_PIN 18
#define E_PIN -1  // Set to -1 as it's not needed for 64x32 panels
#define LAT_PIN 33
#define OE_PIN 15
#define CLK_PIN 32  // Changed from 16 to 32

#include <smash.h>
#include "scenes/samplescene.cpp"



class GameRuntime : public smash::Runtime
{
public:

    GameRuntime() = default;
    ~GameRuntime() = default;

    void initialize() override
    {
        // Add a button to the input system
        addInputDevice(std::make_shared<smash::Button>("Test_Button", 2));  

        // Add scene
        auto sampleScene = std::make_shared<SampleScene>();
        addScene(sampleScene);
        
        // Set active scene
        setActiveScene(sampleScene);

        // Configure matrix
        HUB75_I2S_CFG::i2s_pins _pins = {
            R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN,
            A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN
        };

        HUB75_I2S_CFG mxconfig(
            64,   // Module width
            32,   // Module height
            1,    // Chain length
            _pins // Pin mapping
        );
        // set matrix
        auto matrix = std::make_shared<smash::matrix>(mxconfig);
        setDisplay(matrix);

    }

};
