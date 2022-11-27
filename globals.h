#pragma once

/*icons:
A - target (person)
B - target variant 2
C - eye
D - half filled( or half empty :) ) circle
E - circle
F - flag
G - heart
H - home
I - linux
J - magic stick
K - 'play'
L - exit
M - exit variant 2
N - wifi
O - half filled shield
P - log out
Q - loading
R - water drop
S - umbrella
T - caution
U - settings
*/

#define cheat_icon_symbol "O"
#define cheat_name "domain"
#define cheat_domain ".com"

/*floats*/
float accent_colour[4] = { 173 / 255.f, 57 / 255.f, 57 / 255.f, 1.f };

/*ints*/
int old_tab = 0;
static int tab = 0;

/*chars*/
static char RustKey[64];
static char DeadSide[64];
static char ValoKey[64];
static char ApexKey[64];
static char password[64];

/*options*/
float content_animation = 0.0f;
float dpi_scale = 1.5f;

static bool update_on_f5 = true;

static int game = 0;
const char* games_list[4] = { "RUST", "DEADSIDE", "VALORANT", "APEX LEGENDS"};
