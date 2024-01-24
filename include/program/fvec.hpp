#pragma once

template<class T>
class FVector {
    public:
        FVector(std::initializer_list<T> cdata) : vsize(cdata.size()) {
            int i = 0;
            for (const auto &c : cdata) {
                if (i >= vsize) {
                    break;
                }
                vdata[i++] = c;
            }
        }

        const size_t& size() const {
            return vsize;
        }

        void log() {
            for (int i = 0; i < vsize; ++i) {
                std::cout << vdata[i] << '\n';
            }
        }

    private:
        T vdata[256]; // dynamic size according to cdata.size()/vsize in constructor
        size_t vsize;
};

template<typename T>
using fvec = FVector<T>;