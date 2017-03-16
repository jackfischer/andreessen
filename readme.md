# Andreessen
### A simple web browser, written in pure C++, with no external libraries

By [Jack Fischer](https://github.com/jackfischer), [Nik Vanderhoof](https://github.com/nvander1), and [Ethan Schoen](https://github.com/EthanSchoen)

Andreessen is a very bare bones proof of concept that won Cornell University's BigRedHacks in fall 2016. It should built on macOS and Ubuntu without modification and automatically render a demo page.

Supported HTML tags

* p
* div
* img
* span

Supported CSS Properties

* display: block, inline
* background-color
* background: linear-gradient
* margin


In honor of this guy!

![](http://www.newyorker.com/wp-content/uploads/2015/05/150518_r26512-1200-630-06150519.jpg)

### Architecture
We rewrote facilities for the entire stack, ranging from HTTP over TCP socket, to internal algorithms, to render.
![architecture.png](architecture.png)

