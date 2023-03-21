#include <Quaternion.h>

namespace AML {
	//Constructors
	Quaternion::Quaternion() 
	: q0(0.0), q1(0.0), q2(0.0), q3(0.0) {}

	Quaternion::Quaternion(double val)
	: q0(val), q1(val), q2(val), q3(val) {}

	Quaternion::Quaternion(const double data[4])
	: q0(data[0]), q1(data[1]), q2(data[2]), q3(data[3]) {}
	Quaternion::Quaternion(double q0, double q1, double q2, double q3)
	: q0(q0), q1(q1), q2(q2), q3(q3) {}
	Quaternion::Quaternion(double scalar, const Vector3 &vector)
	: q0(scalar), q1(vector.x), q2(vector.y), q3(vector.z) {}
	Quaternion::Quaternion(const Vector3 &vector)
	: q0(0.0), q1(vector.x), q2(vector.y), q3(vector.z) {}


	//Assignment operators (Quaternion)
	Quaternion& Quaternion::operator+=(const Quaternion &rhs){
		q0 += rhs.q0;
		q1 += rhs.q1;
		q2 += rhs.q2;
		q3 += rhs.q3;

		return *this;
	}
	Quaternion& Quaternion::operator-=(const Quaternion &rhs){
		q0 -= rhs.q0;
		q1 -= rhs.q1;
		q2 -= rhs.q2;
		q3 -= rhs.q3;

		return *this;
	}
	Quaternion& Quaternion::operator*=(const Quaternion &rhs){
		double q0_new = (q0 * rhs.q0) - (q1 * rhs.q1) - (q2 * rhs.q2) - (q3 * rhs.q3);
		double q1_new = (q1 * rhs.q0) + (q0 * rhs.q1) - (q3 * rhs.q2) + (q2 * rhs.q3);
		double q2_new = (q2 * rhs.q0) + (q3 * rhs.q1) + (q0 * rhs.q2) - (q1 * rhs.q3);
		double q3_new = (q3 * rhs.q0) - (q2 * rhs.q1) + (q1 * rhs.q2) + (q0 * rhs.q3);
		q0 = q0_new;
		q1 = q1_new;
		q2 = q2_new;
		q3 = q3_new;

		return *this;
	}

	//Assignemnt operators (Scalar)
	Quaternion& Quaternion::operator+=(double rhs){
		q0 += rhs;
		q1 += rhs;
		q2 += rhs;
		q3 += rhs;

		return *this;
	}
	Quaternion& Quaternion::operator-=(double rhs){
		q0 -= rhs;
		q1 -= rhs;
		q2 -= rhs;
		q3 -= rhs;

		return *this;
	}
	Quaternion& Quaternion::operator*=(double rhs){
		q0 *= rhs;
		q1 *= rhs;
		q2 *= rhs;
		q3 *= rhs;

		return *this;
	}
	Quaternion& Quaternion::operator/=(double rhs){
		q0 /= rhs;
		q1 /= rhs;
		q2 /= rhs;
		q3 /= rhs;

		return *this;
	}

	//Special needed functions
	const Quaternion Quaternion::identity(){
		return Quaternion(1.0, 0.0, 0.0, 0.0);
	}

	
	//Quaternion and Quaternion operation
	Quaternion operator-(const Quaternion &rhs){ return Quaternion(rhs) *= -1.0; }
	Quaternion operator+(const Quaternion &lhs, const Quaternion &rhs){ return (Quaternion(lhs) += rhs); }
	Quaternion operator-(const Quaternion &lhs, const Quaternion &rhs){ return (Quaternion(lhs) -= rhs); }
	Quaternion operator*(const Quaternion &lhs, const Quaternion &rhs){ return (Quaternion(lhs) *= rhs); }

	//Quaternion and constant operations
	Quaternion operator+(const Quaternion &lhs, double s){ return (Quaternion(lhs) += s); }
	Quaternion operator-(const Quaternion &lhs, double s){ return (Quaternion(lhs) -= s); }
	Quaternion operator*(const Quaternion &lhs, double s){ return (Quaternion(lhs) *= s); }
	Quaternion operator/(const Quaternion &lhs, double s){ return (Quaternion(lhs) /= s); }
	Quaternion operator+(double s, const Quaternion &rhs){ return Quaternion(s + rhs.q0, s + rhs.q1, s + rhs.q2, s + rhs.q3); }
	Quaternion operator-(double s, const Quaternion &rhs){ return Quaternion(s - rhs.q0, s - rhs.q1, s - rhs.q2, s - rhs.q3); }
	Quaternion operator*(double s, const Quaternion &rhs){ return Quaternion(s * rhs.q0, s * rhs.q1, s * rhs.q2, s * rhs.q3); }
	Quaternion operator/(double s, const Quaternion &rhs){ return Quaternion(s / rhs.q0, s / rhs.q1, s / rhs.q2, s / rhs.q3); }

