/*
 * CTextInput.h
 *
 *  Created on: Jan 26, 2017
 *      Author: nullifiedcat
 */

#pragma once

#include "basewidget.hpp"

class CTextInput;

typedef std::function<void(CTextInput*, std::string, std::string)> TextInputCallbackFn_t;

class CTextInput : public CBaseWidget {
public:
	CTextInput(std::string name = "unnamed", IWidget* parent = nullptr);

	virtual void OnKeyPress(CatKey key, bool repeat);
	virtual void Draw(int x, int y);
	virtual bool ConsumesKey(CatKey key);

	void PutChar(char ch);
	void SetLength(int newlength);
	void SetMaxWidth(int width);
	void SetCallback(TextInputCallbackFn_t callback);
	std::string Value();
	void SetValue(std::string value);

	TextInputCallbackFn_t m_pCallback;
};
