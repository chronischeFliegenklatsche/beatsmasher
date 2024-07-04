#include <smash.h>

namespace smash
{

    void ToneSource::setNote(note_t note)
    {
        m_note = note;
    }

    note_t ToneSource::getNote() const
    {
        return m_note;
    }

    void ToneSource::setOctave(int octave)
    {
        m_octave = octave;
    }

    int ToneSource::getOctave() const
    {
        return m_octave;
    }

    void ToneSource::setDuration(float duration)
    {
        m_duration = duration;
    }

    float ToneSource::getDuration() const
    {
        return m_duration;
    }

    void ToneSource::setSpeakerIndex(int speakerPin)
    {
        m_speakerIndex = speakerPin;
    }

    int ToneSource::getSpeakerIndex() const
    {
        return m_speakerIndex;
    }

    void ToneSource::play()
    {
        ledcAttachPin(2, 0);
        ledcWriteNote(0, m_note, m_octave);
        t_timeCount = 0;
    }

    void ToneSource::abort()
    {

    }   

    void ToneSource::update(double deltaTime)
    {
        if (t_timeCount >= 0)
        {
            t_timeCount += deltaTime;
            if (t_timeCount >= m_duration)
            {
                abort();
                t_timeCount = -1;
            }
        }
    }
}