	//Quaternion and vector operations
	Vector3 operator*(const Quaternion &q, const Vector3 &v){ return quat2DCM(q) * v; }

	//Quat operations
	Quaternion conjugate(const Quaternion &q){ return Quaternion(q.q0, -q.q1, -q.q2, -q.q3); }
	double norm(const Quaternion &q){ return sqrt(q.q0*q.q0 + q.q1*q.q1 + q.q2*q.q2 + q.q3*q.q3); }
	Quaternion inverse(const Quaternion &q){ return conjugate(q)/norm(q); }
	Quaternion unit(const Quaternion &q){
		double mag = norm(q);
		if(mag > 0.0) return (Quaternion(q)/mag);
		return Quaternion(q);
	}
	void normalise(Quaternion &q){ q = unit(q); }
	bool isUnitQuat(const Quaternion &q, double tolerance){ return (fabs(norm(q) - 1.0) < 2.0*tolerance); }
	double dot(const Quaternion &lhs, const Quaternion &rhs){ return (lhs.q0*rhs.q0 + lhs.q1*rhs.q1 + lhs.q2*rhs.q2 + lhs.q3*rhs.q3); }

	//Converions
	Matrix33 quat2DCM(const Quaternion &q){
		const double TOL = 0.0001;
		if(isUnitQuat(q, TOL)){
			double q0 = q.data[0];
			double q1 = q.data[1];
			double q2 = q.data[2];
			double q3 = q.data[3];

			double data[3][3] = {{q0*q0 + q1*q1 - q2*q2 - q3*q3, 2*q1*q2 + 2*q0*q3, 2*q1*q3 - 2*q0*q2},
								{2*q1*q2 - 2*q0*q3, q0*q0 - q1*q1 + q2*q2 - q3*q3, 2*q2*q3 + 2*q0*q1},
								{2*q1*q3 + 2*q0*q2, 2*q2*q3 - 2*q0*q1, q0*q0 - q1*q1 - q2*q2 + q3*q3}};

			return Matrix33(data);
		}
		return Matrix33::identity();
	}
	Quaternion dcm2Quat(const Matrix33 &dcm){
		const double TOL = 0.0001;
		if(isValidDCM(dcm, TOL)){
			double q1_den = (1.0 + dcm.data[0][0] + dcm.data[1][1] + dcm.data[2][2]);
			double q2_den = (1.0 + dcm.data[0][0] - dcm.data[1][1] - dcm.data[2][2]);
			double q3_den = (1.0 - dcm.data[0][0] + dcm.data[1][1] - dcm.data[2][2]);
			double q4_den = (1.0 - dcm.data[0][0] - dcm.data[1][1] + dcm.data[2][2]);
			double r23mr32 = dcm.data[1][2] - dcm.data[2][1];
			double r31mr13 = dcm.data[2][0] - dcm.data[0][2];
			double r12mr21 = dcm.data[0][1] - dcm.data[1][0];
			double r23pr32 = dcm.data[1][2] + dcm.data[2][1];
			double r31pr13 = dcm.data[2][0] + dcm.data[0][2];
			double r12pr21 = dcm.data[0][1] + dcm.data[1][0];

			double den, q0, q1, q2, q3;
			if( q1_den > q2_den && q1_den > q3_den && q1_den > q4_den ){
				den = sqrt(q1_den);
				q0 = 0.5*den;
				q1 = 0.5*r23mr32/den;
				q2 = 0.5*r31mr13/den;
				q3 = 0.5*r12mr21/den;
			}
			if( q2_den > q1_den && q2_den > q3_den && q2_den > q4_den ){
				den = sqrt(q2_den);
				q0 = 0.5*r23mr32/den;
				q1 = 0.5*den;
				q2 = 0.5*r12pr21/den;
				q3 = 0.5*r31pr13/den;
			}
			if( q3_den > q1_den && q3_den > q2_den && q3_den > q4_den ){
				den = sqrt(q3_den);
				q0 = 0.5*r31mr13/den;
				q1 = 0.5*r12pr21/den;
				q2 = 0.5*den;
				q3 = 0.5*r23pr32/den;
			}
			if( q4_den > q1_den && q4_den > q2_den && q4_den > q3_den ){
				den = sqrt(q4_den);
				q0 = 0.5*r12mr21/den;
				q1 = 0.5*r31pr13/den;
				q2 = 0.5*r23pr32/den;
				q3 = 0.5*den;
			}
			return Quaternion(q0, q1, q2, q3);
		}
		return Quaternion::identity();
	}

	Quaternion euler2Quat(const EulerAngles &attitude){
		switch (attitude.getEulerSequence()) {
			case EulerAngles::EulerSequence::XYZ:
				return euler2Quat_XYZ(attitude);

			//extensible for other sequences
		}
		return Quaternion::identity();
	}

