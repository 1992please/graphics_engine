#ifndef MAIN_APP_H
#define MAIN_APP_H

#include "util.h"
#include "graphics_app.h"
#include "callbacks.h"
#include <GL\glew.h>
#include "Texture.h"
#include "techniques.h"
#include "camera.h"

#define WINDOW_WIDTH  1280  
#define WINDOW_HEIGHT 1024

struct Vertex
{
	glm::vec3 m_pos;
	glm::vec2 m_tex;

	Vertex() {}

	Vertex(glm::vec3 pos, glm::vec2 tex)
	{
		m_pos = pos;
		m_tex = tex;
	}
};

class MainApp :public ICallbacks, public GraphicsApp
{
public:
	MainApp();
	~MainApp();
	bool Init();
	void Run();
	void RenderScene_callback() override;
	void Keyboard_callback(KEY key) override;
	void PassiveMouse_callback(float x, float y) override;
private:
	void CreateVertexBuffer();

	GLuint VBO, VAO, EBO;
	LightingTechnique* Technique;
	Camera* GameCamera;
	float m_scale;
	DirectionalLight mDirectionalLight;
	PersProjInfo mPersProjInfo;
	Texture* mTexture;
};

#endif // !MAIN_APP_H