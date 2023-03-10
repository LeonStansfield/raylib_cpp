#include "raylib.h"
#include <vector>

class Body {
private:
	Vector3 position;
	Vector3 scale;

public:
	Body(Vector3 position, Vector3 scale) {
		this->position = position;
		this->scale = scale;
	}

	Vector3 getPosition() {
		return this->position;
	}

	Vector3 getScale() {
		return this->scale;
	}

	void setPosition(Vector3 position) {
		this->position = position;
	}

	void setScale(Vector3 scale) {
		this->scale = scale;
	}
};

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