#pragma once 
#include <string>
#include "ListNode.h"

class TextLine
{
public:
	TextLine();
	~TextLine();

	void InsertCharacterAtCursor(char c);
	void DeleteCharacterAfterCursor();
	void DeleteCharacterAtCursor();

	void MoveCursorLeft();
	void MoveCursorRight();
	
	std::string ToString() const;
	const int CursorIndex()const;
	inline const int Size() const { return m_Size; }
private:
	ListNode* m_Head = nullptr;
	ListNode* m_Tail = nullptr;
	ListNode* m_Cursor = nullptr;
	int m_Size = 0;
};