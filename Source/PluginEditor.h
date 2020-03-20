#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "MainPanel.h"
#include "LookAndFeel.h"
#include "Background.h"

class EspaciadorAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    
    EspaciadorAudioProcessorEditor (EspaciadorAudioProcessor&);
    ~EspaciadorAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void initializeGUI();

private:

    EspaciadorAudioProcessor& processor;
    ScopedPointer<MainPanel> mMainPanel;
    
    JSVLookAndFeel jsvLookAndFeel;
    
    Slider sliderInput;
    Slider sliderTheta;
    Slider sliderAxisX;
    Slider sliderAxisY;
    Slider sliderCutOffHigh;
    Slider sliderCutOffLow;
    Slider sliderResHigh;
    Slider sliderResLow;
    Slider sliderOutput;

    ComboBox boxChoiceChannels;
    
    Label labelInput;
    Label labelTheta;
    Label labelAxisX;
    Label labelAxisY;
    Label labelCutOffHigh;
    Label labelCutOffLow;
    Label labelResHigh;
    Label labelResLow;
    Label labelOutput;
    
    Image mBackgroundImage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EspaciadorAudioProcessorEditor)
};
