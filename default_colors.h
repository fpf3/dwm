#ifndef DEFAULT_COLORS_H
#define DEFAULT_COLORS_H

char norm_fg[] = "#d6d9ca";
char norm_bg[] = "#0d1310";
char norm_border[] = "#95978d";

char sel_fg[] = "#d6d9ca";
char sel_bg[] = "#3E8193";
char sel_border[] = "#d6d9ca";

char urg_fg[] = "#d6d9ca";
char urg_bg[] = "#877C84";
char urg_border[] = "#877C84";

char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeUrg] =  { urg_fg,      urg_bg,    urg_border },
};

#endif /* DEFAULT_COLORS_H */
