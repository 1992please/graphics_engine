#ifndef BASIC_LIGHTING_TECHNIQUE_H
#define BASIC_LIGHTING_TECHNIQUE_H

#include "basic_technique.h"
#include "lights_common.h"

class BasicLightingTechnique : public BasicTechnique
{
public:
	static const unsigned int MAX_POINT_LIGHTS = 2;
	static const unsigned int MAX_SPOT_LIGHTS = 2;

	BasicLightingTechnique();

	virtual bool Init() override;

	void SetMVP(const glm::mat4& WVP);
	void SetWorldMatrix(const glm::mat4& WVP);
	void SetDirectionalLight(const DirectionalLight& Light);
	void SetPointLights(unsigned int NumLights, const PointLight* pLights);
	void SetSpotLights(unsigned int NumLights, const SpotLight* pLights);
	void SetEyeWorldPos(const glm::vec3& EyeWorldPos);
	void SetMaterial(const Material* mat) override;
private:
	GLuint mMVPLocation;
	GLuint mWorldMatrixLocation;
	GLuint mEyeWorldPosLocation;
	GLuint mNumPointLightsLocation;
	GLuint mNumSpotLightsLocation;

	struct {
		struct{
			GLuint TexLocation;
			GLuint Color;
		}Diffuse, Specular;
		GLuint Shininess;
	}mMaterial;

	struct {
		GLuint Color;
		GLuint AmbientIntensity;
		GLuint DiffuseIntensity;
		GLuint Direction;
	} mDirLightLocation;

	struct {
		GLuint Color;
		GLuint AmbientIntensity;
		GLuint DiffuseIntensity;
		GLuint Position;
		struct {
			GLuint Constant;
			GLuint Linear;
			GLuint Exp;
		} Atten;
	} mPointLightsLocation[MAX_POINT_LIGHTS];

	struct {
		GLuint Color;
		GLuint AmbientIntensity;
		GLuint DiffuseIntensity;
		GLuint Position;
		GLuint Direction;
		GLuint Cutoff;
		struct {
			GLuint Constant;
			GLuint Linear;
			GLuint Exp;
		} Atten;
	} mSpotLightsLocation[MAX_SPOT_LIGHTS];
};

#endif
