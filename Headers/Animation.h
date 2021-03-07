#pragma once
class Animation {
public:
	unsigned int startFrame;
	unsigned int endFrame;

	float duration;

	Animation(unsigned int startFrame_, unsigned int endFrame_, float duration_);

	unsigned int getLength();
};
