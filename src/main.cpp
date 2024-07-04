
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
/*
#include <Arduino.h>

#define TONE_CHANNEL 0
#define SPEAKER_PIN 2
#define FREQ 440

void setup()
{
    ledcAttachPin(SPEAKER_PIN, TONE_CHANNEL);   
}

void loop()
{
    ledcWriteNote(TONE_CHANNEL, NOTE_A, 4);
    delay(1000);
    ledcWriteTone(TONE_CHANNEL, 0);
    delay(1000);
}*/