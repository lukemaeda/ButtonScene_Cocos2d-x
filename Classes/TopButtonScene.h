//
//  TopButtonScene.h
//  ButtonScene
//
//  Created by MAEDAHAJIME on 2015/02/03.
//
//

#ifndef __ButtonScene__TopButtonScene__
#define __ButtonScene__TopButtonScene__

#include "cocos2d.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class TopButtonScene : public Layer
{
    
public:
    
    // 初期化のメソッド
    virtual bool init();
    
    
    static cocos2d::Scene* createScene();
    
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushStart(Ref *pSender);
    
    // iOSで言えば グローバル ラベル
    Label* label1;
    
    // create()を使えるようにしている。
    CREATE_FUNC(TopButtonScene);
};


#endif /* defined(__Label__TopButtonScene__) */