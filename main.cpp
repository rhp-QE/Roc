#include <iostream>
#include <memory>
#include <unordered_set>
#include "base/maroc.h"
#include "base/noncopyable.h"
#include "mm.h"
#include "test.h"

using namespace::std;

// 求最大公约数
int gcd(int a, int b) {
    return a + b;
}

int main() {
    std::unordered_set<std::unique_ptr<int>> set;
    set.insert(std::make_unique<int>(1));
    set.insert(std::make_unique<int>(2));
    std::unordered_map<int, int> map;
    map.insert({1, 1});
    auto res = map.find(3)->second;
   // cout<<res<<endl;
    return 0;
}