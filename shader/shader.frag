in vec4 fPosition;
in vec4 fColor;
in vec4 fLightPosition;
in vec3 fNormal;

// output
out vec4 color;

void main(void)
{       
    vec3 o =-normalize(fPosition.xyz);
    vec3 n = normalize(fNormal);
    vec3 r = reflect(o,n);
    vec3 l = normalize(fLightPosition.xyz-fPosition.xyz);

    float ambient = 0.1;
    float diffus = 0.7*max(0.0,dot(n,l));
    float specular = 0.6*pow(max(0.0,-dot(r,l)),4.0);

    color = fColor * ( ambient + diffus + specular );

	/*color = vec3(1,0,0);*/
}
