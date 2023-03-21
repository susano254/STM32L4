#ifndef VECTOR3_H
#define VECTOR3_H

namespace AML {
	class Vector3{
		public:
			union {
				double data[3];
				struct{double x, y, z;};
			};
			
		//Constructors
		Vector3();
		Vector3(double val);
		Vector3(double x, double y, double z);
		Vector3(const double data[3]);

		//operators
		//assignments for vector
		Vector3& operator+=(const Vector3& rhs);
		Vector3& operator-=(const Vector3& rhs);
		Vector3& operator*=(const Vector3& rhs);
		Vector3& operator/=(const Vector3& rhs);
		//assignments for scalar
		Vector3& operator+=(double rhs);
		Vector3& operator-=(double rhs);
		Vector3& operator*=(double rhs);
		Vector3& operator/=(double rhs);

		static const Vector3 xAxis();
		static const Vector3 yAxis();
		static const Vector3 zAxis();
	};

	// vector to vector element wise operations
	Vector3 operator-(const Vector3& rhs);
	Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
	Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
	Vector3 operator*(const Vector3& lhs, const Vector3& rhs);
	Vector3 operator/(const Vector3& lhs, const Vector3& rhs);

	// vector to scalar element wise operations
	Vector3 operator+(const Vector3& lhs, double rhs);
	Vector3 operator-(const Vector3& lhs, double rhs);
	Vector3 operator*(const Vector3& lhs, double rhs);
	Vector3 operator/(const Vector3& lhs, double rhs);
	Vector3 operator+(double lhs, const Vector3& rhs);
	Vector3 operator-(double lhs, const Vector3& rhs);
	Vector3 operator*(double lhs, const Vector3& rhs);
	Vector3 operator/(double lhs, const Vector3& rhs);

	double invSqrt(float num);
	void normalize(Vector3& v);
	double norm(const Vector3& v);
	Vector3 unit(const Vector3& v);
	Vector3 cross(const Vector3& lhs, const Vector3& rhs);
	double dot(const Vector3& lhs, const Vector3& rhs);
};

#endif