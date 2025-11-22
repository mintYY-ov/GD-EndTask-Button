#include <Geode/Geode.hpp>
#include <Geode/utils/general.hpp>
#include <Geode/utils/terminate.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto endButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_cancelDownloadBtn_001.png"),
			this,
			menu_selector(MyMenuLayer::onendButton)
		);

		auto menu = this->getChildByID("top-menu");
		menu->addChild(endButton);

		endButton->setID("end-task"_spr);

		menu->updateLayout();

		return true;
	}

	void onendButton(CCObject*) {
		geode::createQuickPopup(
			"Terminate Game",
			"Do you want to <cr>terminate</c> the game? <cl>This will also remove any unsaved data, like a crash.</c>",
			"Cancel", "Terminate",
			[](auto, bool btn2) {
				if (btn2) {
					geode::utils::terminate()
				}
			}
		);
	}
};
