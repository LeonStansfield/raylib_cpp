#pragma once
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
