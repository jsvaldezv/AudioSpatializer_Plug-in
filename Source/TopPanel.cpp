/*
  ==============================================================================

    TopPanel.cpp
    Created: 28 Jan 2020 10:48:13pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#include "TopPanel.h"


TopPanel::TopPanel(EspaciadorAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}

TopPanel::~TopPanel()
{
    
}

void TopPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    g.setFont(font_2);
    
    const int label_W = 220;
    
    //g.drawFittedText("PLUGIN ESPACIALIZADOR", TOP_PANEL_WIDTH - label_W, 0, label_W, getHeight(), Justification::centred, 1);
    //g.drawFittedText("PLUGIN ESPACIALIZADOR", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
}
