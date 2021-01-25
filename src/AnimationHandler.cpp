#include "../Headers/AnimationHandler.h"

void AnimationHandler::update(const float dt) {
	if (currentAnimation >= this->animations.size() || currentAnimation < 0) return;
	float duration = this->animations[currentAnimation].duration;

	// Check if the animation has progressed to a new frame and if so change to the next frame
	if (int((time + dt) / duration) > int(time / duration)) {
		// Calculate the frame number
		int frame = int((time + dt) / duration);
		
		// Adjust for looping
		frame %= this->animations[currentAnimation].getLength();

		// Set the sprite to the new frame
		sf::IntRect rect = this->frameSize;
		rect.left = rect.width * frame;
		rect.top = rect.height * this->currentAnimation;
		this->bounds = rect;
	}

	// Increment the time elapsed
	this->time += dt;

	// Adjust for looping
	if (this->time > duration * this->animations[currentAnimation].getLength()) {
		this->time = 0.0f;
	}
}

void AnimationHandler::addAnimation(Animation& animation) {
	this->animations.push_back(animation);
}

void AnimationHandler::changeAnimation(unsigned int animationID) {
	// Do not change the animation if the animation is currently active or the new animation does not exist
	if (this->currentAnimation == animationID || animationID >= this->animations.size() || animationID < 0) return;

	// Set the current animation
	this->currentAnimation = animationID;

	// Update the animation bounds
	sf::IntRect rect = this->frameSize;
	rect.top = rect.height * animationID;
	this->bounds = rect;
	this->time = 0.0f;
}