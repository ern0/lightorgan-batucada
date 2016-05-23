# lightorgan-batacuda
Arduino controlled 8-relay light organ plays a batacuda.
Prepared for ''ToneAThon'',
internal music competition at Ericsson.
(I will link the video as it will be available.)

## Why batacuda? ##

There is no long list of genres,
which can be played on 8 relays.
March is too square for an already square platform.
Bolero is better, but it is difficult to
implement monoton increasing volume with
8 channels of same rhythm instruments.
Finally, I voted on Batacuda, because there are some
dynamic patterns, which are interesging enough to
fill a cca. 3 minutes song: crescendo,
solo teheme echoed by the choir,
and tempo increase.

## Technical background ##

### Hardware ###

Arduino Nano controls a relay module,
which are switching 8 LED lamps:
red, green, blue, white, red, green, blue, white.
That's all, nothing special here.

### Software ###

The requirement is a program, which plays a song when the
device is turned on.
So, the player use no interrupts,
only `digitalWrite()` and `delay()`
instructions.
It eats up some clock cycle, especially with the wrappers,
but please, no one will hear this delay,
it's a 16 MHz processor.

The `m()` (m for macro) macro sets the values of `v1`..`v8`,
then several `v()` (v for value) function call plays a
8-column pattern with these values.
The series of `v()` calls are generated from
OpenOffice/LibreOffice spreadsheet HTML export.
Writing patterns in text editor was uncomfortable,
that's why I choose spreadsheet, it's
the best pattern editor.
The `v()` function can switch a relay,
or make a quick double-switch.
There are two cases which must be solved:
set the initial state of lamps before a pattern
(see `mut()` and `lit()` functions),
and set (usually turn off) a lamp in a certain
position of the pattern, without using a separate column for it.
These tricks are needed because odd number of switch
leaves the lamp in the opposite state.

Probably, it's not the best method for songwriting,
I almost ran out of 8 columns, but it was
easy to implement and required no separate
editor or even a real player.
I have no further plans with it.

### Take it ###

Download it, tweak it, enjoy.
