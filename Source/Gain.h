#pragma once

class Gain
{
public:
        
    Gain();
    ~Gain();
    
    void processGain(float* inAudioGain, float inGain, float* outAudioGain, int inNumSamplestoRender);
        
private:
    
};
