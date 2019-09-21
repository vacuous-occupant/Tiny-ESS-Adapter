# Tiny-ESS-Adapter
Compact ESS adapter powered by Atmel ATTiny
**Currently for Ocarina of Time on Wii Virtual Console only**

## 1. Introduction
Wii Virtual Console (VC) is currently the fastest platform in many categories of Ocarina of Time speedrunning. This is due to version-specific glitches, as well as decreased loading times. There is a critical problem with this: VC actually remaps your analog stick inputs. This drastically increases the difficulty of all variations of the Extended Super Slide (ESS.) It also makes it much more difficult to aim first person items such as the hookshot and the bow.

An ESS adapter is a device which modifies your controller inputs, and then feeds the modified inputs into your console, in an attempt to reverse VC's remap of your analog stick. It can also do things like remap your buttons.

## 2. Adapter Rules
Taken from the Ocarina of Time Speedrunning discord: [https://discord.gg/DfjKaQ](https://discord.gg/DfjKaQ)
-Analog signals are mapped only to analog signals.
-Digital signals can be mapped to analog, but not the reverse. 
-The control stick output must be a monotonically increasing sequence. In other words, if one input value is greater than or equal to another input value, their respective outputs must share that relationship. This preserves the ordering of deadzone → ESS → walking → running.
-Minimum input must be mapped to minimum output. In other words, neutral must map to neutral.
-The adapter may not add or remove functionality to the game. Turbo, macros, and mapping multiple input sources to movement are examples of added functionality. Mapping the entire stick to ESS is an example of loss of functionality.  Link must retain all of his normally accessible actions and movement options.

-to be continued-
