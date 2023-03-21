#include <DCM.h>
#include <cmath>

namespace AML {
	const Matrix33 DCM::rotationAroundX(double theta){
		double data[3][3] = { 
			{1.0,	 	0.0, 		0.0},
			{0.0, cos(theta), sin(theta)},
			{0.0, -sin(theta), cos(theta)}
		};

		return Matrix33(data);
	}
	const Matrix33 DCM::rotationAroundY(double phi){
		double data[3][3] = { 
			{cos(phi), 0.0, -sin(phi)},
			{	0.0, 	1.0,	 0.0},
			{sin(phi), 	0.0, cos(phi)}
		};
		return Matrix33(data);
	}
	const Matrix33 DCM::rotationAroundZ(double thai){
		double data[3][3] = { 
			{cos(thai), sin(thai),	0.0},
			{-sin(thai), cos(thai),	0.0},
			{	0.0, 	0.0,	 	1.0},
		};
		return Matrix33(data);
	}

	bool isValidDCM(const Matrix33 dcm, double tolerance){
		double det = determinant(dcm);
		//first check it's not a negative value
		if(det <= 0.0) return false;
		//then check it's equal to 1
		double error = det - 1.0;
		//absolute value of the error
		error = error < 0 ? -error : error;
		//if greater than the limit then not a valid dcm
		if(error > tolerance) return false;
		//check the matrix * it's transpose is identity matrix
		if(!(dcm*transpose(dcm) == Matrix33::identity())) return false;

		return true;
	}
	void normalizeDCM(Matrix33 &dcm){
		Vector3 x_component = Vector3(dcm.m11, dcm.m21, dcm.m31);
		Vector3 y_component = Vector3(dcm.m12, dcm.m22, dcm.m32);

		//calculate the error in the directions of the vectors (supposed to be 0)
		//i.e. all rows and columns should be independent
		double error = dot(x_component, y_component);

		//reverse the vector to the other direction of the error
		Vector3 orthogonal_x = x_component - 0.5 * error * y_component;
		Vector3 orthogonal_y = y_component - 0.5 * error * x_component;
		Vector3 orthogonal_z = cross(orthogonal_x, orthogonal_y);

		Vector3 x_norm = 0.5 * (3.0 - dot(orthogonal_x, orthogonal_x))* orthogonal_x;
		Vector3 y_norm = 0.5 * (3.0 - dot(orthogonal_y, orthogonal_y))* orthogonal_y;
		Vector3 z_norm = 0.5 * (3.0 - dot(orthogonal_z, orthogonal_z))* orthogonal_z;

		Matrix33 temp = dcm;
		dcm = Matrix33(x_norm, y_norm, z_norm);
	}

	Matrix33 integrateDCM(const Matrix33 &dcm, const Matrix33 &dcmRates, double dt){
		Matrix33 dcm_update = dcm + dcmRates*dt;
		normalizeDCM(dcm_update);
		return dcm_update;
	}
	Matrix33 dcmKinematicsBodyRates(const Matrix33 &dcm, const Vector3 &w_b){
		const double p = w_b.x;
		const double q = w_b.y;
		const double r = w_b.z;
		const double skew_matrix_data[3][3] = {
			{0.0, -r, q},
			{r, 0.0, -p},
			{-q, p, 0.0}
		};

		const Matrix33 skewMatrix(skew_matrix_data);
		Matrix33 result = -skewMatrix*dcm;
		return result;
	}
	Matrix33 dcmKinematicsWorldRates(const Matrix33 &dcm, const Vector3 &w_w){
		const double p = w_w.x;
		const double q = w_w.y;
		const double r = w_w.z;
		const double skew_matrix_data[3][3] = {
			{0.0, -r, q},
			{r, 0.0, -p},
			{-q, p, 0.0}
		};

		const Matrix33 skewMatrix(skew_matrix_data);
		Matrix33 result = dcm*skewMatrix;
		return result;
	}
}
