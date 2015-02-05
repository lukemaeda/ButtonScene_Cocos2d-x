//
//  TopButtonScene.cpp
//  ButtonScene
//
//  Created by MAEDAHAJIME on 2015/02/03.
//
//

#include "TopButtonScene.h"
//音をならすためにinclude
#include "SimpleAudioEngine.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

Scene* TopButtonScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = TopButtonScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}


// 「INIT」初期化
bool TopButtonScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 画面の座標関係の詳しい説明はここ http://www.cocos2d-x.org/wiki/Coordinate_System
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    // ラベルを生成
    label1 = Label::createWithSystemFont("Cocos2d-x", "Arial", 120);

    // ラベルの設置
    label1->setPosition(Point(winSize.width /2 ,winSize.height/1.5));
    
    // ラベルタイトルを追加
    this->addChild(label1,1);
    
    // スタートボタンを設置
    auto startButton = MenuItemImage::create(
                        "CloseNormal01.png",  // 通常状態の画像
                        "CloseSelected01.png",  // 押下状態の画像
                        CC_CALLBACK_1(TopButtonScene::pushStart, this)); // 押下時のアクション
    // ボタンの設置
    startButton->setPosition(Point(winSize.width /2 ,winSize.height/2.7));
    
    // メニューを作成 自動解放オブジェクト
    auto menu = Menu::create(startButton, NULL);
    //
    menu->setPosition(Point::ZERO);
    // メニューを追加
    this->addChild(menu, 1);
    
    return true;
}

// pushStartボタン
void TopButtonScene::pushStart(Ref *pSender)
{
    CCLOG("Pushボタン");
    
    // 効果音を鳴らす
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
    
    // ラベルの文字変更
    label1->setString("Hello Cocos2d-x");

}
