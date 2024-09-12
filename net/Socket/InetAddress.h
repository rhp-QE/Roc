#ifndef _ROC_INETADDRESS_H_
#define _ROC_INETADDRESS_H_

#include <concepts>
#include <string_view>
#include "base/copyable.h"

namespace roc {
namespace net {

class InetAddress : public roc::copyable {

public:
    int port();
    std::string_view ip();
    
private:
    int port_;
    std::string_view ip_;
};

}
}

#endif // _ROC_INETADDRESS_H_