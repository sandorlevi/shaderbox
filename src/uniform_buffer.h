// ----------------------------------------------------------------------------
// Uniform buffer cross-language definitions
// ----------------------------------------------------------------------------
#if defined(HLSLTOY) && defined(__cplusplus)
#define _begin_ubuffer(name, num) struct alignas(16) name {
#define _end_ubuffer }
#define _uniform(type, name, default_value) type name = default_value
#define _pack(x)
#else
#if defined(__cplusplus) || defined(GL_ES) || defined(GL_SHADING_LANGUAGE_VERSION)
#define _begin_ubuffer(name, num) /* uniform name { */
#define _end_ubuffer
#define _uniform(type, name, default_value) const type name = default_value
#define _pack(x)
#endif
#endif

#ifdef HLSL
#define _begin_ubuffer(name, num) cbuffer name : register(num) {
#define _end_ubuffer }
#define _uniform(type, name, default_value) type name
#define _pack(x) : packoffset(x)
#endif

#if defined(HLSLTOY) || defined(HLSL)
_begin_ubuffer(main_uniform_buffer_t, b0)
	_uniform(vec2,	u_res,				vec2(0, 0))			_pack(c0.x);
	_uniform(vec2,	u_mouse,			vec2(0, 0))			_pack(c0.z);
	_uniform(float,	u_time,				(0.))				_pack(c1);
_end_ubuffer;
#else
#if defined(__cplusplus) || defined(SHADERTOY)
	#define u_res iResolution
	#define u_time iGlobalTime
	#define u_mouse iMouse
#endif
#endif

#ifdef APP_CLOUDS
_begin_ubuffer(clouds_uniform_buffer_t, b1)
	_uniform(vec3,	wind_dir,			vec3(0, 0, .2))		_pack(c0);
	_uniform(vec3,	sun_dir,			vec3(0, 0, -1))		_pack(c1);
	_uniform(vec3,	sun_color,			vec3(1., .7, .55))	_pack(c2);
	_uniform(float,	sun_power,			(8.))				_pack(c3.x);

	_uniform(int,	cld_march_steps,	(100))				_pack(c3.y);
	_uniform(int,	illum_march_steps,	(6))				_pack(c3.z);

	_uniform(float,	sigma_scattering,	(.15))				_pack(c3.w);
	_uniform(float,	cld_coverage,		(.535))				_pack(c4.x);
	_uniform(float,	cld_thick,			(125.))				_pack(c4.y);
_end_ubuffer;
#endif
