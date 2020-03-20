/*
  ==============================================================================

    PanelBase.h
    Created: 28 Jan 2020 10:45:37pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "InterfaceDefines.h"

class PanelBase
: public Component
{
public:
    
    PanelBase(EspaciadorAudioProcessor* inProcessor);
    ~PanelBase();
    
    void paint (Graphics& g) override;

protected:
    
    EspaciadorAudioProcessor* mProcessor;
    
};
