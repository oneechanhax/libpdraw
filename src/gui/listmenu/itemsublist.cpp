
/*
 * Libpdw: Primitives Done Well!
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

#include <glez/color.hpp>
#include <glez/draw.hpp>
#include <stdexcept>

#include "gui/canvas.hpp"
#include "gui/listmenu/itemsublist.hpp"

namespace menu {
namespace ncc {

ItemSublist::ItemSublist(std::string title, List* list)
    : Item("ncc_item_sublist")
    , title(title)
    , list(list) {
}

void ItemSublist::SetParent(IWidget* widget) {
    Item::SetParent(widget);
    List* listp = dynamic_cast<List*>(widget);
    if (!listp)
        throw std::runtime_error("ItemSublist parent isnt List");
    listp->AddChild(list);
}

bool ItemSublist::IsHovered() {
    List* parent = dynamic_cast<List*>(GetParent());
    if (!parent)
        throw std::runtime_error("Sublist parent can't be casted to List!");
    return Item::IsHovered() || (dynamic_cast<List*>(parent->open_sublist) == list && !parent->open_sublist->ShouldClose());
}

void ItemSublist::Update() {
    if (!IsHovered()) {
        List* parent = dynamic_cast<List*>(GetParent());
        if (!parent)
            throw std::runtime_error("Sublist parent can't be casted to List!");
        if (dynamic_cast<List*>(parent->open_sublist) == list) {
            parent->OpenSublist(nullptr, 0);
        }
    }
}

void ItemSublist::Draw(int x, int y) {
    Item::Draw(x, y);
    List* parent = dynamic_cast<List*>(GetParent());
    if (!parent)
        throw std::runtime_error("Sublist parent can't be casted to List!");
    const auto& size = GetSize();
    if (parent->open_sublist == list)
        glez::draw::rect(x, y, size.first, size.second, Transparent(this->GetCanvas()->GetColor(), 0.5f));
    glez::draw::string(x + 2, y, (IsHovered() ? "[-] " : "[+] ") + title, this->GetCanvas()->GetFont(), glez::color::white, nullptr, nullptr);
}

void ItemSublist::OnKeyPress(CatKey code, bool repeated) {
    Item::OnKeyPress(code, repeated);
}

void ItemSublist::OnMouseEnter() {
    Item::OnMouseEnter();
    List* parent = dynamic_cast<List*>(GetParent());
    if (!parent)
        throw std::runtime_error("Sublist parent can't be casted to List!");
    parent->OpenSublist(list, GetOffset().second - 1);
}

void ItemSublist::OnMouseLeave() {
    Item::OnMouseLeave();
    List* parent = dynamic_cast<List*>(GetParent());
    if (!parent)
        throw std::runtime_error("Sublist parent can't be casted to List!");
    if (dynamic_cast<List*>(parent->open_sublist)) {
        if (parent->open_sublist->ShouldClose()) {
            //			parent->OpenSublist(nullptr, 0);
        }
    }
}

}
} // namespace menu::ncc
