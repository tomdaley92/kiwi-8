#ifndef GUI_H
#define GUI_H

#include <imgui.h>
#include "imgui_impl_sdl.h"
#include <SDL2/SDL.h>

#define MENU_HEIGHT 38

/* Forward declaration */
class Display;

class Gui {

    private:

        /* Pointers to chip-8 data */
        Display *display;

        int *cycles;
        bool *emulation_paused;
        bool *load_store_quirk;
        bool *shift_quirk;
        bool *vwrap;

        /* Help-window toggles */
        bool show_controls;
        bool show_license;
        bool show_about;
        bool show_usage;

        void MainMenu();
        void HelpWindows();

    public:

        bool soft_reset_flag;
        bool load_rom_flag;
        bool quit_flag;
        bool show_menu_flag;
        bool show_fps_flag;
        

        Gui();
        ~Gui();

        void Initialize(Display *display,
                        int *cycles, 
                        bool *emulation_paused, 
                        bool *load_store_quirk, 
                        bool *shift_quirk, 
                        bool *vwrap);

        void ProcessEvents(SDL_Event *event);
        void NewFrame();
        void Render();

        
};

#endif