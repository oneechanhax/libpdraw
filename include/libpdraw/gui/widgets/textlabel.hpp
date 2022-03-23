/*
 * CTextLabel.h
 *
 *  Created on: Jan 26, 2017
 *      Author: nullifiedcat
 */

#pragma once

#include "basewidget.hpp"

class CTextLabel : public CBaseWidget {
public:
	CTextLabel(std::string name = "unnamed", IWidget* parent = nullptr, std::string text = "", bool centered = false);

	void SetText(std::string text);
	std::string GetText();
	void SetPadding(int x, int y);
	void SetAutoSize(bool autosize);
	void SetCentered(bool centered);

	virtual void Draw(int x, int y);
};
