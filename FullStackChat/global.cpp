#include "global.h"

// 相当于右键刷新
std::function<void (QWidget *)> repolist = [](QWidget *w){
    // 去除原来的qss样式
    w->style()->unpolish(w);

    // 添加新样式
    w->style()->polish(w);
};
