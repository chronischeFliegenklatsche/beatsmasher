#ifndef _SONG_CPP
#define _SONG_CPP

#include <set>
#include "tone.cpp"

class Song
{
protected:
    std::set<Tone> m_tones;
    Song() = default;
public:
    virtual ~Song() = default;

    void addTone(Tone tone)
    {
        m_tones.insert(tone);
    }

    Tone getNextTone()
    {
        Tone nextTone = *m_tones.begin();
        m_tones.erase(m_tones.begin());
        return nextTone;
    }
    
};

#endif