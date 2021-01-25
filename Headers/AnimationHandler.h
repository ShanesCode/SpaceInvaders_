#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
	unsigned int startFrame;
	unsigned int endFrame;

	float duration;

	Animation(unsigned int startFrame, unsigned int endFrame, float duration) {
		this->startFrame = startFrame;
		this->endFrame = endFrame;
		this->duration = duration;
	}

	unsigned int getLength() {
		return endFrame - startFrame + 1;
	}
};

class AnimationHandler {
private:
	// Array of animations
	std::vector<Animation> animations;
	
	// Current time since the animation loop started
	float time;

	int currentAnimation;

public:
	// Add a new animation
	void addAnimation(Animation& animation);

	// Update the current frame of the animation. dt is the time since the update was last called (ie the time for one frame to be executed)
	void update(const float dt);

	// Change the animation, resetting time in the process
	void changeAnimation(unsigned int animationNumber);

	// Current section of the texture that should be displayed
	sf::IntRect bounds;

	// Pixel dimensions of each individual frame
	sf::IntRect frameSize;

	// Constructor
	AnimationHandler() {
		this->time = 0.0f;
		this->currentAnimation = -1;
	}

	AnimationHandler(const sf::IntRect& frameSize) {
		this->frameSize = frameSize;

		this->time = 0.0f;
		this->currentAnimation = -1;
	}
};