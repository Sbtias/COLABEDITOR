#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class ColabEditorPopup final : public geode::Popup<> {
protected:
    bool setup() override {
        this->setTitle("COLABEDITOR");

        auto size = m_mainLayer->getContentSize();

        auto status = CCLabelBMFont::create(
            "LOCAL PROTOTYPE",
            "bigFont.fnt"
        );
        status->setScale(0.45f);
        status->setPosition({ size.width / 2.f, size.height - 48.f });
        m_mainLayer->addChild(status);

        auto info = CCLabelBMFont::create(
            "Collaborative editor tools",
            "bigFont.fnt"
        );
        info->setScale(0.35f);
        info->setPosition({ size.width / 2.f, size.height - 82.f });
        m_mainLayer->addChild(info);

        auto session = CCLabelBMFont::create(
            "Session: not connected",
            "bigFont.fnt"
        );
        session->setScale(0.35f);
        session->setPosition({ size.width / 2.f, size.height - 116.f });
        m_mainLayer->addChild(session);

        auto note = CCLabelBMFont::create(
            "Supabase sync is not wired up yet.",
            "bigFont.fnt"
        );
        note->setScale(0.28f);
        note->setPosition({ size.width / 2.f, 35.f });
        m_mainLayer->addChild(note);

        return true;
    }

public:
    static ColabEditorPopup* create() {
        auto ret = new ColabEditorPopup();
        if (ret->initAnchored(260.f, 190.f)) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }
};

class $modify(ColabEditorEditorUI, EditorUI) {
    bool init(LevelEditorLayer* editorLayer) {
        if (!EditorUI::init(editorLayer))
            return false;

        auto menu = CCMenu::create();
        menu->setID("colabeditor-menu"_spr);
        menu->setPosition({ 0.f, 0.f });

        auto label = CCLabelBMFont::create("COLAB", "goldFont.fnt");
        label->setScale(0.42f);

        auto button = CCMenuItemSpriteExtra::create(
            label,
            this,
            menu_selector(ColabEditorEditorUI::onColabEditor)
        );
        button->setPosition({ 45.f, 45.f });
        menu->addChild(button);
        this->addChild(menu, 100);

        return true;
    }

    void onColabEditor(CCObject*) {
        ColabEditorPopup::create()->show();
    }
};
