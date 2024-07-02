#ifndef _TONE_CPP
#define _TONE_CPP

#include <string>
#include <unordered_map>

static const std::unordered_map<std::string, float> noteFrequencies = {
    // Octave 0
    {"C0", 16.35f}, {"C#0", 17.32f}, {"Db0", 17.32f},
    {"D0", 18.35f}, {"D#0", 19.45f}, {"Eb0", 19.45f},
    {"E0", 20.60f}, {"Fb0", 20.60f}, {"E#0", 21.83f},
    {"F0", 21.83f}, {"F#0", 23.12f}, {"Gb0", 23.12f},
    {"G0", 24.50f}, {"G#0", 25.96f}, {"Ab0", 25.96f},
    {"A0", 27.50f}, {"A#0", 29.14f}, {"Bb0", 29.14f},
    {"B0", 30.87f}, {"Cb1", 30.87f}, {"B#0", 32.70f},

    // Octave 1
    {"C1", 32.70f}, {"C#1", 34.65f}, {"Db1", 34.65f},
    {"D1", 36.71f}, {"D#1", 38.89f}, {"Eb1", 38.89f},
    {"E1", 41.20f}, {"Fb1", 41.20f}, {"E#1", 43.65f},
    {"F1", 43.65f}, {"F#1", 46.25f}, {"Gb1", 46.25f},
    {"G1", 49.00f}, {"G#1", 51.91f}, {"Ab1", 51.91f},
    {"A1", 55.00f}, {"A#1", 58.27f}, {"Bb1", 58.27f},
    {"B1", 61.74f}, {"Cb2", 61.74f}, {"B#1", 65.41f},

    // Octave 2
    {"C2", 65.41f}, {"C#2", 69.30f}, {"Db2", 69.30f},
    {"D2", 73.42f}, {"D#2", 77.78f}, {"Eb2", 77.78f},
    {"E2", 82.41f}, {"Fb2", 82.41f}, {"E#2", 87.31f},
    {"F2", 87.31f}, {"F#2", 92.50f}, {"Gb2", 92.50f},
    {"G2", 98.00f}, {"G#2", 103.83f}, {"Ab2", 103.83f},
    {"A2", 110.00f}, {"A#2", 116.54f}, {"Bb2", 116.54f},
    {"B2", 123.47f}, {"Cb3", 123.47f}, {"B#2", 130.81f},

    // Octave 3
    {"C3", 130.81f}, {"C#3", 138.59f}, {"Db3", 138.59f},
    {"D3", 146.83f}, {"D#3", 155.56f}, {"Eb3", 155.56f},
    {"E3", 164.81f}, {"Fb3", 164.81f}, {"E#3", 174.61f},
    {"F3", 174.61f}, {"F#3", 185.00f}, {"Gb3", 185.00f},
    {"G3", 196.00f}, {"G#3", 207.65f}, {"Ab3", 207.65f},
    {"A3", 220.00f}, {"A#3", 233.08f}, {"Bb3", 233.08f},
    {"B3", 246.94f}, {"Cb4", 246.94f}, {"B#3", 261.63f},

    // Octave 4
    {"C4", 261.63f}, {"C#4", 277.18f}, {"Db4", 277.18f},
    {"D4", 293.66f}, {"D#4", 311.13f}, {"Eb4", 311.13f},
    {"E4", 329.63f}, {"Fb4", 329.63f}, {"E#4", 349.23f},
    {"F4", 349.23f}, {"F#4", 369.99f}, {"Gb4", 369.99f},
    {"G4", 392.00f}, {"G#4", 415.30f}, {"Ab4", 415.30f},
    {"A4", 440.00f}, {"A#4", 466.16f}, {"Bb4", 466.16f},
    {"B4", 493.88f}, {"Cb5", 493.88f}, {"B#4", 523.25f},

    // Notes without octave (defaulting to octave 4)
    {"C", 261.63f}, {"C#", 277.18f}, {"Db", 277.18f},
    {"D", 293.66f}, {"D#", 311.13f}, {"Eb", 311.13f},
    {"E", 329.63f}, {"Fb", 329.63f}, {"E#", 349.23f},
    {"F", 349.23f}, {"F#", 369.99f}, {"Gb", 369.99f},
    {"G", 392.00f}, {"G#", 415.30f}, {"Ab", 415.30f},
    {"A", 440.00f}, {"A#", 466.16f}, {"Bb", 466.16f},
    {"B", 493.88f}, {"Cb", 493.88f}, {"B#", 523.25f}
};

struct Tone
{
    
    float freq;
    float timestamp;
    float duration;
    size_t buttonIndex;

    Tone(float _freq, float _timestamp, float _duration, size_t _buttonIndex)
        : freq(_freq), timestamp(_timestamp), duration(_duration), buttonIndex(_buttonIndex) {}

    Tone(const std::string& _name, float _timestamp, float _duration, size_t _buttonIndex)
     : timestamp(_timestamp), duration(_duration), buttonIndex(_buttonIndex)
    {
        auto it = noteFrequencies.find(_name);
        freq = (it != noteFrequencies.end()) ? it->second : 0.0f;
    }

    static Tone createTone(const std::string& name, float timestamp, float duration, size_t buttonIndex)
    {
        return Tone(name, timestamp, duration, buttonIndex);
    }

    bool operator<(const Tone& other) const
    {
        return timestamp < other.timestamp;
    }
};
#endif