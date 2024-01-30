#pragma once

#include <algorithm>
#include <vector>
#include <stdexcept>

namespace cam {
	namespace detail {
		template<class T>
		class FVector {
		private:
			using iterator = typename std::vector<T>::iterator;
			using const_iterator = typename std::vector<T>::const_iterator;

		public:
			FVector(std::initializer_list<T> cdata) : vdata(cdata) {}

			void sort() {
				std::sort(vdata.begin(), vdata.end());
			}

			const size_t& size() const noexcept {
				return vdata.size();
			}

			void pop(size_t i) {
				vdata.erase(vdata.begin() + i);
			}

			void remove(const T &id) {
				for (int i = 0; i < vdata.size(); ++i) {
					if (id == vdata[i]) {
						pop(i);
					}
				}
			}

			T& operator[](size_t i) {
				if (i >= vdata.size()) {
					throw std::out_of_range("Index out of range");
				}
				return vdata[i];
			}

			const T& operator[](size_t i) const {
				if (i >= vdata.size()) {
					throw std::out_of_range("Index out of range");
				}
				return vdata[i];
			}

			iterator begin() {
				return vdata.begin();
			}

			const_iterator begin() const {
				return vdata.begin();
			}

			iterator end() {
				return vdata.end();
			}

			const_iterator end() const {
				return vdata.end();
			}

		private:
			const size_t x_min() const {
				size_t low_i = 0;
				for (int i = 0; i < vdata.size(); ++i) {
					if (vdata[low_i] > vdata[i]) {
						low_i = i;
					}
				}
				return low_i;
			}

			std::vector<T> vdata;

			template<typename U>
			friend std::ostream& operator<<(std::ostream&, const FVector<U>&);
		};

		template<typename T>
		std::ostream& operator<<(std::ostream &os, const FVector<T> &vec) {
			for (const auto &e : vec.vdata) {
				os << e << '\n';
			}
			return os;
		}
	}

	template<typename T>
	using fvec = detail::FVector<T>;
};