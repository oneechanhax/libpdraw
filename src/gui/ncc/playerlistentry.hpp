/*
 * PlayerListEntry.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: nullifiedcat
 */

#pragma once

//#include <gui/widgets/basecontainer.hpp>
//#include "menu.hpp"

/*namespace menu { namespace ncc {

class PlayerListEntry : public CBaseContainer {
public:
        PlayerListEntry(int eid);
        inline virtual void SortByZIndex() override {};
        virtual void Draw(int x, int y) override;
        virtual void MoveChildren() override;
        virtual void Update() override;
        virtual void OnKeyPress(CatKey key, bool repeat) override;
public:
        const int idx;
};

namespace entrysubs {

class SubBase : public CBaseWidget {
public:
        SubBase(PlayerListEntry&);
        virtual void Draw(int x, int y) override;
public:
        PlayerListEntry& parent;
        int color_fg { 0 };
        int color_bg { 0 };
        std::string text { "" };
};
class SubTitle : public SubBase {
public:
        SubTitle(PlayerListEntry& parent, const std::string& title);
        virtual void Draw(int x, int y) override;
};
class SubState : public SubBase {
public:
        inline SubState(PlayerListEntry& parent) : SubBase(parent) {};
        virtual void Update() override;
        virtual bool ConsumesKey(CatKey key) override;
        virtual void OnKeyPress(CatKey key, bool repeat) override;
};
class SubColorComponent : public SubBase {
public:
        enum class Component {
                R,
                G,
                B
        };
        SubColorComponent(PlayerListEntry&, Component);
        virtual void Update() override;
        virtual bool ConsumesKey(CatKey key) override;
        virtual void OnKeyPress(CatKey key, bool repeat) override;
public:
        const Component component;
};

}

}}*/
