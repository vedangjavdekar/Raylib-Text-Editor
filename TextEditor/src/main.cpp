#include "raylib.h"
#include "Page.h"

int main()
{
	const int screenWidth = 1280;
	const int screenHeight = 720;
	const int blinkAfterFrames = 30;
	const int blinkTime = 30;
	bool isBlinking = false;
	int frameCounter = 0;


	InitWindow(screenWidth, screenHeight, "Text Editor");
	SetTargetFPS(60);


	Page page;
	page.HandleNewLine();

	while (!WindowShouldClose())
	{
		// Update
		//----------------------------------------------------------------------------------
		int key = GetCharPressed();

		// Check if more characters have been pressed on the same frame
		while (key > 0)
		{
			// NOTE: Only allow keys in range [32..125]
			if ((key >= 32) && (key <= 125))
			{
				page.AddCharToCurrentLine((char)key);
				isBlinking = false;
				frameCounter = 0;
			}

			key = GetCharPressed();  // Check next character in the queue
		}

		if (IsKeyPressed(KEY_RIGHT))
		{
			page.MoveCursorRight();
			isBlinking = false;
			frameCounter = 0;
		}

		if (IsKeyPressed(KEY_LEFT))
		{
			page.MoveCursorLeft();
			isBlinking = false;
			frameCounter = 0;
		}

		if (IsKeyPressed(KEY_UP))
		{
			page.MoveUpLine();
			isBlinking = false;
			frameCounter = 0;
		}

		if (IsKeyPressed(KEY_DOWN))
		{
			page.MoveDownLine();
			isBlinking = false;
			frameCounter = 0;
		}

		if (IsKeyPressed(KEY_DELETE))
		{
			page.DeleteCharacterAfterCursor();
			isBlinking = false;
			frameCounter = 0;
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			page.DeleteCharacterAtCursor();
			isBlinking = false;
			frameCounter = 0;
		}

		if (IsKeyPressed(KEY_ENTER))
		{
			page.HandleNewLine();
			isBlinking = false;
			frameCounter = 0;
		}

		frameCounter++;
		if (!isBlinking && frameCounter > blinkAfterFrames)
		{
			isBlinking = true;
			frameCounter = 0;
		}

		if (isBlinking)
		{
			frameCounter = frameCounter % (2 * blinkTime);
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		int cursorX = 0, cursorY = 0;
		page.GetCursorXY(cursorX, cursorY);
		if (isBlinking)
		{
			if (frameCounter < blinkTime)
			{
				DrawRectangle(20 + cursorX, 10 + cursorY, 12, 20, LIGHTGRAY);
			}
		}
		else
		{
			DrawRectangle(20 + cursorX, 10 + cursorY, 12, 20, LIGHTGRAY);
		}
		page.Draw();
		EndDrawing();
		//----------------------------------------------------------------------------------

	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------



	return 0;
}