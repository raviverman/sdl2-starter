#include<SDL2/SDL.h>
#include<stdbool.h>
#include<unistd.h>
#include<stdio.h>

int main() {

   SDL_Window* window = NULL;
   SDL_Renderer* renderer = NULL;

   SDL_Init( SDL_INIT_EVERYTHING );
   SDL_CreateWindowAndRenderer( 640, 480, 0, &window, &renderer );

   SDL_RenderClear( renderer );
   printf("Window: %p, Render: %p\n", window, renderer );


   /* Draw a rectangle */
   SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
   SDL_Rect rect;
   rect.w = 100;
   rect.h = 100;
   rect.x = 20;
   rect.y = 20;

   SDL_RenderDrawRect( renderer, &rect );
   SDL_RenderPresent( renderer );

   int is_running = true;
   SDL_Event event;
   while (is_running) {
      while (SDL_PollEvent(&event)) {
          if (event.type == SDL_QUIT) {
              is_running = false;
         }
      }
      SDL_Delay(10);
   }

   // Close and destroy the window
   SDL_DestroyWindow(window);

   // Clean up
   SDL_Quit();
   return 0;
}
