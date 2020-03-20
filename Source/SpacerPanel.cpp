/*
  ==============================================================================

    SpacerPanel.cpp
    Created: 28 Jan 2020 11:52:33pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#include "SpacerPanel.h"
#include "PluginEditor.h"

SpacerPanel::SpacerPanel(EspaciadorAudioProcessor* inProcessor)
:   PanelBase(inProcessor),
    mStyle(SpacerPanelStyle_TWO)
{
    setSize(SPACER_PANEL_WIDTH, SPACER_PANEL_HEIGHT);
}

SpacerPanel::~SpacerPanel()
{
    
}

void SpacerPanel::setSpacerPanelStyle(SpacerPanelStyle inStyle)
{
    mStyle = inStyle;
}

void SpacerPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    /*switch (mStyle)
    {
        case(SpacerPanelStyle_TWO):
        {
            g.drawFittedText("TWO CHANNELS", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
        } break;
        
        case(SpacerPanelStyle_FOUR):
        {
            g.drawFittedText("FOUR CHANNELS", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
        } break;
            
        case(SpacerPanelStyle_EIGHT):
        {
            g.drawFittedText("EIGHT CHANNELS", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
        } break;
        
        default:
        case(SpacerPanelStyle_TotalNumStyle):
        {
            //RIP
            g.drawFittedText("FUCK", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
            jassertfalse;
        } break;
    }*/
}
