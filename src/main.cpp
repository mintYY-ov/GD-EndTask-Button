#include <Geode/Geode.hpp>
#include <Geode/utils/general.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ-cancel-Download-Btn-001.png"),
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);

		auto menu = this->getChildByID("top-menu");
		menu->addChild(myButton);

		myButton->setID("end-task"_spr);

		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
		geode::utils::game::exit(false);
	}
};