/*
 * Copyright (C) 2004-2008 Geometer Plus <contact@geometerplus.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __ZLTEXTPARAGRAPHBUILDER_H__
#define __ZLTEXTPARAGRAPHBUILDER_H__

#include <vector>
#include <string>

#include <fribidi/fribidi.h>

#include <ZLUnicodeUtil.h>

#include "ZLTextElement.h"

class ZLTextParagraph;

class ZLTextParagraphBuilder {

public:
	ZLTextParagraphBuilder(const std::string &language, const ZLTextParagraph &paragraph, const std::vector<ZLTextMark> &marks, int index, ZLTextElementVector &elements);
	void fill();

private:
	void processTextEntry(const ZLTextEntry &textEntry);
	void addWord(const char *ptr, int offset, int len);
	void updateRTLState(bool state);
	void insertRSElement();

private:
	const ZLTextParagraph &myParagraph;
	ZLTextElementVector &myElements;

	std::vector<ZLTextMark>::const_iterator myFirstMark;
	std::vector<ZLTextMark>::const_iterator myLastMark;
	int myOffset;

	const std::string myLanguage;
	const bool myRTL;
	bool myCurrentRTL;

	std::vector<char> myBreaksTable;

	FriBidiCharType myBidiCharType;
	ZLUnicodeUtil::Ucs4String myUcs4String;
	std::vector<FriBidiLevel> myBidiLevels;
};

#endif /* __ZLTEXTPARAGRAPHBUILDER_H__ */
