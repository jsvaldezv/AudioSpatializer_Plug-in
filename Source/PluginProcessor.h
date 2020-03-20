#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Gain.h"
#include "Spacer.h"

class EspaciadorAudioProcessor  : public AudioProcessor
{
public:

    EspaciadorAudioProcessor();
    ~EspaciadorAudioProcessor();

//==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

//==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

//==============================================================================
    const String getName() const override;
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

//==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

//==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void updateFilter();

private:
    
    //void initializeDSP();

    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> highPassFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> lowPassFilter;
    
    float lastSampleRate;
    
    //ScopedPointer<Gain> oInputGain [8];
    //ScopedPointer<Gain> oOutputGain [8];
    //ScopedPointer<Spacer> oSpacer [8];
    
    AudioParameterFloat* mInputGain;
    AudioParameterFloat* mParameterTheta;
    AudioParameterFloat* mParameterX;
    AudioParameterFloat* mParameterY;
    AudioParameterInt* mChoiceChannels;
    AudioParameterFloat* mParameterCutOffHigh;
    AudioParameterFloat* mParameterCutOffLow;
    AudioParameterFloat* mParameterResHigh;
    AudioParameterFloat* mParameterResLow;
    AudioParameterFloat* mOutputGain;
    
//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EspaciadorAudioProcessor)
};
