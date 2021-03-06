/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Wk1exampleProjectVstAudioProcessorEditor::Wk1exampleProjectVstAudioProcessorEditor (Wk1exampleProjectVstAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    setSize (400, 300);
}

Wk1exampleProjectVstAudioProcessorEditor::~Wk1exampleProjectVstAudioProcessorEditor()
{
}

//==============================================================================
void Wk1exampleProjectVstAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    // This draws what we see when we boot VST.
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void Wk1exampleProjectVstAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // Lay out positions of elements so they resize nicely.  Don't do static because that is
    // oldschool and lame.
}
