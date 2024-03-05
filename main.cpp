#include "definition.hpp"
int main(int argc, char* argv[]) {
	if (!Init()) return -1;
	if (!LoadMedia()) return -1;
	bool quit = false;
	int f = 0;
	while (!quit) {
		while (SDL_PollEvent(&g_event)) {
			if (g_event.type == SDL_QUIT) {
				quit = true;
			}
		}
		
		SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
		SDL_RenderClear(g_screen);

		SDL_Rect* clip = &frame[f / 20];
		g_image.render((screen_width - clip->w) / 2, (screen_height - clip->h) / 2, clip);

		SDL_RenderPresent(g_screen);

		f++;
		if (f / 20 >= walking_frame) f = 0;
	}
	close();
	return 0;
}