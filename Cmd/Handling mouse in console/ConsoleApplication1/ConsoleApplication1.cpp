
#include "stdafx.h"

DWORD getInput(INPUT_RECORD **);


HANDLE wHnd; /* write (output) handle */
HANDLE rHnd; /* read (input handle */

int main()
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	
	DWORD numEventsRead;
	INPUT_RECORD * eventBuffer;

	DWORD dwNewMode;
	GetConsoleMode(rHnd, &dwNewMode);
	dwNewMode = (dwNewMode & ~ENABLE_QUICK_EDIT_MODE) | ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, dwNewMode);

	while (1)
	{
		/* Get the input and number of events successfully obtained */
		numEventsRead = getInput(&eventBuffer);

		/* if more than 0 are read */
		if (numEventsRead)
		{
			/* loop through the amount of records */
			for (int i = 0; i < numEventsRead; i++)
			{
				/* check each event */
				switch (eventBuffer[i].EventType)
				{
					/* if type of event is a KEY_EVENT */
				case KEY_EVENT:
					switch (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode)
					{
						/* if escape key is pressed*/
					case VK_F10:
						printf("f1");
						break;
					}
				case MOUSE_EVENT:
					printf("==%i,",eventBuffer[i].Event.MouseEvent.dwMousePosition.X);
					printf("%i,", eventBuffer[i].Event.MouseEvent.dwMousePosition.Y);
					if (eventBuffer[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						printf("button");
					}
				}
			}
		}
	}

	return 0;
}










/* Read console input buffer and return malloc'd INPUT_RECORD array */
DWORD getInput(INPUT_RECORD **eventBuffer)
{
	/* Variable for holding the number of current events, and a point to it */
	DWORD numEvents = 0;


	/* Variable for holding how many events were read */
	DWORD numEventsRead = 0;


	/* Put the number of console input events into numEvents */
	GetNumberOfConsoleInputEvents(rHnd, &numEvents);


	if (numEvents) /* if there's an event */
	{
		/* Allocate the correct amount of memory to store the events */
		*eventBuffer = new INPUT_RECORD [numEvents];

		/* Place the stored events into the eventBuffer pointer */
		ReadConsoleInput(rHnd, *eventBuffer, numEvents, &numEventsRead);
	}


	/* Return the amount of events successfully read */
	return numEventsRead;
}
