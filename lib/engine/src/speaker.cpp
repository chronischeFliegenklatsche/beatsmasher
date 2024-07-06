#include <smash.h>

namespace smash
{

    std::vector<int> Speaker::s_availablePwmChannels = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    Speaker::Speaker(int pin, int index) : m_pin(pin), m_index(index), m_pwmChannel(getAvailablePwmChannel())
    {
        ledcAttachPin(m_pin, m_pwmChannel);
    }

    int Speaker::getAvailablePwmChannel()
    {
        int pwmChannel = s_availablePwmChannels.back();
        s_availablePwmChannels.pop_back();
        return pwmChannel;
    }

    void Speaker::playTone(note_t note, int octave)
    {
        ledcWriteNote(m_pwmChannel, note, octave);
    }

    void Speaker::stop()
    {
        ledcWriteTone(m_pwmChannel, 0);
    }
}