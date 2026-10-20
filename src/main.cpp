#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class $modify(ColabEditorEditorUI, EditorUI) {
    bool init(LevelEditorLayer* editorLayer) {
        if (!EditorUI::init(editorLayer))
            return false;

        auto menu = CCMenu::create();
        if (!menu)
            return true;

        menu->setID("colabeditor-menu"_spr);
        menu->setPosition({ 0.f, 0.f });

        auto label = CCLabelBMFont::create("COLAB", "goldFont.fnt");
        if (!label)
            return true;
        label->setScale(0.42f);

        auto button = CCMenuItemSpriteExtra::create(
            label,
            this,
            menu_selector(ColabEditorEditorUI::onColabEditor)
        );
        if (!button)
            return true;

        button->setPosition({ 45.f, 45.f });
        menu->addChild(button);
        this->addChild(menu, 100);

        return true;
    }

    void onColabEditor(CCObject*) {
        FLAlertLayer::create(
            "COLABEDITOR",
            "Collaborative editor prototype.\n\nSupabase synchronization is not connected yet.",
            "Close"
        )->show();
    }
};
