#include "..\Headers\Animation.h"

// Constructor
Animation::Animation(unsigned int startFrame_, unsigned int endFrame_, float duration_) {
	startFrame = startFrame_;
	endFrame = endFrame_;
	duration = duration_;
}

// Public functions
unsigned int Animation::getLength() {
	return endFrame - startFrame + 1;
}