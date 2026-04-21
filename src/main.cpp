#include <Geode/Geode.hpp>
#include <Geode/modify/EndLevelLayer.hpp>

using namespace geode::prelude;

class $modify(MyEndLevelLayer, EndLevelLayer) {
    bool init() {
        // Сначала запускаем оригинал, чтобы все кнопки создались
        if (!EndLevelLayer::init()) {
            return false;
        }

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        // Создаем спрайт с мемом
        auto memeSprite = CCSprite::create("meme.png");
        
        if (memeSprite) {
            // Ставим в центр
            memeSprite->setPosition({winSize.width / 2, winSize.height / 2});
            
            // Растягиваем под размер экрана
            float scaleX = winSize.width / memeSprite->getContentSize().width;
            float scaleY = winSize.height / memeSprite->getContentSize().height;
            memeSprite->setScaleX(scaleX);
            memeSprite->setScaleY(scaleY);

            // Устанавливаем ZOrder на -1, чтобы картинка была САМЫМ задним планом
            // Все стандартные кнопки будут ПОВЕРХ неё
            memeSprite->setZOrder(-1);
            
            this->addChild(memeSprite);
        }

        return true;
    }
};