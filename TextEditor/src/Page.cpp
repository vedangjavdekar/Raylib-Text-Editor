#include "Page.h"
#include "raylib.h"
#include <cstdlib>

void Page::AddCharToCurrentLine(char c)
{
	if (m_LineIndex > -1)
	{
		m_Lines[m_LineIndex]->InsertCharacterAtCursor(c);
	}
}

void Page::HandleNewLine()
{
	if (m_LineIndex == m_Lines.size() - 1)
	{
		m_Lines.emplace_back(std::make_unique<TextLine>());
		m_LineIndex = (int)m_Lines.size() - 1;
	}
	else
	{
		m_Lines.insert(m_Lines.begin() + m_LineIndex + 1, std::make_unique<TextLine>());
		m_LineIndex++;
	}
}

void Page::DeleteCurrentLine()
{
	if (m_Lines.size() > 1)
	{
		m_Lines.erase(m_Lines.begin() + m_LineIndex);
		if (m_LineIndex == m_Lines.size())
		{
			m_LineIndex--;
		}
	}
}

void Page::MoveCursorLeft()
{
	if (m_LineIndex > -1)
	{
		m_Lines[m_LineIndex]->MoveCursorLeft();
	}
}

void Page::MoveCursorRight()
{
	if (m_LineIndex > -1)
	{
		m_Lines[m_LineIndex]->MoveCursorRight();
	}
}

void Page::MoveDownLine()
{
	if (m_LineIndex < m_Lines.size() - 1)
	{
		m_LineIndex++;
	}
}

void Page::MoveUpLine()
{
	if (m_LineIndex > 0)
	{
		m_LineIndex--;
	}
}

void Page::DeleteCharacterAfterCursor()
{
	if (m_LineIndex > -1)
	{
		if (m_Lines[m_LineIndex]->Size() == 0)
		{
			DeleteCurrentLine();
			return;
		}
		m_Lines[m_LineIndex]->DeleteCharacterAfterCursor();
	}
}

void Page::DeleteCharacterAtCursor()
{
	if (m_LineIndex > -1)
	{
		if (m_Lines[m_LineIndex]->Size() == 0)
		{
			DeleteCurrentLine();
			return;
		}
		m_Lines[m_LineIndex]->DeleteCharacterAtCursor();
	}
}

void Page::Draw()
{
	static char buffer[20];
	DrawRectangle(0, 0, 20, 720, LIGHTGRAY);
	for (int i = 0; i < m_Lines.size(); ++i)
	{
		const char* lineNumber = _itoa(i + 1, buffer, 10);
		int width = MeasureText(lineNumber, 20);
		DrawText(lineNumber, 15 - width, 10 + i * 20, 20, GRAY);
	}

	for (int i = 0; i < m_Lines.size(); ++i)
	{
		std::string text = m_Lines[i]->ToString();
		DrawText(text.c_str(), 20, 10 + i * 20, 20, DARKGRAY);
	}
}

void Page::GetCursorXY(int& x, int& y)
{
	if (m_LineIndex > -1)
	{
		std::string text = m_Lines[m_LineIndex]->ToString();
		x = MeasureText(text.substr(0, m_Lines[m_LineIndex]->CursorIndex()).c_str(), 20);
		y = m_LineIndex * 20;
	}
	else
	{
		x = 0;
		y = 0;
	}
}
