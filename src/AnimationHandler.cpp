#include "..\Headers\AnimationHandler.h"

// Constructor
AnimationHandler::AnimationHandler() {
	time = 0.0f;
	currentAnimation = -1;
}

AnimationHandler::AnimationHandler(const sf::IntRect& frameSize_) {
	frameSize = frameSize_;

	time = 0.0f;
	currentAnimation = -1;
}

void AnimationHandler::update(const float dt) {
	if (currentAnimation >= animations.size() || currentAnimation < 0) return;
	float frame_duration = animations[currentAnimation].frame_duration;

	// Check if the animation has progressed to a new frame and if so change to the next frame
	if (int((time + dt) / frame_duration) > int(time / frame_duration)) {
		// Calculate the frame number
		int frame = int((time + dt) / frame_duration);
		
		// Adjust for looping
		frame %= animations[currentAnimation].getLength();

		// Set the sprite to the new frame
		sf::IntRect rect = frameSize;
		rect.left = rect.width * frame;
		rect.top = rect.height * currentAnimation;
		bounds = rect;
	}

	// Increment the time elapsed
	time += dt;

	// Adjust for looping
	if (time > frame_duration * animations[currentAnimation].getLength()) {
		time = 0.0f;
	}
}

void AnimationHandler::addAnimation(Animation& animation) {
	animations.push_back(animation);
}

void AnimationHandler::changeAnimation(unsigned int animationID) {
	// Do not change the animation if the animation is currently active or the new animation does not exist
	if (currentAnimation == animationID || animationID >= animations.size() || animationID < 0) return;

	// Set the current animation
	currentAnimation = animationID;

	// Update the animation bounds
	sf::IntRect rect = frameSize;
	rect.top = rect.height * animationID;
	bounds = rect;
	time = 0.0f;
}