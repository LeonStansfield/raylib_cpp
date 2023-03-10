#pragma once
#include "raylib.h"
#include "Body.h"
#include <vector>

class Cube : public Body {
private:
	Color color;
	Color wireColor;
public:
	Cube(Vector3 position, Vector3 scale, Color color, Color wireColor) : Body(position, scale) {
		this->color = color;
		this->wireColor = wireColor;
	}

	Color getColor() {
		return this->color;
	}

	void setColor(Color color) {
		this->color = color;
	}

	Color getWireColor() {
		return this->wireColor;
	}

	void setWireColor(Color wireColor) {
		this->wireColor = wireColor;
	}

	void draw() {
		DrawCube(this->getPosition(), this->getScale().x, this->getScale().y, this->getScale().z, this->getColor());
	}

	void drawWire() {
		DrawCubeWires(this->getPosition(), this->getScale().x, this->getScale().y, this->getScale().z, this->getColor());
	}
};