/*
 * CBaseContainer.h
 *
 *  Created on: Jan 30, 2017
 *      Author: nullifiedcat
 */

#pragma once

#include "basewidget.hpp"

class CBaseContainer : public CBaseWidget, public virtual IWidget {
public:
    CBaseContainer(std::string name = "unnamed", IWidget* parent = nullptr);
    virtual ~CBaseContainer();

    void AddChild(IWidget* child);
    int ChildCount();
    virtual IWidget* ChildByIndex(int idx);
    virtual IWidget* ChildByName(std::string name);
    virtual IWidget* ChildByPoint(int x, int y);

    virtual bool ConsumesKey(CatKey key);
    virtual void Draw(int x, int y);
    virtual void DrawBounds(int x, int y);
    virtual void Hide();
    virtual void OnFocusLose();
    virtual void OnKeyPress(CatKey key, bool repeat);
    virtual void OnKeyRelease(CatKey key);
    virtual void OnMouseLeave();
    virtual void OnMousePress();
    virtual void OnMouseRelease();
    virtual void Update();
    virtual void HandleCustomEvent(std::string_view event);

    virtual void SortByZIndex();
    void UpdateHovers();

    virtual void MoveChildren();

    IWidget* GetHoveredChild();
    IWidget* GetFocusedChild();
    IWidget* GetPressedChild();
    void HoverOn(IWidget* child);
    void FocusOn(IWidget* child);
    void PressOn(IWidget* child);

    IWidget* m_pHoveredChild;
    IWidget* m_pFocusedChild;
    IWidget* m_pPressedChild;

    std::vector<IWidget*> m_children;
};
