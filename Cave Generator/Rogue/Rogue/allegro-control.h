#ifndef _H_ALLEGRO_CONTROL
#define _H_ALLEGRO_CONTROL


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro5.h>


class AllegroControl
{
public:
	AllegroControl();
	~AllegroControl();

	bool Init();
	void Loop();

	void CatchEvent();
	void ExecuteEvent();
	void Draw();

	inline bool IsRunning() const;

private:
	void Close();
	void ShowError(const char * text) const;

	bool					running_;
	ALLEGRO_DISPLAY	*		display_;
	ALLEGRO_EVENT_QUEUE *	event_queue_;
	ALLEGRO_TIMER *			logic_timer_;
	ALLEGRO_TIMER *			display_timer_;
	ALLEGRO_FONT *			basic_font_;
	ALLEGRO_EVENT			current_event_;
	
	// TEMPORATY
	int fps_counter_;

};


inline bool AllegroControl::IsRunning() const
{
	return running_;
}

#endif // !_H_ALLEGRO_CONTROL
