#ifndef STATUS
#define STATUS

#include "Vector3f.h"

struct Status {
	/*
	  0 -> rotate scene
	  1 -> walk mode
	  2 -> 
	  3 -> move legoman
	  */
	int mode;
	// extra information needed for modes
	int submode;
	/*
	  0 -> Ortho
	  1 -> Perspective
	 */
	int view_mode;

	bool view_walls;
	
	int window_width;
	int window_height;
	float aspect_ratio;
	Vector3f scene_rotation;
	Vector3f scene_translation;
	Vector3f scene_scale;
	float zoom;

	Status(int mode, int submode, int window_width, int window_height, int window_margin_x, int window_margin_y) {
		this->window_width = window_width;
		this->window_height = window_height;
		this->mode = mode;
		this->submode = submode;

		scene_rotation = Vector3f();
		scene_translation = Vector3f();
		scene_scale = Vector3f(1, 1, 1);

		view_mode = 0;
		aspect_ratio = (float) window_width/(float) window_height;

		zoom = 1;
		view_walls = true;
	}
};

#endif
