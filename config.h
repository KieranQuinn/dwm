#define NUMCOLORS 		13
#define MODKEY 			Mod1Mask
#define MONKEY 			Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static const unsigned int systrayspacing	= 2;	    // systray spacing
static const Bool showsystray				= True;	    // false means no systray
static const unsigned int gappx				= 8;		// gaps between windows
static const unsigned int borderpx			= 1;        // border pixel of windows
static const unsigned int snap				= 32;       // snap pixel
static const Bool showbar					= True;     // false means no bar
static const Bool topbar					= True;     // false means bottom bar
static const float mfact					= 0.55; 	// factor of master area size [0.05..0.95]
static const int nmaster					= 1;   		// number of clients in master area
static const Bool resizehints				= False; 	// true means respect size hints in tiled resizals

static const char font[] = "-*-stlarch-*-*-*-*-14-*-*-*-*-*-*-*"",""-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";

static const char colors[NUMCOLORS][ColLast][13] = {
    /* border    fg       	bg */
	{ "#EEEEEE", "#666666", "#222222" },				// 01 - regular
	{ "#222222", "#FFFFFF", "#222222" },				// 02 - selected
	{ "#222222", "#FF0000", "#222222" },				// 03 - urgent
	{ "#222222", "#333333", "#222222" }, 				// 04 - occupied
	{ "#222222", "#A82222", "#222222" }, 				// 05 - red
	{ "#222222", "#1F7B94", "#222222" }, 				// 06 - blue
	{ "#222222", "#349147", "#222222" }, 				// 07 - green
	{ "#222222", "#333333", "#222222" }, 				// 08 - dark grey
	{ "#222222", "#DCDCDC", "#222222" }, 				// 09 - light grey
	{ "#222222", "#08736C", "#222222" }, 				// 0A - teal
	{ "#222222", "#B86A6A", "#222222" }, 				// 0B - pink
	{ "#222222", "#FFFFFF", "#222222" }, 				// 0C - white
	{ "#222222", "#000000", "#222222" }, 				// 0D - black
};

static const Layout layouts[] = {
	/*	symbol			gaps		arrange */
	{ "    \uE002",		True,	    tile	},
	{ "    \uE003",   	True,	    bstack	},
	{ "    \uE000",  	False,	    monocle	},
	{ "    \uE0B1",		False,	    NULL	},
};

static const Tag tags[] = {
	/* name			layout			mfact		nmaster */
	{ "     web",	&layouts[0],  	-1,		    -1 },
	{ "     chat",	&layouts[0],   	-1,		    -1 },
	{ "     term",	&layouts[3],  	-1,		    -1 },
	{ "     code",	&layouts[0],  	-1,			-1 },
	{ "     media",	&layouts[0],   	-1,		    -1 },
	{ "     misc",	&layouts[0],  	-1,		    -1 },
};

static const Rule rules[] = {
    /* class         	instance   	title 	    tags mask    	isfloating		iscentred   	monitor */
	{ "Chromium",		NULL,       NULL,       1 << 0,    		False,   		False,			-1 },
	{ "Skype",			NULL,       NULL,       1 << 1,       	False,       	False,			-1 },
	{ "URxvt",			NULL,       NULL,       1 << 2,       	True,       	True,			-1 },
	{ "Geany",			NULL,       NULL,       1 << 3,       	False,       	False,			-1 },
	{ "Vlc",			NULL,       NULL,       1 << 4,       	False,       	False,			-1 },
	{ "Pcmanfm",		NULL,       NULL,       1 << 5,       	False,       	False,			-1 },
};

