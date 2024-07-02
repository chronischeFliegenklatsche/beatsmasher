
#include <Arduino.h>
#include <gameRuntime.cpp>

GameRuntime game;

void setup()
{
    Serial.begin(115200);
    game.initialize();
}

void loop()
{
    if (!game.getExitQueued())
    {
        game.update();
    }
    game.shutdown();
}
