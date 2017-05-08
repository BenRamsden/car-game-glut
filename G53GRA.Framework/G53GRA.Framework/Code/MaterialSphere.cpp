#include "MaterialSphere.h"

MaterialSphere::MaterialSphere() {

}

MaterialSphere::~MaterialSphere() {

}

void MaterialSphere::Display() {
	const GLint sphere_res = 32;

	//MATERIALS
	GLfloat no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat mat_ambient_color[] = { 0.8f, 0.8f, 0.2f, 1.0f };
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat no_shininess[] = { 0.0f };
	GLfloat low_shininess[] = { 5.0f };
	GLfloat high_shininess[] = { 100.0f };
	GLfloat mat_emission[] = { 0.3f, 0.2f, 0.2f, 0.0f };

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();
	
	glTranslatef(pos[0], pos[1], pos[2]);
	//glRotatef(90, rotation[0], rotation[1], rotation[2]);
	glScalef(scale[0], scale[1], scale[2]);

	//DRAW SPHERE
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, sphere_res, sphere_res);

	glPopMatrix();
	glPopAttrib();
}