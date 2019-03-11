/*
  ==============================================================================

    MasterSectionEditor.h
    Created: 6 Nov 2018 3:44:06pm
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "LookAndFeels.h"
#include "LtdComplexComponent.h"
#include "LtdRotarySlider.h"

//==============================================================================

class MasterSectionEditor    : public LtdComplexComponent
{
public:
	MasterSectionLookAndFeel lookAndFeel;

    MasterSectionEditor(LittleTeknoDrummerAudioProcessor&, int, int);
    ~MasterSectionEditor();

private:
	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

	//==============================================================================
	LtdRotarySlider mixSlider{ juce::String("Mix") };
	LtdRotarySlider eqFreqSlider{ juce::String("Eq Freq") };
	LtdRotarySlider distortSlider{ juce::String("Distort") };
	LtdRotarySlider eqGainSlider{ juce::String("Eq Gain") };
	LtdRotarySlider levelSlider{ juce::String("Level") };
	LtdRotarySlider panSlider{ juce::String("Pan") };

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterSectionEditor)
};
