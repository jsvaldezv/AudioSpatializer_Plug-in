#include "Gain.h"
#include "JuceHeader.h"

Gain::Gain()
{
    
}

Gain::~Gain()
{
    
}

void Gain::processGain(float* inAudioGain, float inGain, float* outAudioGain, int inNumSamplestoRender)
{
    float gainMapped = jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = Decibels::decibelsToGain(gainMapped, -24.0f);
    
    for(int i=0; i < inNumSamplestoRender; i++)
    {
        outAudioGain[i] = inAudioGain[i] * gainMapped;
    }
}
