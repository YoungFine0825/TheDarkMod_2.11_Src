/*****************************************************************************
The Dark Mod GPL Source Code

This file is part of the The Dark Mod Source Code, originally based
on the Doom 3 GPL Source Code as published in 2011.

The Dark Mod Source Code is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the License,
or (at your option) any later version. For details, see LICENSE.TXT.

Project: The Dark Mod (http://www.thedarkmod.com/)

******************************************************************************/
#version 140

#pragma tdm_include "tdm_utils.glsl"
#pragma tdm_include "interactionCommon.fs"
#pragma tdm_include "tdm_shadowstencilsoft.glsl"


uniform bool	u_shadows;
uniform int		u_softShadowsQuality;
uniform float	u_softShadowsRadius;
uniform vec2	u_renderResolution;
uniform usampler2D u_stencilTexture;
uniform sampler2D u_depthTexture;

out vec4 FragColor;


void main() {
	InteractionGeometry props;
	FragColor.rgb = computeInteraction(props);

	vec3 objectToLight = var_TangentBitangentNormalMatrix * var_LightDirLocal;
	vec3 objectNormal = var_TangentBitangentNormalMatrix[2];

	if (u_shadows && u_softShadowsQuality > 0) {
		FragColor.rgb *= computeStencilSoftShadow(
			u_stencilTexture, u_depthTexture,
			objectToLight, objectNormal,
			u_modelViewMatrix, u_projectionMatrix,
			u_softShadowsQuality, u_softShadowsRadius,
			u_depthTexture, ivec2(-1, -1), vec4(0)
		);
	}
	FragColor.a = 1.0;
}
