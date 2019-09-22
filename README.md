# Tiny-ESS-Adapter
Compact ESS adapter powered by Atmel ATTiny

**Currently for Ocarina of Time on Wii Virtual Console only**

## 1. Introduction
Wii Virtual Console (VC) is currently the fastest platform in many categories of Ocarina of Time speedrunning. This is due to version-specific glitches, as well as decreased loading times. There is a critical problem with this: VC actually remaps your analog stick inputs. This drastically increases the difficulty of all variations of the Extended Super Slide (ESS.) It also makes it much more difficult to aim first person items such as the hookshot and the bow.

An ESS adapter is a device which modifies your controller inputs, and then feeds the modified inputs into your console, in an attempt to reverse VC's remap of your analog stick. It can also do things like remap your buttons.

## 2. Adapter Rules
Taken from the Ocarina of Time Speedrunning discord: [https://discord.gg/DfjKaQ](https://discord.gg/DfjKaQ)
* Analog signals are mapped only to analog signals.
* Digital signals can be mapped to analog, but not the reverse. 
* The control stick output must be a monotonically increasing sequence. In other words, if one input value is greater than or equal to another input value, their respective outputs must share that relationship. This preserves the ordering of deadzone → ESS → walking → running.
* Minimum input must be mapped to minimum output. In other words, neutral must map to neutral.
* The adapter may not add or remove functionality to the game. Turbo, macros, and mapping multiple input sources to movement are examples of added functionality. Mapping the entire stick to ESS is an example of loss of functionality.  Link must retain all of his normally accessible actions and movement options.

## 3. 1D vs 2D Remap
A gamecube controller has a range of 0 to 255 on each axis. For the sake of human readability, we will use the scale -127 to 127 instead. For example, the neutral position on the thumbstick would be 0,0. Straight forward would be 0,127. Left is -127,0, etc.
However, due to the plastic controller casing, the actual highest attainable value for the cardinal directions is more like 105, and the diagonals are around 75.
### 2-dimensional Remap
Since each axis has 256 possible values, there are a total of 65,566 possible coordinates (256x256) on a gamecube controller stick. Though again, due to the controller casing its actually closer to 32,000. A 2D remap changes every point on the 2 dimensional spectrum of coordinates to another set of coordinates. There are some programming tricks to reduce this number by 1/4, but at a minimum you would need a remap table of at least 8,000 modified coordinates programmed on your ESS adapter for a full 2D remap.
### 1-dimensional Remap
A 1D remap reduces this to 128 values. Instead of remapping every point in the spectrum of points, you simply remap every point on the axis. That would be a total of 512 values (256+256), however we can reduce that by 1/4 using the same programming tricks mentioned above.
### Which is better?
It depends on who you ask, but based on the data I've gathered, I believe they are exactly identical.

-to be continued-