static const char *menu[] = { "dmenu_run", "-i", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *webb[] = { "chromium", NULL, "Chromium" };
static const char *chat[] = { "skype", NULL, "Skype" };
static const char *term[] = { "urxvtc", NULL, "URxvt" };
static const char *edit[] = { "geany", NULL, "Geany" };
static const char *mdia[] = { "vlc", NULL, "Vlc" };
static const char *file[] = { "pcmanfm", NULL, "Pcmanfm" };
static const char *prts[] = { "scrot", NULL };

static Key keys[] = {
	{ MONKEY,       	XK_p, 		spawn,          {.v = menu } },
	{ MONKEY,       	XK_w,    	runorraise,   	{.v = webb } },
	{ MONKEY,       	XK_s,     	runorraise,    	{.v = chat } },
	{ MONKEY,       	XK_Return,	runorraise,    	{.v = term } },
	{ MONKEY,       	XK_e,    	runorraise,    	{.v = edit } },
	{ MONKEY,       	XK_m,     	runorraise,    	{.v = mdia } },
	{ MONKEY,       	XK_f,     	runorraise,    	{.v = file } },
	{ MONKEY,       	XK_Print,	spawn,    		{.v = prts } },
	{ MODKEY|ShiftMask,	XK_q,     	quit,           {0} },
	{ MODKEY|ShiftMask,	XK_b,    	togglebar,      {0} },
	{ MODKEY|ShiftMask,	XK_c,   	killclient,     {0} },
	{ MODKEY,       	XK_Return,	zoom,           {0} },
	{ MODKEY,          	XK_Tab,   	view,           {0} },
	{ MODKEY|ShiftMask,	XK_f,   	togglefloating, {0} },
	{ MODKEY,      		XK_space,	setlayout,      {0} },
	{ MODKEY,			XK_t,    	setlayout,      {.v = &layouts[0] } },
	{ MODKEY,          	XK_b,    	setlayout,      {.v = &layouts[1] } },
	{ MODKEY,         	XK_m,  		setlayout,      {.v = &layouts[2] } },
	{ MODKEY,          	XK_f,   	setlayout,      {.v = &layouts[3] } },
	{ MODKEY,         	XK_Right, 	focusstack,     {.i = +1 } },
	{ MODKEY,         	XK_Left,  	focusstack,     {.i = -1 } },
	{ MODKEY,          	XK_h,      	setmfact,       {.f = -0.05 } },
	{ MODKEY,          	XK_l,      	setmfact,       {.f = +0.05 } },
	{ MODKEY,          	XK_equal,  	incnmaster,     {.i = +1 } },
	{ MODKEY,      		XK_minus,	incnmaster,     {.i = -1 } },
	{ MODKEY,        	XK_Down, 	focusstack, 	{.i = +1 } },
	{ MODKEY,         	XK_Up, 		focusstack,   	{.i = -1 } },
	{ MODKEY,        	XK_0,      	view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,	XK_0,      	tag,            {.ui = ~0 } },
	{ MODKEY,         	XK_comma, 	focusmon,       {.i = -1 } },
	{ MODKEY,        	XK_period,	focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,	XK_comma,  	tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,	XK_period, 	tagmon,         {.i = +1 } },
	TAGKEYS(        	XK_1,   	0)
	TAGKEYS(        	XK_2,   	1)
	TAGKEYS(        	XK_3,    	2)
	TAGKEYS(        	XK_4,   	3)
	TAGKEYS(          	XK_5,   	4)
	TAGKEYS(      		XK_6,     	5)
};

static Button buttons[] = {
	{ ClkLtSymbol, 		0,       	Button1,        setlayout,      {0} },
	{ ClkClientWin,		MODKEY,  	Button1,        movemouse,      {0} },
	{ ClkClientWin,		MODKEY,   	Button2,        togglefloating, {0} },
	{ ClkClientWin,		MODKEY,    	Button3,        resizemouse,    {0} },
	{ ClkTagBar,  		0,       	Button1,        view,           {0} },
	{ ClkTagBar,  		0,         	Button3,        toggleview,     {0} },
	{ ClkTagBar, 		MODKEY,   	Button1,        tag,            {0} },
	{ ClkTagBar,  		MODKEY,   	Button3,        toggletag,      {0} },
};
