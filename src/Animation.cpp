#include "../Headers/Animation.h"

// Constructor
Animation::Animation(unsigned int startFrame_, unsigned int endFrame_, float frame_duration_) {
	startFrame = startFrame_;
	endFrame = endFrame_;
	frame_duration = frame_duration_;
}

// Public functions
unsigned int Animation::getLength() {
	return endFrame - startFrame + 1;
}