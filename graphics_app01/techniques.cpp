#include "util.h"
#include "techniques.h"

LightingTechnique::LightingTechnique()
{
}

bool LightingTechnique::Init()
{
	if (!Technique::Init()) {
		return false;
	}

	if (!AddShader("shaders/lighting.vs", "shaders/lighting.fs")) {
		return false;
	}

	mMVPLocation = GetUniformLocation("MVP");
	mSamplerLocation = GetUniformLocation("gSampler");
	mDirLightColorLocation = GetUniformLocation("gDirectionalLight.Color");
	mDirLightAmbientIntensityLocation = GetUniformLocation("gDirectionalLight.AmbientIntensity");

	if (mMVPLocation == INVALID_UNIFORM_LOCATION ||
		mSamplerLocation == INVALID_UNIFORM_LOCATION ||
		mDirLightColorLocation == INVALID_UNIFORM_LOCATION ||
		mDirLightAmbientIntensityLocation == INVALID_UNIFORM_LOCATION)
	{
		return false;
	}

	return true;
}

void LightingTechnique::SetMVP(const glm::mat4& MVP)
{
	glUniformMatrix4fv(mMVPLocation, 1, GL_FALSE, &MVP[0][0]);
}


void LightingTechnique::SetTextureUnit(unsigned int TextureUnit)
{
	glUniform1i(mSamplerLocation, TextureUnit);
}


void LightingTechnique::SetDirectionalLight(const DirectionalLight& Light)
{
	glUniform3f(mDirLightColorLocation, Light.Color.x, Light.Color.y, Light.Color.z);
	glUniform1f(mDirLightAmbientIntensityLocation, Light.AmbientIntensity);
}

bool CustomTechnique::Init()
{
	if (!Technique::Init()) {
		return false;
	}

	if (!AddShader("shaders/shader.vs", "shaders/shader.fs")) {
		return false;
	}

	mMVPLocation = GetUniformLocation("MVP");

	if (mMVPLocation == INVALID_UNIFORM_LOCATION)
	{
		return false;
	}

	return true;
}

void CustomTechnique::SetMVP(const glm::mat4 & MVP)
{
	glUniformMatrix4fv(mMVPLocation, 1, GL_FALSE, &MVP[0][0]);
}

bool UnlitTechnique::Init()
{
	if (!Technique::Init()) {
		return false;
	}

	if (!AddShader("shaders/unlit.vs", "shaders/unlit.fs")) {
		return false;
	}

	mMVPLocation = GetUniformLocation("MVP");
	mSamplerLocation = GetUniformLocation("gSampler");

	if (mMVPLocation == INVALID_UNIFORM_LOCATION ||
		mSamplerLocation == INVALID_UNIFORM_LOCATION)
	{
		return false;
	}

	return true;
}

void UnlitTechnique::SetMVP(const glm::mat4 & MVP)
{
	glUniformMatrix4fv(mMVPLocation, 1, GL_FALSE, &MVP[0][0]);
}

void UnlitTechnique::SetTextureUnit(unsigned int TextureUnit)
{
	glUniform1i(mSamplerLocation, TextureUnit);
}
