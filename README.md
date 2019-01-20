# Little Tekno Drummer (LTD)

A simple drum synthesiser plugin inspired by the awesome [Sonic Charge Microtonic](https://soniccharge.com/microtonic), one of my favourite plugins. All sounds are synthesised in realtime - no samples used. 

It is written in C++ and the [JUCE](https://juce.com/) framework. 

![Screenshot](media/img/screenshot-medium.png)

Here some audio examples (more to come!):

* [Example 1](https://dfilaretti.github.io/assets/loop1.wav)
* [Example 2](https://dfilaretti.github.io/assets/loop2.wav)
* [Example 3](https://dfilaretti.github.io/assets/loop3.wav)

## Architecture / how to use

As in the original Mictoronic, the architecture is quite simple. 
We have essentially an _oscillator_ section and a _noise_ section, which gets mixed together and finally processed in the _master_ section. 
In a bit more detail...

* **oscillator section**: oscillator -> Attack-Decay (AD) envelope. Oscillator waveform can be sine, saw or square. If desired, the oscillator pitch can be modulated via a second AD envelope and/or an LFO. More modulation options may become available in future. 

* **noise section**: white noise generator -> filter -> AD envelope. The filter can be Low-Pass (LP), High-Pass (HP) or Band-Pass (BP) and its cutoff frequency and envelope are adjustable via the corresponding sliders. Later: more envelope shapes. 

* **master section**: here the _oscillator_ and _noise_ signal are mixed together (via the _mix_ slider) and some effects and global level/pan are applied. Currently only distortion is available, but we may add more in future. 

## Faq

### Why there is no step-sequencer? And why there aren't multiple "drum pads" like in most other drum instruments?

Yes - one instance of this plugin = 1 single drum sound, and there is no built-in step sequencer, meaning you need to use your DAW's piano roll or editor to input notes. 

Here are some of the reasons for this:

* OK let's be honest here, this started as a learning/practice project, so I wanted to keep it simple :-) 

* Although I'm a big fan of drum synth plugins, I pretty much never use their built-in step sequencer, but instead I rely on my DAW's editor. Related to that, I recently bought an Ableton Push2 meaning the drum sequencing workflow is heavily based on Drum Racks. With this setup an additional step sequencer just be redundant for me. 

* When working on my tracks I often find myself loading a Microtonic just to make a single sound (rather than the full 8-drums drumkit). Or, perhaps, sometimes I only use 4 of the 8 slots, while sometimes I need 50 slots (no, not really). With this approach you get more freedom and flexibility on how you want to use the instrument. Load as many instances as you want, and use/route them in the way you see fit. For example, I like to load a few instances of the synth inside Ableton's Drum Rack, perhaps together with other things such as samples etc. 

Having said that, a step sequencer sounds like a nice future addition and a great learning exercise. 


## Todo / Contributions

Contributions, feature requests, bug reports as well as general feedback and advice are very welcome!

Here are a few needed improvements that comes to mind...

* envelopes are linear, but should be exponential (or, at least, offer the choice!) 
* dedicated envelope type for claps 
* global EQ
* Optimize performance
* Make UI prettier 
* ..... 

Please take a look at the [issues](https://github.com/dfilaretti/LittleTeknoDrummer/issues) and feel free to open new ones is needed. 
