/*
  ==============================================================================

    SpacerPanel.h
    Created: 28 Jan 2020 11:52:33pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#pragma once
#include "PanelBase.h"

enum SpacerPanelStyle
{
    SpacerPanelStyle_TWO,
    SpacerPanelStyle_FOUR,
    SpacerPanelStyle_EIGHT,
    SpacerPanelStyle_TotalNumStyle
};

class SpacerPanel
:   public PanelBase
{
public:
    
    SpacerPanel(EspaciadorAudioProcessor* inProcessor);
    ~SpacerPanel();
    
    void paint(Graphics& g) override;
    
    void setSpacerPanelStyle(SpacerPanelStyle inStyle);
    
private:
    
    SpacerPanelStyle mStyle;
    
};

