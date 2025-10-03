#include <Geode/ui/LazySprite.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/Geode.hpp>
using namespace geode::prelude;

void loadIcon() {
	CCSize nodeSize{64.f, 64.f};

			auto spr1 = LazySprite::create(nodeSize, false);

			spr1->setLoadCallback([spr1](Result<> res) {
				if (res) {
					log::info("Sprite loaded!");
				} else {
					log::error("Sprite failed to load, error: {}", res.unwrapErr());
					spr1->initWithSpriteFrameName("GJ-cancel-Download-Btn-001.png"_spr);
				}
			});

			spr1->loadFromUrl("https://i.ibb.co/mrzzMx5M/GJ-cancel-Download-Btn-001.png");

			spr1->initWithSpriteFrameName("GJ-cancel-Download-Btn-001.png");
		}
