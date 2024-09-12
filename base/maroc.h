#ifndef _ROC_MAROC_H_
#define _ROC_MAROC_H_

#include <functional>
#include <optional>
#include <type_traits>
#include <variant>

namespace roc{

/// 如果不为空则调用， 省去调用方的判空逻辑
template <typename Callable, typename... Args>
void
safe_invoke(Callable&& callable, Args&&... args) {
    if (callable) {
        return std::invoke(std::forward<Callable>(callable), std::forward<Args>(args)...);
    }
}

}

#endif // _ROC_MAROC_H_