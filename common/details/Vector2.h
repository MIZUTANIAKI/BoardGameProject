#include "..\Vector2.h"
template<class T>
Vector2Temple<T>::Vector2Temple()
{
	x = 0;
	y = 0;
}

template<class T>
Vector2Temple<T>::~Vector2Temple()
{
}

template<class T>
Vector2Temple<T>::Vector2Temple(T x, T y)
{
	this->x = x;
	this->y = y;
}

template<class T>
void Vector2Temple<T>::Swap(Vector2Temple& vec)
{
	T tmpx = x;
	T tmpy = y;
	this->x = vec.x;
	this->y = vec.y;
	vec.x = tmpx;
	vec.y = tmpy;
}

template<class T>
inline void Vector2Temple<T>::Move(Vector2Temple& vec)
{
	this->x = std::move(vec.x);
	this->y = std::move(vec.y);
}

template<class T>
Vector2Temple<T>& Vector2Temple<T>::operator=(const Vector2Temple<T>& vec)
{
	this->x = vec.x;
	this->y = vec.y;
	return (*this);
}

template<class T>
T& Vector2Temple<T>::operator[](int no)
{
	if (no == 0)
	{
		return this->x;
	}
	else if (no == 1)
	{
		return this->y;
	}
	else
	{
		return this->x;			//ó·äOÇÃèÍçáÇÕÅAÇ∆ÇËÇ†Ç¶Ç∏XÇìnÇ∑ÅB
	}
}

template<class T>
Vector2Temple<T>& Vector2Temple<T>::operator+=(const Vector2Temple<T>& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;

}

template<class T>
Vector2Temple<T>& Vector2Temple<T>::operator-=(const Vector2Temple<T>& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

template<class T>
Vector2Temple<T>& Vector2Temple<T>::operator*=(T k)
{
	this->x *= k;
	this->y *= k;
	return *this;
}

template<class T>
Vector2Temple<T>& Vector2Temple<T>::operator/=(T k)
{
	this->x /= k;
	this->y /= k;
	return *this;
}

template<class T>
Vector2Temple<T> Vector2Temple<T>::operator+() const
{
	return (*this);
}

template<class T>
Vector2Temple<T> Vector2Temple<T>::operator-() const
{
	return Vector2Temple(-this->x, -this->y);
}

template<class T>
Vector2Temple<T>& Vector2Temple<T>::operator+=(const T k)
{
	this->x += k;
	this->y += k;
	return *this;
}

template<class T>
Vector2Temple<T>& Vector2Temple<T>::operator-=(const T k)
{
	this->x -= k;
	this->y -= k;
	return *this;
}

template<class T>
bool Vector2Temple<T>::operator==(const Vector2Temple<T>& Vec) const
{
	return ((this->x == Vec.x) && (this->y == Vec.y));
}

template<class T>
bool Vector2Temple<T>::operator!=(const Vector2Temple<T>& Vec) const
{
	return (this->x != Vec.x) && (this->y != Vec.y);
}

template<class T>
bool Vector2Temple<T>::operator<=(const Vector2Temple<T>& Vec) const
{
	return ((this->x <= Vec.x) && (this->y <= Vec.y));
}

template<class T>
bool Vector2Temple<T>::operator<(const Vector2Temple<T>& Vec) const
{
	return ((this->x < Vec.x) && (this->y < Vec.y));
}

template<class T>
bool Vector2Temple<T>::operator>=(const Vector2Temple<T>& Vec) const
{
	return ((this->x >= Vec.x) && (this->y >= Vec.y));
}

template<class T>
bool Vector2Temple<T>::operator>(const Vector2Temple<T>& Vec) const
{
	return ((this->x > Vec.x) && (this->y > Vec.y));
}

template<class T>
Vector2Temple<T> operator+(const Vector2Temple<T>& u, T v)
{
	return Vector2Temple<T>(u.x + v, u.y + v);
}

template<class T>
Vector2Temple<T> operator-(const Vector2Temple<T>& u, T v)
{
	return Vector2Temple<T>(u.x - v, u.y - v);
}

template<class T>
Vector2Temple<T> operator*(const Vector2Temple<T>& u, T v)
{
	return Vector2Temple<T>(u.x * v, u.y * v);
}

template<class T>
Vector2Temple<T> operator*(T v, const Vector2Temple<T>& u)
{
	return Vector2Temple<T>(v * u.x, v * u.y);
}

template<class T>
Vector2Temple<T> operator/(const Vector2Temple<T>& u, T v)
{
	return v != 0 ? Vector2Temple<T>(u.x / v, u.y / v) : u;
}

template<class T>
Vector2Temple<T> operator%(const Vector2Temple<T>& u, T v)
{
	return Vector2Temple<T>(u.x % v, u.y % v);
}

template<class T>
Vector2Temple<T> operator+(const Vector2Temple<T>& u, const Vector2Temple<T>& u2)
{
	return Vector2Temple<T>(u.x + u2.x, u.y + u2.y);
}

template<class T>
Vector2Temple<T> operator-(const Vector2Temple<T>& u, const Vector2Temple<T>& u2)
{
	return Vector2Temple<T>(u.x - u2.x, u.y - u2.y);
}

