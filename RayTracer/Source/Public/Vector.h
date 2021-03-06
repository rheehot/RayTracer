#pragma once
#include <cmath>

// Represents the location or direction of the 3D space
// Left handed coordinate system, Z-axis goes up
struct FVector
{
	// Forward
	float X;

	// Right
	float Y;

	// Up
	float Z;
	
	FVector() :X{ 0 }, Y{ 0 }, Z{ 0 } {}
	FVector(float X, float Y, float Z) :X{ X }, Y{ Y }, Z{ Z } {}

	const FVector& operator+() const { return *this; }
	FVector operator-() const { return { -X, -Y, -Z }; }
	FVector& operator+=(const FVector& V) { X += V.X; Y += V.Y; Z += V.Z; return *this; }
	FVector& operator-=(const FVector& V) { X -= V.X; Y -= V.Y; Z -= V.Z; return *this; }
	FVector& operator*=(const FVector& V) { X *= V.X; Y *= V.Y; Z *= V.Z; return *this; }
	FVector& operator/=(const FVector& V) { X /= V.X; Y /= V.Y; Z /= V.Z; return *this; }
	FVector& operator*=(float Scale) { X *= Scale; Y *= Scale; Z *= Scale; return *this; }
	FVector& operator/=(float Scale) { X /= Scale; Y /= Scale; Z /= Scale; return *this; }
	FVector operator+(const FVector& V) const { return { X + V.X, Y + V.Y, Z + V.Z }; }
	FVector operator-(const FVector& V) const { return { X - V.X, Y - V.Y, Z - V.Z }; }
	FVector operator*(const FVector& V) const { return { X * V.X, Y * V.Y, Z * V.Z }; }
	FVector operator/(const FVector& V) const { return { X / V.X, Y / V.Y, Z / V.Z }; }
	FVector operator*(float Scale) const { return { X * Scale, Y * Scale, Z * Scale }; }
	FVector operator/(float Scale) const { return { X / Scale, Y / Scale, Z / Scale }; }

	float Size() const { return sqrt(SqrSize()); }
	float SqrSize() const { return Dot(*this, *this); }

	void Normalize() { *this /= Size(); }
	static FVector GetNormal(const FVector& V) { return V / V.Size(); }

	static float Dot(const FVector& V1, const FVector& V2)
	{
		return V1.X * V2.X + V1.Y * V2.Y + V1.Z * V2.Z;
	}

	static FVector Cross(const FVector& V1, const FVector& V2)
	{
		return { V1.Y * V2.Z - V1.Z * V2.Y, -(V1.X * V2.Z - V1.Z * V2.X), V1.X * V2.Y - V1.Y * V2.X };
	}

	static const FVector Zero;
	static const FVector One;
};

inline const FVector FVector::Zero;
inline const FVector FVector::One{ 1.f, 1.f, 1.f };

inline FVector operator*(float Scale, const FVector& V)
{
	return V * Scale;
}
