#pragma once
class Animation {
public:
	unsigned int startFrame;
	unsigned int endFrame;

	float frame_duration;

	Animation(unsigned int startFrame_, unsigned int endFrame_, float frame_duration_);

	unsigned int getLength();
};
