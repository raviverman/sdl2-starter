#include<SDL2/SDL.h>
#include<stdbool.h>
#include<unistd.h>
#include<stdio.h>

bool isMouseOver( SDL_Rect rect, int mouse_x, int mouse_y ) {
   if ( mouse_x >= rect.x && mouse_x <= rect.x + rect.w &&
        mouse_y >= rect.y && mouse_y <= rect.y + rect.h ) {
      return true;
   }
   return false;
}

int main() {

   SDL_Window* window = NULL;
   SDL_Renderer* renderer = NULL;

   SDL_Init( SDL_INIT_EVERYTHING );
   SDL_CreateWindowAndRenderer( 640, 480, 0, &window, &renderer );

   SDL_RenderClear( renderer );
   printf("Window: %p, Render: %p\n", window, renderer );


   SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
   SDL_Rect rect;
   rect.w = 100;
   rect.h = 100;
   rect.x = 20;
   rect.y = 20;

   SDL_Rect rect2;
   rect2.w = 100;
   rect2.h = 100;
   rect2.x = 140;
   rect2.y = 20;

   SDL_RenderDrawRect( renderer, &rect );
   SDL_RenderDrawRect( renderer, &rect2 );

   SDL_RenderPresent( renderer );

   int count = 0;
   int is_running = true;
   int mouse_x, mouse_y;
   SDL_Event event;
   while (is_running) {
      while (SDL_PollEvent(&event)) {
          if (event.type == SDL_QUIT) {
              is_running = false;
          } else if ( event.type == SDL_MOUSEMOTION ) {
            SDL_GetMouseState(&mouse_x, &mouse_y);
            printf("Mouse Motion (%d, %d) CPU Cnt: %d\n", mouse_x, mouse_y,
                   SDL_GetCPUCount());
         }
      }

      /*clear canvas*/
      SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
      SDL_RenderClear( renderer );
      /* render content */
      if (isMouseOver(rect, mouse_x, mouse_y)) {
         SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
      } else {
         SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
      }
      SDL_RenderDrawRect( renderer, &rect );
      if (isMouseOver(rect2, mouse_x, mouse_y)) {
         SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
      } else {
         SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
      }
      SDL_RenderDrawRect( renderer, &rect2 );
      /* show content */
      SDL_RenderPresent( renderer );

      SDL_Delay(10);
   }

   // Close and destroy the window
   SDL_DestroyWindow(window);

   // Clean up
   SDL_Quit();
   return 0;
}
