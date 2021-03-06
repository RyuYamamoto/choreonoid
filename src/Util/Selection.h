/**
   @author Shin'ichiro Nakaoka
*/

#ifndef CNOID_UTIL_SELECTION_H
#define CNOID_UTIL_SELECTION_H

#include <vector>
#include <string>
#include "exportdecl.h"

namespace cnoid {

class CNOID_EXPORT Selection
{
public:
    explicit Selection(const char* domainname = 0);

    explicit Selection(size_t size, const char* domainname = 0);
        
    int size() const {
        return  symbols_.size();
    }

    operator bool() const {
        return !symbols_.empty() && selectedIndex_ >= 0;
    }
        
    void resize(int s);

    void clear();

    void setSymbol(int index, const std::string& symbol);

    Selection& operator<<(const std::string& symbol);

    std::string& symbol(int index) {
        return symbols_[index];
    }
        
    const std::string& symbol(int index) const {
        return symbols_[index];
    }
            
    int index(const std::string& symbol) const;

    const char* label(int index) const;

    bool select(int index);
    bool selectIndex(int index);
    bool select(const std::string& symbol);

    int selectedIndex() const {
        return selectedIndex_;
    }

    int which() const {
        return selectedIndex_;
    }

    bool is(int index) const {
        return (index == selectedIndex_);
    }

    const std::string& selectedSymbol() const {
        return symbols_[selectedIndex_];
    }

    const char* selectedLabel() const;

private:
    std::vector<std::string> symbols_;
    int selectedIndex_;
    const char* domainname_;
};

}

#endif
