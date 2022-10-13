#pragma once
#include <vector>
#include <memory>
#include "TextLine.h"

class Page
{
public:
	void AddCharToCurrentLine(char c);
	void HandleNewLine();
	void DeleteCurrentLine();
	void MoveCursorLeft();
	void MoveCursorRight();
	void MoveDownLine();
	void MoveUpLine();

	void DeleteCharacterAfterCursor();
	void DeleteCharacterAtCursor();

	void GetCursorXY(int& x, int& y);
	void Draw();
private:
	int m_LineIndex = -1;
	std::vector<std::unique_ptr<TextLine>> m_Lines;

};