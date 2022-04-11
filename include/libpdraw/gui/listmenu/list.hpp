
/*
 * Libpdraw: A Versitile GUI for use with a primitive drawing system!
 * Copyright (C) 2022 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LIST_HPP_
#define LIST_HPP_

#include <var.hpp>

#include "gui/widgets/basecontainer.hpp"

class Item;

namespace menu {
namespace ncc {

class List : public CBaseContainer {
public:
    List(std::string title);
    List();

    void Fill(ui::BaseVar*);
    void Fill(const std::string vec);
    void Fill(const std::vector<ui::BaseVar*>& vec);

    List* ForceGetSublist(std::string_view);
    List* FindSublist(std::string_view);
    List* CreateSublist(std::string_view);

    void OpenSublist(List* sublist, int dy);
    bool ShouldClose();

    static List* FromString(const std::string& string);

    // virtual IWidget* ChildByPoint(int x, int y) override;
    inline virtual void SortByZIndex() override {};
    virtual void Show() override;
    virtual void OnKeyPress(CatKey key, bool repeat) override;
    virtual void OnMouseEnter() override;
    virtual void OnMouseLeave() override;
    virtual void Draw(int x, int y) override;
    virtual void Update() override;
    virtual void MoveChildren() override;
    virtual void SetParent(IWidget* parent) override;

public:
    void Fill(ui::BaseVar*, int depth);
    List* root_list { nullptr };
    bool got_mouse { false };
    List* open_sublist { nullptr };
    std::string title;

private:
    int items;
};

}
} // namespace menu::ncc

#endif /* LIST_HPP_ */
