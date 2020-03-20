/*
  ==============================================================================

    InterfaceDefines.h
    Created: 28 Jan 2020 10:59:03pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/
#include "JuceHeader.h"

#pragma once

#define MAIN_PANEL_WIDTH                750
#define MAIN_PANEL_HEIGHT               300

#define TOP_PANEL_WIDTH                 MAIN_PANEL_WIDTH
#define TOP_PANEL_HEIGHT                45

#define GAIN_PANEL_WIDTH                100
#define GAIN_PANEL_HEIGHT               MAIN_PANEL_HEIGHT - TOP_PANEL_HEIGHT

#define CENTER_PANEL_WIDTH              MAIN_PANEL_WIDTH - (GAIN_PANEL_WIDTH * 2)
#define CENTER_PANEL_HEIGHT             GAIN_PANEL_HEIGHT

#define CENTER_PANEL_MENU_BAR_WIDTH     CENTER_PANEL_WIDTH
#define CENTER_PANEL_MENU_BAR_HEIGHT    35

#define SPACER_PANEL_WIDTH              CENTER_PANEL_WIDTH
#define SPACER_PANEL_HEIGHT             CENTER_PANEL_HEIGHT - CENTER_PANEL_MENU_BAR_HEIGHT

const Font font_1 ("Helvetica Neue", 12.00f, Font::bold);
const Font font_2 ("Helvetica Neue", 22.00f, Font::bold);
const Font font_3 ("Helvetica Neue", 48.00f, Font::bold);
