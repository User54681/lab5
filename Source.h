#pragma once
#ifndef source
#include <iostream>
#include <ctime>

template <typename T>
class matrix {
private:	
	T** data;
	unsigned int m, n; //m - rows, n - columns
public:
	matrix() {
        m = 3;
        n = 3;
        data = new T * [m];
        for (int i = 0; i < m; ++i) data[i] = new T[n];
    };
	matrix(unsigned int m, unsigned int n) {
        this->m = m;
        this->n = n;
        data = new T * [m];
        for (int i = 0; i < m; ++i) data[i] = new T[n];
    };
	~matrix() {
        for (int i = 0; i < m; ++i) {
            delete[] data[i];
        }
        delete[] data;
    };
	void random() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    };
	friend std::ostream& operator <<(std::ostream& os, const matrix<T>& mat) {
        for (unsigned int i = 0; i < mat.m; ++i) {
            for (unsigned int j = 0; j < mat.n; ++j) {
                os << mat.data[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    };
    /*friend std::ofstream& operator <<(std::ofstream& ofs, const matrix<T>& mat) {
        for (unsigned int i = 0; i < mat.m; ++i) {
            for (unsigned int j = 0; j < mat.n; ++j) {
                ofs << mat.data[i][j] << " ";
            }
            ofs << "\n";
        }
        return ofs;
    };*/
	matrix<T> operator+(const matrix<T>& other) {
        if (m == other.m and n == other.n) {
            matrix result(m, n);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            return result;
        }
        else std::cout << "������ ��������� ����� ������" << "\n";
    };
	matrix<T>& operator+=(const matrix<T>& other) {
        if (m == other.m and n == other.n) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    data[i][j] += other.data[i][j];
                }
            }
            std::cout << *this << "\n";
            return *this;
        }
        else std::cout << "������ ��������� ���� ������� � ������" << "\n";
    };
	matrix<T> operator-(const matrix<T>& other) {
        if (m == other.m and n == other.n) {
            matrix result(m, n);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    result.data[i][j] = data[i][j] - other.data[i][j];
                }
            }
            return result;
        }
        else std::cout << "������ ��������� �������� ������" << "\n";
    };
	matrix<T>& operator-=(const matrix<T>& other) {
        if (m == other.m and n == other.n) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    data[i][j] -= other.data[i][j];
                }
            }
            std::cout << *this << "\n";
            return *this;
        }
        else std::cout << "������ ������� �� ����� ������� ������" << "\n";
    };
	matrix<T> operator*(const matrix<T>& other) {
        if (m == other.n) {
            matrix result(m, other.n);
            for (unsigned int i = 0; i < m; ++i) {
                for (unsigned int j = 0; j < other.n; ++j) {
                    result.data[i][j] = 0;
                    for (unsigned int k = 0; k < n; ++k) {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }
        else std::cout << "���������� ��������� ������������ ������" << "\n";
    };
	bool operator ==(const matrix<T>& other) const {
        if (m != other.m || n != other.n) return false;

        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) return false;
            }
        }

        return true;
    };
	bool operator !=(const matrix<T>& other) const {
        return !(*this == other);
    };
};

#endif // !source