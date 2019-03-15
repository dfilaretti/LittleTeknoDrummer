/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LittleTeknoDrummerAudioProcessorEditor::LittleTeknoDrummerAudioProcessorEditor (LittleTeknoDrummerAudioProcessor& p)
    : AudioProcessorEditor (&p), 
	  processor (p), 
	  oscSectionGui    (p, 4, 2, "Oscillator", Colours::black), 
	  noiseSectionGui  (p, 4, 1, "Noise",      Colours::black),
	  masterSectionGui (p, 4, 1, "Master",     Colours::black)
{
	setLookAndFeel (&lookAndFeel);

	setSize (kWidth, kHeight);
	addAndMakeVisible (oscSectionGui);
	addAndMakeVisible (masterSectionGui);
	addAndMakeVisible (noiseSectionGui);
	 
	initResetButton();
	initRandomButton();


	// setup version slider
	versionLabel.setColour(Label::textColourId, Colours::black);
	versionLabel.setFont(Font(16.0f, Font::bold));
	versionLabel.setText("Version 0.1.1", dontSendNotification);
	versionLabel.setJustificationType(Justification::right);
	addAndMakeVisible(versionLabel);
}



LittleTeknoDrummerAudioProcessorEditor::~LittleTeknoDrummerAudioProcessorEditor() 
{ 
	setLookAndFeel (nullptr); 
}

//==============================================================================
void LittleTeknoDrummerAudioProcessorEditor::paint (Graphics& g)
{
	g.fillAll (Colours::lightgrey);

	// draw title area
	auto area = getLocalBounds();
	auto headerArea = area.removeFromTop(kTitleHeight).reduced(8);
	auto titleArea = headerArea.removeFromLeft (area.getWidth() / 2);
	auto creditsArea = headerArea;
	creditsArea.removeFromRight(4);

	// draw title
	g.setColour(Colours::black);
	g.setFont(Font(40.0f, Font::bold));
	titleArea.removeFromLeft(4);
	g.drawText("WeirdDrums", titleArea, Justification::left, true);

	// draw credits
	
	g.setColour(Colours::black);
	g.setFont(Font(16.0f, Font::bold));

	g.drawText("www.danielefilaretti.com", 
		       creditsArea,
		       Justification::bottomRight, true);
}

void LittleTeknoDrummerAudioProcessorEditor::resized()
{
	auto area = getLocalBounds();
	auto width = area.getWidth();

	auto titleArea = area.removeFromTop(kTitleHeight);

	auto buttonWidth = (width - 8) / 4;
	auto bottomArea = area.removeFromBottom(kTitleHeight).reduced (8, 0);
	bottomArea.removeFromBottom(8);
	auto button1Area = bottomArea.removeFromLeft(buttonWidth).reduced(10, 2);
	auto button2Area = bottomArea.removeFromLeft(buttonWidth).reduced(10, 2);
	auto versionArea = bottomArea.removeFromLeft(buttonWidth * 2);


	auto mainArea = area.reduced(4);
	
	// setup main area
	oscSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 2));
	noiseSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 4));
	masterSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 4));

	// setup bottom area
	resetButton.setBounds (button1Area);
	randomButton.setBounds (button2Area);

	versionLabel.setBounds (versionArea);
}

//==============================================================================
void LittleTeknoDrummerAudioProcessorEditor::initResetButton()
{
	resetButton.onClick = [&]()
	{
		auto paramsToReset =
		{
			"FREQ",
			"ATTACK",
			"DECAY",
			"WAVE-TYPE",
			"PITCH-ENV-AMOUNT",
			"PITCH-ENV-RATE",
			"PITCH-LFO-AMOUNT",
			"PITCH-LFO-RATE",
			"FILTER-TYPE",
			"FILTER-CUTOFF",
			"FILTER-RESONANCE",
			"NOISE-ATTACK",
			"NOISE-DECAY",
			"MASTER-MIX",
			"MASTER-DISTORT",
			"MASTER-LEVEL"
		};

		for (auto paramtoReset : paramsToReset)
		{
			auto param = dynamic_cast<juce::AudioProcessorParameterWithID*>(processor.parameters.getParameter(paramtoReset));
			auto defaultValueNormalised = param->getDefaultValue();
			param->setValueNotifyingHost(defaultValueNormalised);
		}
	};

	addAndMakeVisible(resetButton);
	resetButton.setButtonText("Init");
}

void LittleTeknoDrummerAudioProcessorEditor::initRandomButton()
{
	randomButton.onClick = [&]()
	{
		auto paramsToReset =
		{
			"FREQ",
			"ATTACK",
			"DECAY",
			"WAVE-TYPE",
			"PITCH-ENV-AMOUNT",
			"PITCH-ENV-RATE",
			"PITCH-LFO-AMOUNT",
			"PITCH-LFO-RATE",
			"FILTER-TYPE",
			"FILTER-CUTOFF",
			"FILTER-RESONANCE",
			"NOISE-ATTACK",
			"NOISE-DECAY",
			"MASTER-MIX",
			"MASTER-DISTORT"
			//"MASTER-LEVEL"
		};

		for (auto paramtoReset : paramsToReset)
		{
			auto param = dynamic_cast<juce::AudioProcessorParameterWithID*>(processor.parameters.getParameter(paramtoReset));
			auto randomValueNormalised = randomNumberGenerator.nextFloat();
			param->setValueNotifyingHost(randomValueNormalised);
		}
	};

	addAndMakeVisible(randomButton);
	randomButton.setButtonText("Rand");
}