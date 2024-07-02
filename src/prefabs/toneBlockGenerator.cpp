#ifndef _TONE_BLOCK_GENERATOR_CPP
#define _TONE_BLOCK_GENERATOR_CPP

#include <smash.h>
#include "../types/song.cpp"
#include "toneBLock.cpp"

class ToneBlockGenerator : public smash::GameObject
{
    Song m_song;
public:
    ToneBlockGenerator(Song song) : m_song(song)
    {
        constexpr float waitUntilSong = 5.0f;
        constexpr size_t toneCacheSize = 40;

        // Initialize tone block
        for (int x = 0; x < toneCacheSize; x++)
        {
            Tone tone = m_song.getNextTone();
            smash::Vector2 position = smash::Vector2(tone.timestamp + 64 - waitUntilSong * ToneBlock::s_Speed, tone.buttonIndex * 4);
            auto toneBlock = std::make_shared<ToneBlock>(m_song.getNextTone(), position, tone.duration * ToneBlock::s_Speed);
            toneBlock->setGeneratorForCallback(this);
            getScene()->instantiate(toneBlock);
        }
        
    }
};

#endif