	EulerAngles quat2EulerAngles(const Quaternion &q, const EulerAngles::EulerSequence seq){
		if(isUnitQuat(q)){
			switch(seq){
				case EulerAngles::EulerSequence::XYZ:
					return quat2EulerAngles_XYZ(q);
				//extensible for other sequences
			}
		}
		return EulerAngles();
	}

	//define helpers here

	//euler to quat sequence helpers
	Quaternion euler2Quat_XYZ(const EulerAngles &attitude){
		double c1 = cos(0.5*attitude.data[0]);
		double c2 = cos(0.5*attitude.data[1]);
		double c3 = cos(0.5*attitude.data[2]);
		double s1 = sin(0.5*attitude.data[0]);
		double s2 = sin(0.5*attitude.data[1]);
		double s3 = sin(0.5*attitude.data[2]);
		double q0 = c1*c2*c3 + s1*s2*s3;
		double q1 = s1*c2*c3 - c1*s2*s3;
		double q2 = c1*s2*c3 + s1*c2*s3;
		double q3 = c1*c2*s3 - s1*s2*c3;

		return Quaternion(q0, q1, q2, q3);
	}

	//quat to euler sequence helpers
	EulerAngles quat2EulerAngles_XYZ(const Quaternion &q){
		double q0 = q.data[0];
		double q1 = q.data[1];
		double q2 = q.data[2];
		double q3 = q.data[3];
		double r11 = q0*q0 + q1*q1 - q2*q2 - q3*q3;
		double r12 = 2*q1*q2 + 2*q0*q3;
		double r13 = 2*q1*q3 - 2*q0*q2;
		double r23 = 2*q2*q3 + 2*q0*q1;
		double r33 = q0*q0 - q1*q1 - q2*q2 + q3*q3;
		double phi = atan2(r23, r33);
		double theta = -asin(r13);
		double psi = atan2(r12, r11);

		return EulerAngles(phi, theta, psi);
	}


	//Kinematic functions
	Quaternion integrateQuat(const Quaternion &quat, const Quaternion &quatRates, double dt){
		Quaternion quat_new = quat + quatRates*dt;
		normalise(quat_new);

		return quat_new;
	}
	Quaternion quatKinematicsRates_BodyRates(const Quaternion &quat, const Vector3 &bodyRates){
		double p = bodyRates.x;
		double q = bodyRates.y;
		double r = bodyRates.z;

		double q0 = 0.5 * (-quat.q1 * p - quat.q2 * q - quat.q3 * r);
		double q1 = 0.5 * ( quat.q0 * p + quat.q3 * q - quat.q2 * r);
		double q2 = 0.5 * (-quat.q3 * p + quat.q0 * q + quat.q1 * r);
		double q3 = 0.5 * ( quat.q2 * p - quat.q1 * q + quat.q0 * r);

		return Quaternion(q0, q1, q2, q3);
		
	}
	Quaternion quatKinematicsRates_WorldRates(const Quaternion &quat, const Vector3 &worldRates){
		double p = worldRates.x;
		double q = worldRates.y;
		double r = worldRates.z;

		double q0 = 0.5 * (-quat.q1 * p - quat.q2 * q - quat.q3 * r);
		double q1 = 0.5 * ( quat.q0 * p - quat.q3 * q + quat.q2 * r);
		double q2 = 0.5 * ( quat.q3 * p + quat.q0 * q - quat.q1 * r);
		double q3 = 0.5 * (-quat.q2 * p + quat.q1 * q + quat.q0 * r);

		return Quaternion(q0, q1, q2, q3);
	}

	//interpolation
	Quaternion linearInterpolation(const Quaternion &startQ, const Quaternion &endQ, double t){
		Quaternion q0 = unit(startQ); 	//start quaternion normalized
		Quaternion q1 = unit(endQ); 	//end quaternion normalized
		if(t < 0.0) return q0;
		if (t > 1.0) return q1;
		else return unit((1.0 - t)*q0 + t*q1);
		
	}
	Quaternion slerpInterpolation(const Quaternion &startQ, const Quaternion &endQ, double t){
		Quaternion q0 = unit(startQ); 	//start quaternion normalized
		Quaternion q1 = unit(endQ); 	//end quaternion normalized
		if(t < 0.0) return q0;
		if(t > 1.0) return q1;
		
		double dotProduct = dot(q0, q1);
		if(dotProduct < 0.0){
			q1 = -q1;
			dotProduct = -dotProduct;
		}
		//since unit quaternions dot product is equal to cosine the angle between them 
		double theta = acos(dotProduct);
		//if angle is small just better to linaer interpolate 
		if(theta < 0.0001)
			return linearInterpolation(startQ, endQ, t);
		
		//else spherically linaer interpolate 
		double a = sin((1.0-t)*theta)/sin(theta);
		double b = sin(t*theta)/sin(theta);

		return unit(a*q0+b*q1);
	}

};