/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Wk1exampleProjectVstAudioProcessor::Wk1exampleProjectVstAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

Wk1exampleProjectVstAudioProcessor::~Wk1exampleProjectVstAudioProcessor()
{
}

//==============================================================================
const String Wk1exampleProjectVstAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Wk1exampleProjectVstAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Wk1exampleProjectVstAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Wk1exampleProjectVstAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Wk1exampleProjectVstAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Wk1exampleProjectVstAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Wk1exampleProjectVstAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Wk1exampleProjectVstAudioProcessor::setCurrentProgram (int index)
{
}

const String Wk1exampleProjectVstAudioProcessor::getProgramName (int index)
{
    return {};
}

void Wk1exampleProjectVstAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Wk1exampleProjectVstAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    // Setup stuff
}

void Wk1exampleProjectVstAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    // Cleanup code goes here
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Wk1exampleProjectVstAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Wk1exampleProjectVstAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    // Where the work happens
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state. (don't worry about trying to do that for the moment)
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        // put channel 0 audio buffer into channelData variable
        // put channel 0 audio buffer into channelData variable
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            channelData[sample] = random.nextFloat() - 1;
        }
        
    }
}

//==============================================================================
bool Wk1exampleProjectVstAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Wk1exampleProjectVstAudioProcessor::createEditor()
{
    return new Wk1exampleProjectVstAudioProcessorEditor (*this);
}

//==============================================================================
void Wk1exampleProjectVstAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Wk1exampleProjectVstAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Wk1exampleProjectVstAudioProcessor();
}
