/*
  ==============================================================================

    TopPanel.h
    Created: 28 Jan 2020 10:48:13pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#pragma once
#include "PanelBase.h"

class TopPanel
:   public PanelBase
{
public:
    
    TopPanel(EspaciadorAudioProcessor* inProcessor);
    ~TopPanel();
    
    void paint(Graphics& g) override;
    
private:
    
    
    
};
