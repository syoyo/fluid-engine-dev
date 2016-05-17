// Copyright (c) 2016 Doyub Kim

#ifndef INCLUDE_JET_DETAIL_ARRAY_ACCESSOR3_INL_H_
#define INCLUDE_JET_DETAIL_ARRAY_ACCESSOR3_INL_H_

#include <algorithm>

namespace jet {

template <typename T>
ArrayAccessor<T, 3>::ArrayAccessor() : _data(nullptr) {
}

template <typename T>
ArrayAccessor<T, 3>::ArrayAccessor(const Size3& size, T* const data) {
    reset(size, data);
}

template <typename T>
ArrayAccessor<T, 3>::ArrayAccessor(
    size_t width, size_t height, size_t depth, T* const data) {
    reset(width, height, depth, data);
}

template <typename T>
ArrayAccessor<T, 3>::ArrayAccessor(const ArrayAccessor& other) {
    set(other);
}

template <typename T>
void ArrayAccessor<T, 3>::set(const ArrayAccessor& other) {
    reset(other._size, other._data);
}

template <typename T>
void ArrayAccessor<T, 3>::reset(const Size3& size, T* const data) {
    _size = size;
    _data = data;
}

template <typename T>
void ArrayAccessor<T, 3>::reset(
    size_t width, size_t height, size_t depth, T* const data) {
    reset(Size3(width, height, depth), data);
}

template <typename T>
T& ArrayAccessor<T, 3>::at(size_t i) {
    JET_ASSERT(i < _size.x*_size.y*_size.z);
    return _data[i];
}

template <typename T>
const T& ArrayAccessor<T, 3>::at(size_t i) const {
    JET_ASSERT(i < _size.x*_size.y*_size.z);
    return _data[i];
}

template <typename T>
T& ArrayAccessor<T, 3>::at(const Point3UI& pt) {
    return at(pt.x, pt.y, pt.z);
}

template <typename T>
const T& ArrayAccessor<T, 3>::at(const Point3UI& pt) const {
    return at(pt.x, pt.y, pt.z);
}

template <typename T>
T& ArrayAccessor<T, 3>::operator()(const Point3UI &pt) {
    JET_ASSERT(pt.x < _size.x && pt.y < _size.y && pt.z < _size.z);
    return _data[pt.x + _size.x * (pt.y + _size.y * pt.z)];
}

template <typename T>
const T& ArrayAccessor<T, 3>::operator()(const Point3UI &pt) const {
    JET_ASSERT(pt.x < _size.x && pt.y < _size.y && pt.z < _size.z);
    return _data[pt.x + _size.x * (pt.y + _size.y * pt.z)];
}

template <typename T>
T& ArrayAccessor<T, 3>::at(size_t i, size_t j, size_t k) {
    JET_ASSERT(i < _size.x && j < _size.y && k < _size.z);
    return _data[i + _size.x * (j + _size.y * k)];
}

template <typename T>
const T& ArrayAccessor<T, 3>::at(size_t i, size_t j, size_t k) const {
    JET_ASSERT(i < _size.x && j < _size.y && k < _size.z);
    return _data[i + _size.x * (j + _size.y * k)];
}

template <typename T>
Size3 ArrayAccessor<T, 3>::size() const {
    return _size;
}

template <typename T>
size_t ArrayAccessor<T, 3>::width() const {
    return _size.x;
}

template <typename T>
size_t ArrayAccessor<T, 3>::height() const {
    return _size.y;
}

template <typename T>
size_t ArrayAccessor<T, 3>::depth() const {
    return _size.z;
}

template <typename T>
T* const ArrayAccessor<T, 3>::data() const {
    return _data;
}

template <typename T>
void ArrayAccessor<T, 3>::setData(const T* data) {
    _data = data;
}

template <typename T>
void ArrayAccessor<T, 3>::swap(ArrayAccessor& other) {
    std::swap(other._data, _data);
    std::swap(other._size, _size);
}

template <typename T>
size_t ArrayAccessor<T, 3>::index(const Point3UI& pt) const {
    JET_ASSERT(pt.x < _size.x && pt.y < _size.y && pt.z < _size.z);
    return pt.x + _size.x * (pt.y + _size.y * pt.z);
}

template <typename T>
size_t ArrayAccessor<T, 3>::index(size_t i, size_t j, size_t k) const {
    JET_ASSERT(i < _size.x && j < _size.y && k < _size.z);
    return i + _size.x * (j + _size.y * k);
}

template <typename T>
T& ArrayAccessor<T, 3>::operator[](size_t i) {
    return _data[i];
}

template <typename T>
const T& ArrayAccessor<T, 3>::operator[](size_t i) const {
    return _data[i];
}

template <typename T>
T& ArrayAccessor<T, 3>::operator()(size_t i, size_t j, size_t k) {
    JET_ASSERT(i < _size.x && j < _size.y && k < _size.z);
    return _data[i + _size.x * (j + _size.y * k)];
}

template <typename T>
const T& ArrayAccessor<T, 3>::operator()(size_t i, size_t j, size_t k) const {
    JET_ASSERT(i < _size.x && j < _size.y && k < _size.z);
    return _data[i + _size.x * (j + _size.y * k)];
}

template <typename T>
ArrayAccessor<T, 3>& ArrayAccessor<T, 3>::operator=(
    const ArrayAccessor& other) {
    set(other);
    return *this;
}


template <typename T>
ConstArrayAccessor<T, 3>::ConstArrayAccessor() : _data(nullptr) {
}

template <typename T>
ConstArrayAccessor<T, 3>::ConstArrayAccessor(
    const Size3& size, const T* const data) {
    _size = size;
    _data = data;
}

template <typename T>
ConstArrayAccessor<T, 3>::ConstArrayAccessor(
    size_t width, size_t height, size_t depth, const T* const data) {
    _size = Size3(width, height, depth);
    _data = data;
}

template <typename T>
ConstArrayAccessor<T, 3>::ConstArrayAccessor(const ArrayAccessor<T, 3>& other) {
    _size = other.size();
    _data = other.data();
}

template <typename T>
ConstArrayAccessor<T, 3>::ConstArrayAccessor(const ConstArrayAccessor& other) {
    _size = other._size;
    _data = other._data;
}

template <typename T>
const T& ConstArrayAccessor<T, 3>::at(size_t i) const {
    JET_ASSERT(i < _size.x*_size.y*_size.z);
    return _data[i];
}

template <typename T>
const T& ConstArrayAccessor<T, 3>::at(const Point3UI& pt) const {
    return at(pt.x, pt.y, pt.z);
}

template <typename T>
const T& ConstArrayAccessor<T, 3>::at(size_t i, size_t j, size_t k) const {
    JET_ASSERT(i < _size.x && j < _size.y && k < _size.z);
    return _data[i + _size.x * (j + _size.y * k)];
}

template <typename T>
Size3 ConstArrayAccessor<T, 3>::size() const {
    return _size;
}

template <typename T>
size_t ConstArrayAccessor<T, 3>::width() const {
    return _size.x;
}

template <typename T>
size_t ConstArrayAccessor<T, 3>::height() const {
    return _size.y;
}

template <typename T>
size_t ConstArrayAccessor<T, 3>::depth() const {
    return _size.z;
}

template <typename T>
const T* const ConstArrayAccessor<T, 3>::data() const {
    return _data;
}

template <typename T>
size_t ConstArrayAccessor<T, 3>::index(const Point3UI& pt) const {
    JET_ASSERT(pt.x < _size.x && pt.y < _size.y && pt.z < _size.z);
    return pt.x + _size.x * (pt.y + _size.y * pt.z);
}

template <typename T>
size_t ConstArrayAccessor<T, 3>::index(size_t i, size_t j, size_t k) const {
    JET_ASSERT(i < _size.x && j < _size.y && k < _size.z);
    return i + _size.x * (j + _size.y * k);
}

template <typename T>
const T& ConstArrayAccessor<T, 3>::operator[](size_t i) const {
    return _data[i];
}

template <typename T>
const T& ConstArrayAccessor<T, 3>::operator()(
    size_t i, size_t j, size_t k) const {
    JET_ASSERT(i < _size.x && j < _size.y && k < _size.z);
    return _data[i + _size.x * (j + _size.y * k)];
}

template <typename T>
const T& ConstArrayAccessor<T, 3>::operator()(const Point3UI &pt) const {
    JET_ASSERT(pt.x < _size.x && pt.y < _size.y && pt.z < _size.z);
    return _data[pt.x + _size.x * (pt.y + _size.y * pt.z)];
}

}  // namespace jet

#endif  // INCLUDE_JET_DETAIL_ARRAY_ACCESSOR3_INL_H_