# swordfight
sword thingy3 ESP32s, 2 swords + 1 hub. you swing, you clash, the hub keeps score. 

how it detects hits
each sword has an MPU6050 strapped in. when the blades clash, the accelerometer picks up a sharp spike (sudden stop = spike). no contact sensors hopefully it will just watch for the spike pattern. debounce it so one clash doesn't count as five. 

how scoring works
a clash happens on both swords simultaneously (woah), so instead of "who hit first" (doesnt make sense for a clash) we would compare who swung harder (?) bigger impact magnitude wins that exchange. close calls (withinn ~10%?) = no winner, just a "clang", but nobody's combo breaks.

winning streaks build a combo multiplier. lose a clash (or tie) and it resets, so momentum matters, you have to keep swinging hard to protect a streak.

health bar drains based on clash losses, scaled by the other guy's combo. first to zero (or whoever's ahead when time's up) wins.

the lights
alexren says they have WS2812 led strips, so each sword gets one like on the blade or something

* idle color = which player 
* pulses brighter as your combo builds 
* flashes on impact
* dims as you take damage, so the sword itself doubles as a health readout


hub might get a strip too for a bigger shared health/score display, visible from far away.

the mesh
swords talk to the hub over ESP-NOW so theres no wifi router needed, low latency, works fine in a packed venue with either no wifi or its really bad :pf:

stretch goals

* laptop dashboard over websocket, live health/combo feed, like a sword visualizer on screen from like general orientation
* sound effects of the speaker for clashes
* integrate a web cam or something for position tracking on screen (maybe idk if there will be webcams there)

