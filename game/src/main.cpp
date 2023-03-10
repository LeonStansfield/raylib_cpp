
#include <math.h>
#include <vector>
#include <iostream>

#include "raylib.h"

const int screenWidth = 1600;
const int screenHeight = 900;

class Cube {
private:
	Vector3 position;
	Vector3 scale;
	Color color;
	Color wireColor;
public:
	Cube(Vector3 position, Vector3 scale, Color color, Color wireColor) {
		this->position = position;
		this->scale = scale;
		this->color = color;
		this->wireColor = wireColor;
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
		DrawCubeWires(this->getPosition(), this->getScale().x, this->getScale().y, this->getScale().z, this->getWireColor());
	}
};

int main() {
	//initialisation
	InitWindow(screenWidth, screenHeight, "Raylib");
	SetTargetFPS(60);

	// Define the camera to look into our 3d world
	Camera3D camera = { 0 };
	camera.position = Vector3({ 10.0f, 10.0f, 8.0f });
	camera.target = Vector3({ 0.0f, 0.0f, 0.0f });
	camera.up = Vector3({ 0.0f, 1.0f, 0.0f });
	camera.fovy = 60.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	Cube cube({ 0.0f, 0.0f, 0.0f }, Vector3({ 1.0f, 1.0f, 1.0f }), RED, MAROON);

	while (!WindowShouldClose()) 
	{
		//update

		//drawing
		BeginDrawing();

			ClearBackground(WHITE);


			BeginMode3D(camera);

				cube.draw();
				cube.drawWire();

				DrawGrid(10, 1.0f);

			EndMode3D();

			DrawFPS(10, 10); //draw fps

		EndDrawing();
	}

	//deinitialisation
	CloseWindow(); //close window and openGL context
	return 0;
}