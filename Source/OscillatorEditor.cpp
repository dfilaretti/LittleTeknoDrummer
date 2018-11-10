/*
  ==============================================================================

    OscillatorEditor.cpp
    Created: 6 Nov 2018 2:36:24pm
    Author:  dfila

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "OscillatorEditor.h"

//==============================================================================
OscillatorEditor::OscillatorEditor(PatSynthAudioProcessor& p) 
	: processor(p)
{
	// setup size
	setSize(kWidth, kHeight);

	// setup combo box
	oscComboBox.addItem(kMenuItemSineText,   kMenuItemSineId);
	oscComboBox.addItem(kMenuItemSawText,    kMenuItemSawId);
	oscComboBox.addItem(kMenuItemSquareText, kMenuItemSquareId);
	oscComboBox.setJustificationType(Justification::centred);
	addAndMakeVisible(&oscComboBox);
	oscComboBoxAttachment = new ComboBoxAttachment(
		processor.parameters, 
		Globals::paramIdWaveType, 
		oscComboBox);
}

OscillatorEditor::~OscillatorEditor()
{
}

void OscillatorEditor::paint (Graphics& g)
{
	//background stuff
	juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);

	g.fillAll(Colours::black);
	g.setColour(Colours::white);
	g.drawText("Oscillator One", titleArea, Justification::centredTop);


	juce::Rectangle <float> area(25, 25, 150, 150);

	g.setColour(Colours::yellow);
	g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void OscillatorEditor::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(40);
	oscComboBox.setBounds(area.removeFromTop(20));
}
