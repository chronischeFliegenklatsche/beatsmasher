#ifndef _SMASH_SPEAKER_H
#define _SMASH_SPEAKER_H

#include <Arduino.h>
#include <vector>

namespace smash
{
    class Speaker
    {
        static std::vector<int> s_availablePwmChannels;
        int m_pwmChannel;
        int m_pin;
        int m_index;
        int getAvailablePwmChannel();
    public:
        Speaker(int pin, int index);
        ~Speaker() = default;
        void playTone(note_t note, int octave);
        void stop();
    };
}

#endif