// ----------------------------------------------------------------------------
// Fractional Brownian Motion
// macro function generators, depend on custom basis function
// ----------------------------------------------------------------------------

#define DECL_FBM_FUNC(_name, _octaves, _basis) float _name(_in(vec3) pos, _in(float) lacunarity, _in(float) init_gain, _in(float) gain) { vec3 p = pos; float H = init_gain; float t = 0.; for (int i = 0; i < _octaves; i++) { t += _basis * H; p *= lacunarity; H *= gain; } return t; }

#define DECL_FBM_FUNC_TILE(_name, _octaves, _basis) float _name(_in(vec3) pos, _in(float) lacunarity, _in(float) init_gain, _in(float) gain) { vec3 p = pos; float H = init_gain; float L = lacunarity; float t = 0.; for (int i = 0; i < _octaves; i++) { t += _basis * H; L *= lacunarity; H *= gain; } return t; }

