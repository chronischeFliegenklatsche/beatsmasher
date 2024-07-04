#ifndef _SMASH_TONE_SOURCE_H
#define _SMASH_TONE_SOURCE_H

#include <string>
#include "component.h"

namespace smash
{
    class ToneSource : public Component
    {
        double t_timeCount = -1;
        int m_speakerIndex;
        note_t m_note;
        int m_octave;
        float m_duration;
    public:
        ToneSource() = default;
        ~ToneSource() override = default;
        std::string getTypeName() const override
        {
            return "ToneSource";
        }

        void setNote(note_t note);
        note_t getNote() const;

        void setOctave(int octave);
        int getOctave() const;

        void setDuration(float duration);
        float getDuration() const;

        void setSpeakerIndex(int speakerIndex);
        int getSpeakerIndex() const;
        
        void play();
        void abort();

        void update(double deltaTime) override;

    };
}

#endif