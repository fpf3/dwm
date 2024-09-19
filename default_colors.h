static const char norm_fg[] = "#d6d9ca";
static const char norm_bg[] = "#0d1310";
static const char norm_border[] = "#95978d";

static const char sel_fg[] = "#d6d9ca";
static const char sel_bg[] = "#3E8193";
static const char sel_border[] = "#d6d9ca";

static const char urg_fg[] = "#d6d9ca";
static const char urg_bg[] = "#877C84";
static const char urg_border[] = "#877C84";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeUrg] =  { urg_fg,      urg_bg,    urg_border },
};
