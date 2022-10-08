#include "TextLine.h"
#include <sstream>

TextLine::TextLine()
{
	m_Head = new ListNode();
	m_Tail = new ListNode();

	m_Head->next = m_Tail;
	m_Tail->prev = m_Head;
	m_Cursor = m_Tail;
	m_Size = 0;
}

TextLine::~TextLine()
{
	if (m_Head->next != m_Tail)
	{
		ListNode* node = m_Head->next;
		while (node != m_Tail)
		{
			ListNode* toRemove = node;
			node = node->next;
			delete toRemove;
		}
	}

	delete m_Head;
	delete m_Tail;
}

void TextLine::InsertCharacterAtCursor(char c)
{
	ListNode* prev = m_Cursor->prev;
	ListNode* node = new ListNode();
	node->c = c;
	node->prev = prev;
	prev->next = node;
	node->next = m_Cursor;
	m_Cursor->prev = node;
	m_Size++;
}

void TextLine::DeleteCharacterAfterCursor()
{
	if (m_Cursor != m_Tail && m_Cursor->next != m_Tail)
	{
		ListNode* nextNext = m_Cursor->next->next;
		ListNode* next = m_Cursor->next;
		m_Cursor->next = nextNext;
		nextNext->prev = m_Cursor;
		delete next;
		m_Size--;
	}
	else if (m_Size == 1)
	{
		ListNode* node = m_Head->next;
		m_Head->next = m_Tail;
		m_Tail->prev = m_Head;
		m_Cursor = m_Tail;
		m_Size = 0;
		delete node;
	}
}

void TextLine::DeleteCharacterAtCursor()
{
	if (m_Cursor->prev != m_Head)
	{
		ListNode* prev = m_Cursor->prev;
		ListNode* prevPrev = m_Cursor->prev->prev;
		m_Cursor->prev = prevPrev;
		prevPrev->next = m_Cursor;
		delete prev;
		m_Size--;
	}
	else if (m_Size == 1)
	{
		ListNode* node = m_Head->next;
		m_Head->next = m_Tail;
		m_Tail->prev = m_Head;
		m_Cursor = m_Tail;
		m_Size = 0;
		delete node;
	}
}

void TextLine::MoveCursorLeft()
{
	if (m_Cursor->prev != m_Head)
	{
		m_Cursor = m_Cursor->prev;
	}
}

void TextLine::MoveCursorRight()
{
	if (m_Cursor != m_Tail)
	{
		m_Cursor = m_Cursor->next;
	}
}

std::string TextLine::ToString() const
{
	if (m_Head->next != m_Tail)
	{
		std::stringstream ss;
		ListNode* node = m_Head->next;
		while (node != m_Tail)
		{
			ss << node->c;
			node = node->next;
		}
		ss << '\0';
		return ss.str();
	}
	return "";
}

const int TextLine::CursorIndex() const
{
	int index = 0;
	ListNode* node = m_Head;
	while (node->next != m_Cursor)
	{
		node = node->next;
		index++;

	}
	return index;
}
