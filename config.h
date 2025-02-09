/* See LICENSE file for copyright and license details. */

#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>
#include "types.h"
#include "funcprotos.h"
#include "util.h"
#include "default_colors.h"

#define SESSION_FILE "/tmp/dwm-session"

/* appearance configurables */
static unsigned int borderpx  = 1;        /* border pixel of windows */
static unsigned int snap      = 6;        /* snap pixel */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */

/* appearance constants */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const char *fonts[]          = { "monospace:size=", 
										"NotoColorEmoji:antialias=true:autohint=true:pixelsize=", 
										"JoyPixels:pixelsize="};
static const char dmenufont[]       = "monospace:size=10";

//const char *unicode_cmd[] = {"unicode_select", NULL};
const char *unicode_cmd[] = {"rofimoji", NULL};

const float refresh_interval = 1000. / 144.;

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "120x34", "-e", "ranger", NULL };
const char *spcmd3[] = {"keepassxc", NULL };

static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
	{"keepassxc",   spcmd3},
};

/* tagging */
#define MAXTAGSLEN 32
static char *tags[] = { "🌐", "🖥️", "🖥️", "📧", "💬", "📄", "📄", "📊", "💲" };
static char *tagsalt[] = { "web", "dev1", "dev2", "email", "chat", "doc1", "doc2", "status", "term" };
static const int momentaryalttags = 0;

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
		/* class        instance        title           tags mask   isfloating  isterminal,	noswallow,	monitor, resizehints*/
	{ NULL,		    "spterm",		NULL,		    SPTAG(0),	1,	        1,			0,	 		-1 ,     1 },
	{ NULL,		    "spfm",			NULL,		    SPTAG(1),	1,	        0,			0,	 		-1 ,     1 },
	{ "KeePassXC",	NULL,			NULL,		    SPTAG(2),	1,	        0,			0,	 		-1 ,     1 },
	{ "Gimp",       NULL,           NULL,           0,          1,          0,			1,	 		-1 ,     1 },
	{ "Firefox",    NULL,           NULL,           1 << 8,     0,          0,			0,	 		-1 ,     1 },
	{ "St",			NULL,			NULL,			0,			0,			1,			0,			-1 ,     0 },
	{ NULL,         NULL,           "Event Tester", 0,          0,          0,			1,	 		-1 ,     1 }, /* xev */
	{ "thunderbird","Alert",        NULL,           0,          1,          0,			0,	 		-1 ,     1 }, /* notifications */
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[[]]",     bigtile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
 	{ "[@]",      spiral },
 	{ "[\\]",     dwindle },
	{ "[]=",      tile },    /* first entry is default */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,             {.ui = TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,       {.ui = TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,              {.ui = TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,        {.ui = TAG} }, \
	{ MODKEY|Mod1Mask|ShiftMask,    KEY,      globalview,       {.ui = TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *termcmd[]  = { "st", NULL };

//#define MONITOR_NAME "LVDS1"
static const char *invertcmd[] = { "rotate_desktop.sh", "inverted" }; // flip monitor upside down
static const char *normalcmd[] = { "rotate_desktop.sh", "normal" }; // put it rightside up


static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Down,   spawn,          {.v = invertcmd } },
	{ MODKEY|ShiftMask,             XK_Up,     spawn,          {.v = normalcmd } },
    { MODKEY|ShiftMask,             XK_u,      spawn,          {.v = unicode_cmd} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,            XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,            XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ControlMask,          XK_Up,      bumpfontsize,  {.i = +1} },
    { MODKEY|ControlMask,          XK_Down,    bumpfontsize,  {.i = -1} },
	{ MODKEY,                      XK_Return, zoom,           {0} },
	{ Mod1Mask,                    XK_Tab,    rotatestack,    {0} },
	{ MODKEY,                    	XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,            XK_q,      killclient,     {0} },
	{MODKEY,					    XK_y,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                      XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                      XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                      XK_r,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,          XK_r,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                      XK_t,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ShiftMask,            XK_f,      fullscreen,     {0} },
	{ MODKEY,                      XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,            XK_space,  togglefloating, {0} },
    { MODKEY,                      XK_v,      toggleswallow,  {0} },
	{ MODKEY,                      XK_0,      view,           {.ui = ~0 }},
	{ MODKEY|ShiftMask,            XK_0,      tag,            {.ui = ~0 }},
	{ MODKEY,                      XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                      XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,            XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,            XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,            			XK_u,  	   togglescratch,  {.ui = 0 } },
	{ MODKEY|ShiftMask,            XK_c,	   togglescratch,  {.ui = 1 } },
	{ MODKEY,            			XK_x,	   togglescratch,  {.ui = 2 } },
	{ MODKEY,						XK_n,	   togglealttag,   {0} },
	// Set tag control keybinds for...
	//      KEY 						TAG
	TAGKEYS(XK_0, 						VIEWTAGMASK) // 0 key is bound to "all" tags
	TAGKEYS(XK_1,                       1 << 0 )
	TAGKEYS(XK_2,                       1 << 1 )
	TAGKEYS(XK_3,                       1 << 2 )
	TAGKEYS(XK_4,                       1 << 3 )
	TAGKEYS(XK_5,                       1 << 4 )
	TAGKEYS(XK_6,                       1 << 5 )
	TAGKEYS(XK_7,                       1 << 6 )
	TAGKEYS(XK_8,                       1 << 7 )
	TAGKEYS(XK_9,                       1 << 8 )
	{ MODKEY|ShiftMask,            XK_e,      quitprompt,	   {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button4,        scrolltag,      {0} },
	{ ClkTagBar,            0,              Button5,        scrolltag,      {0} },
};

#endif /* CONFIG_H */
