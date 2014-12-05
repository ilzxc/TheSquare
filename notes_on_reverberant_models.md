# notes on reverberant models


### Preamble

The reverberation problem is remarkably expensive to compute using brute-force or physical modeling approaches. The problem can be simplified without sacrificing perceptual quality. Some observations:

1. For typical rooms, the echo density increases as $$${t^2}$$$, where $$${t}$$$ is time.
2. The number of resonant modes in any given frequency band $$${f}$$$ increases as $$${f^2}$$$.

The implications are for [1] - beyond some time, the echo density is so great that it can be modeled as some uniformly sampled stochastic process (without loss of perceptual fidelity). As for [2] - above some frequency, the modes are so dense that they are perceptually equivalent to a *random frequency response* generated (presumably according to some statistics).

Thus, the ***impulse response*** of a reverberant room can be divided into two segments. The first segment consists of *early reflections* (relatively sparse first echoes in the impulse response). The remainder, *late reverberation* is so densely populated with echoes that it is best to characterize the response *statistically*. The ***frequency response*** of a room similarly divides into two segments. The low-frequency interval consists of a relatively sparse distribution of resonant models, while at higher frequencies the modes are packed so densely that they are best characterized as a random frequency response with regular statistical properties.

The controls for artificial reverberation include:

* $$${t_60 (f) \rightarrow}$$$ desired reverberation time at each frequency $$${f}$$$
* $$${G^2 (f) \rightarrow}$$$ signal power gain at each frequency
* $$${C(f) \rightarrow}$$$ "clarity" - ratio of impulse-response energy in early reflections to that in late reverb
* $$${\rho(f) \rightarrow}$$$ *interaural correlation coefficient* at left & right ears

It is common to design for a given $$${t_60}$$$ at more than one frequency - one for low, another for high, and interpolated values at intermediate frequencies. Perceptual studies suggest that reverberation time should be independently adjustable in at least three frequency bands.

### Energy Decay Curve

The *energy decay curve* is the *tail integral* of the squared impulse response at time $$${t}$$$:

$${ EDC(t) = \int_t^\infty h^2 (\tau)d\tau}$$

The $$${EDC(t)}$$$ is the total amount of signal energy remaining in the reverberator impulse response at time $$${t}$$$.

