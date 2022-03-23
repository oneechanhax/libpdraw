/*
 * CCheckbox.h
 *
 *  Created on: Jan 26, 2017
 *      Author: nullifiedcat
 */

#pragma once

#include "basewidget.hpp"

class CCheckbox;

typedef std::function<void(CCheckbox*, bool)> CheckboxCallbackFn_t;

class CCheckbox : public CBaseWidget {
public:
	CCheckbox(std::string name = "unnamed", IWidget* parent = nullptr, bool checked = false);

	void SetWidth(int width);
	inline bool Value() { return Props()->GetBool("checked"); }
	inline void SetValue(bool value) { Props()->SetBool("checked", value); }
	void SetCallback(CheckboxCallbackFn_t callback);

	virtual void OnMousePress();
	virtual void Draw(int x, int y);

	CheckboxCallbackFn_t m_pCallback;

};
