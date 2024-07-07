// pair hashing in stl for unordered_set/map

typedef pair<int, int> Value;
constexpr int P = 1696969;

namespace std {
    template<>
    struct hash<Value> {
        size_t operator() (const Value& x) const& {
            auto [a, b] = x;
            return (a * P) + b;
        }
    };
}
