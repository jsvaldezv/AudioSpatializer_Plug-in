/*
  ==============================================================================

    GainPanel.cpp
    Created: 28 Jan 2020 10:46:49pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#include "GainPanel.h"

GainPanel::GainPanel(EspaciadorAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}

GainPanel::~GainPanel()
{
    
}
