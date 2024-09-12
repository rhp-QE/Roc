#ifndef _ROC_NONCOPYABLE_H_
#define _ROC_NONCOPYABLE_H_

namespace roc {

class noncopyable {
public:
    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;

protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

} // namespcae roc


#endif // _ROC_NONCOPYABLE_H_