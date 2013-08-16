#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)) )
    {
        return false;
    }
    
    //CCCallFunc家族函数：当我们需要在一个动作完成之后需要调用某个函数时使用
    

    CCSprite* player = CCSprite::create("Icon.png");
    player->setPosition(ccp(100, 100));
    this->addChild(player);
    CCMoveTo* action = CCMoveTo::create(1, ccp(200, 200));
    //CCCallFunc的功能非常简单，它只能简单地实现在动作序列中帮助我们调用一个函数的功能。
//    CCCallFunc* call  = CCCallFunc::create(this, callfunc_selector(HelloWorld::callBack));
//    //下面这行代码是创建一个动作序列
//    CCFiniteTimeAction* seq = CCSequence::create(action,call,NULL);
//    player->runAction(seq);
    
    
    
    
    //CCCallFuncN  既能够调用一个方法还能够将调用的对象传过去  这里的调用对象就是player  它是个精灵对象
//    CCCallFuncN* callN = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::callNodeBack));
//    CCFiniteTimeAction* seq2 = CCSequence::create(action,callN,NULL);
//    player->runAction(seq2);
    
    
    //先创建一个字典
    CCDictionary* dic = CCDictionary::create();
    dic->retain();
    dic->setObject(CCString::create("zxcc"), 1);
    
    //CCCallFuncND可以传递一个任意数据类型  例如，我们可以传递一个字典
//    CCCallFuncND* callND = CCCallFuncND::create(this, callfuncND_selector(HelloWorld::callNodeBack),(void*)dic);
//    CCFiniteTimeAction* seq3 = CCSequence::create(action,callND,NULL);
//    player->runAction(seq3);
    
    
    
    
   
    //我们创建一个精灵
    CCSprite* player2 = CCSprite::create("player2.png");
    player2->setPosition(ccp(300, 300));
    this->addChild(player2);
    //在例子中我先移动一个精灵 ，再移动另一个精灵
   // CCCallFuncND传值的类型只能为CCObject类型
    CCCallFuncO* callO = CCCallFuncO::create(this, callfuncO_selector(HelloWorld::callObjectBack), player2);
    CCFiniteTimeAction* seq4 = CCSequence::create(action,callO,NULL);
    player->runAction(seq4);
    return true;
}

                                                

//CCCallFunc的回调函数
void HelloWorld::callBack()
{
    CCLog("CCCallFunc");
}

//CCCallFuncN的回调函数
void HelloWorld::callNodeBack(cocos2d::CCNode *sender)
{
    CCSprite* player = (CCSprite*) sender;
    CCLog("%f",player->getPosition().x);
}

//CCCallFuncND的回调函数
void HelloWorld::callNodeBack(cocos2d::CCNode *sender, void * data)
{
    CCDictionary* dic = (CCDictionary*)data;

    CCString* str = (CCString*)(dic->objectForKey(1));
    
      CCLog("%s",str->getCString());
}

//CCCallFuncO的回调方法
void HelloWorld::callObjectBack(cocos2d::CCObject *data)
{
    CCSprite* player = (CCSprite*)data;
    
    player->runAction(CCMoveTo::create(1, ccp(1 ,90)));
  
}



