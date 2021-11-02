#pragma once
#include "Entity.h"

class Building : public Entity, public sf::Drawable, public sf::Transformable {
	private:
		sf::Texture tex;
		sf::VertexArray vertices;
		std::vector<bool> active_pixels;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			// apply the transform
			states.transform *= getTransform();

			// draw the vertex array
			target.draw(vertices, states);
		}

		void CreateVertexStructure();
	public:
		unsigned int width;
		unsigned int height;

		void onCollision() override;
		void updateVertexPositions();

		Building(int xpos_ = 0, int ypos_ = 0, bool collides_ = true, Game* game_ = nullptr);
};