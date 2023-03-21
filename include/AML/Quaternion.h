#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"
#include "Matrix33.h"
#include "EulerAngles.h"
#include "DCM.h"
#include <cmath>

namespace AML {
	class Quaternion {
		public:
			//Data
			union {
				double data[4];
				struct {
					double q0, q1, q2, q3;
				};
			};


			//Constructors
			Quaternion();
			explicit Quaternion(double val);
			explicit Quaternion(const double data[4]);
			explicit Quaternion(double q0, double q1, double q2, double q3);
			explicit Quaternion(double scalar, const Vector3 &vector);
			explicit Quaternion(const Vector3 &vector);


			//Assignment operators (Quaternion)
			Quaternion& operator+=(const Quaternion &rhs);
			Quaternion& operator-=(const Quaternion &rhs);
			Quaternion& operator*=(const Quaternion &rhs);

			//Assignemnt operators (Scalar)
			Quaternion& operator+=(double rhs);
			Quaternion& operator-=(double rhs);
			Quaternion& operator*=(double rhs);
			Quaternion& operator/=(double rhs);

			//Special needed functions
			static const Quaternion identity();
			
	};
	
	//Quaternion and Quaternion operation
	Quaternion operator-(const Quaternion &rhs);
	Quaternion operator+(const Quaternion &lhs, const Quaternion &rhs);
	Quaternion operator-(const Quaternion &lhs, const Quaternion &rhs);
	Quaternion operator*(const Quaternion &lhs, const Quaternion &rhs);

	//Quaternion and constant operations
	Quaternion operator+(const Quaternion &lhs, double s);
	Quaternion operator-(const Quaternion &lhs, double s);
	Quaternion operator*(const Quaternion &lhs, double s);
	Quaternion operator/(const Quaternion &lhs, double s);
	Quaternion operator+(double s, const Quaternion &lhs);
	Quaternion operator-(double s, const Quaternion &lhs);
	Quaternion operator*(double s, const Quaternion &lhs);
	Quaternion operator/(double s, const Quaternion &lhs);

	//Quaternion and vector operations
	Vector3 operator*(const Quaternion &q, const Vector3 &v);


	//Quat operations
	Quaternion conjugate(const Quaternion &q);
	double norm(const Quaternion &q);
	void normalise(Quaternion &q);
	Quaternion inverse(const Quaternion &q);
	Quaternion unit(const Quaternion &q);
	bool isUnitQuat(const Quaternion &q, double tolerance = std::numeric_limits<double>::epsilon());
	double dot(const Quaternion &lhs, const Quaternion &rhs);

	//Converions
	Matrix33 quat2DCM(const Quaternion &q);
	Quaternion dcm2Quat(const Matrix33 &dcm);
	EulerAngles quat2EulerAngles(const Quaternion &q, const EulerAngles::EulerSequence seq = EulerAngles::EulerSequence::XYZ);
	Quaternion euler2Quat(const EulerAngles &angles);

	//define helpers here

	//euler to quat sequence helpers
	Quaternion euler2Quat_XYZ(const EulerAngles &angles);

	//quat to euler sequence helpers
	EulerAngles quat2EulerAngles_XYZ(const Quaternion &q);


	//Kinematic functions
	Quaternion integrateQuat(const Quaternion &quat, const Quaternion &quatRates, double dt);
	Quaternion quatKinematicsRates_BodyRates(const Quaternion &q, const Vector3 &bodyRates);
	Quaternion quatKinematicsRates_WorldRates(const Quaternion &q, const Vector3 &worldRates);

	//interpolation
	Quaternion linearInterpolation(const Quaternion &startQ, const Quaternion &endQ, double t);
	Quaternion slerpInterpolation(const Quaternion &startQ, const Quaternion &endQ, double t);
};

#endif