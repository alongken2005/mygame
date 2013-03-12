#include "HelloWorldScene.h"
#include "cocos-ext.h"

using namespace cocos2d;
USING_NS_CC_EXT;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! CCLayer::init());

		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();  
		cache->addSpriteFramesWithFile("cs_female_attacka.plist", "cs_female_attacka.png");
		CCArray* framesArray = CCArray::create();

		char str[80];
		int count = 8;
		for(int i = 1; i <= count; i++)  
		{  
			sprintf(str, "cs_female_attacka_%d.png", i);  
			framesArray->addObject(cache->spriteFrameByName(str));  
		}
		
		CCAnimation* animation = CCAnimation::createWithSpriteFrames(framesArray, 0.1f);  
		animation->setLoops(-1);    // ����ѭ������  
		animation->setRestoreOriginalFrame(true); 

		CCSprite* girlSprite = CCSprite::createWithSpriteFrameName("cs_female_attacka_1.png");  
		CCSize size = CCDirector::sharedDirector()->getWinSize();  
		girlSprite->setPosition(ccp(size.width / 2, size.height / 2));  
  
		/*  �þ���ִ��һ�������� 
		animation�����ƣ�animate�Ƕ��ʣ� 
			����Ҫ��������Ҫ��CCAnimate����һ���ᶯ�Ķ�����������ô����ģ��ٺ� 
		*/  
		girlSprite->runAction(CCAnimate::create(animation));  
  
		this->addChild(girlSprite); 


        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

void HelloWorld::update( float fDelta )  
{  
	CCLOG("update");  
} 

